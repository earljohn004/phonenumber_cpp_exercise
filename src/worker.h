/**
 * worker header - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains multi-threading implementation for file reading and 
 * data processing
 *
 **/

#ifndef _H_WORKER_H_
#define _H_WORKER_H_

#include "phonedata_model.h"
#include "prog_settings.h"

#include <mutex>
#include <thread>
#include <queue>
#include <atomic>
#include <condition_variable>

class worker{

	public: 
		worker() = default;
		worker( std::shared_ptr<phonedata_model> phonedata, 
				std::shared_ptr<prog_settings> settings,
				std::string filename );

		~worker() = default;

		void input_producer_proc();
		void process_consumer_proc();
		void start_thread();
		
	private:
		void extract_information(const std::string input);

	private: 
		std::mutex mutex_;
		std::queue<std::string> input_queue_;
		std::condition_variable condition_var_;

		bool is_active_ ;
		int max_size_ = 10;
		bool is_end_of_file_ = false;

		std::shared_ptr<phonedata_model> phonedata_;
		std::shared_ptr<prog_settings> settings_;

		std::string filename_;

};

#endif// _H_WORKER_H_
