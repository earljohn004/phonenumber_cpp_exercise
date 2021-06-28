/**
 * worker source- version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains multi-threading implementation for file reading and 
 * data processing
 *
 **/

#include "worker.h"
#include "prog_settings.h"
#include "phonedata_model.h"
#include "common_defines.h"
#include "common_debug.h"
#include "utility.h"

#include <thread>
#include <chrono>
#include <fstream>
#include <string>

worker::worker(
		std::shared_ptr<phonedata_model> phonedata, 
		std::shared_ptr<prog_settings> settings,
		std::string filename )
{
	phonedata_ = std::make_shared<phonedata_model>(*phonedata);
	settings_ = std::make_shared<prog_settings>(*settings);
	filename_ = std::move(filename);
}


void worker::input_producer_proc(){

	std::string filename( filename_ );
	std::ifstream file(filename);
	std::string linestr;
	std::unique_lock<decltype(mutex_)> lock(mutex_);

	while( std::getline(file, linestr)){
		
		MESSAGE_LOG("reading input from file....");
		input_queue_.push( linestr );

		if( static_cast<int>(input_queue_.size()) >= max_size_ ){
			is_active_ = true;
			lock.unlock();
			condition_var_.notify_one();
			lock.lock();

			condition_var_.wait(lock, [&](){
				return is_active_ == false;
			});
		}
	}

	//When the end of file is reached and queue size 
	//does not reach the max specified
	//release lock to call next thread
	{
		is_active_ = true;
		lock.unlock();
		condition_var_.notify_one();
		lock.lock();

		//update is_end_of_file_ flag
		//to stop process_consumer_proc
		is_end_of_file_ = true;

		condition_var_.wait(lock, [&](){
			return is_active_ == false;
		});
	}


}

void worker::process_consumer_proc(){

	//Change condition, add mark in upper 
	//thread to notify finish
	while( !is_end_of_file_){
		std::unique_lock<decltype(mutex_)> lock(mutex_);

		condition_var_.wait( lock, [&](){
				return is_active_;
		});

		while( !input_queue_.empty() ){
			auto request = input_queue_.front();

			MESSAGE_LOG("extracting information...");
			extract_information( request );

			input_queue_.pop();
		}

		is_active_= false;

		lock.unlock();
		condition_var_.notify_one();
	}

	auto get_vector = settings_->get_output_settings();

	// Write to file
	std::ofstream outfile;
	outfile.open("output.txt");

	
	// headerss will print the header to stringstream
	std::stringstream headerss;
	for( auto header: get_vector ){
		headerss << std::setw(10) << header <<  ", ";
	}
	headerss << std::endl;

	// get data to be outputted from phonedata_
	auto str = phonedata_->display_output( get_vector );
	std::stringstream ss(str);

	outfile << headerss.rdbuf() << ss.rdbuf();
	std::cout << ss.str();

	MESSAGE_LOG("End of program");
}

void worker::start_thread(){
	std::thread input_thread( &worker::input_producer_proc, this );
	std::thread process_thread( &worker::process_consumer_proc, this );

	input_thread.join();
	process_thread.join();
}

void worker::extract_information( const std::string input ){
	std::unique_ptr<utility> util { std::make_unique<utility>() };

	std::stringstream ss(input);
	auto get_vector = settings_->get_input_settings();
	retcode ret = retcode::ret_ng;

	date_format time_stamp {};
	date_format date_sent {};
	date_format date_receive {};
	std::string sender_phone {};
	std::string receive_phone { "0" };

	for( auto str : get_vector ) {

		std::string tmp{};
		std::getline(ss, tmp, settings_->get_delimeter() );
		
		if( str == "TimeStamp" ){
			ret = util->extract_date_from_epoch( tmp, time_stamp );

			if(ret == retcode::ret_ng){
				ERROR_LOG("Time stamp error");
			}else {/* Do nothing */}

		}
		else if( str == "DateSentTimeStamp"){

			ret = util->extract_date_from_epoch( tmp, date_sent );

			if(ret == retcode::ret_ng){
				ERROR_LOG("Date sent error");
			}else {/* Do nothing */}
		}
		else if( str == "DateReceivedTimeStamp" ){

			ret = util->extract_date_from_epoch( tmp, date_receive );

			if(ret == retcode::ret_ng){
				ERROR_LOG("Date sent error");
			}else {/* Do nothing */}
		}
		else if( str == "SenderPhoneNumber"){

			ret = util->extract_phonenumber( tmp, sender_phone );

			if(ret == retcode::ret_ng){
				ERROR_LOG("SenderPhone error");
			}else {/* Do nothing */}
		}
		else if( str == "RecepientPhoneNumber"){

			ret = util->extract_phonenumber( tmp, receive_phone );

			if(ret == retcode::ret_ok){
				phonedata_->increment_phonenumber_receive( receive_phone );
			}else {/* Do nothing */}

		}else{
			ERROR_LOG("does not exist");
		}
	}

	phonedata_->add_date_information( sender_phone, date_sent.to_string(), receive_phone );
}
