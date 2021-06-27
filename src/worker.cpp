#include "worker.h"
#include "common_defines.h"
#include "common_debug.h"

#include <thread>
#include <chrono>
#include <fstream>

void worker::input_producer_proc(){

	std::string filename("input.csv");
	std::ifstream file(filename);
	std::string linestr;
	std::unique_lock<decltype(mutex_)> lock(mutex_);

	while( std::getline(file, linestr)){
		
		MESSAGE_LOG("reading input from file....");
		input_queue_.push( linestr );

		if( input_queue_.size() >= max_size_ ){
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
			VAR_LOG(request);
			input_queue_.pop();
			//TODO: add implementation for processing of data
		}

		is_active_= false;

		lock.unlock();
		condition_var_.notify_one();
	}
}

void worker::start_thread(){
	std::thread input_thread( &worker::input_producer_proc, this );
	std::thread process_thread( &worker::process_consumer_proc, this );

	input_thread.join();
	process_thread.join();
}

void worker::extract_information(const std::string input){
}

