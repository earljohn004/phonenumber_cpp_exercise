#ifndef _H_WORKER_H_
#define _H_WORKER_H_

#include <mutex>
#include <thread>
#include <queue>
#include <atomic>
#include <condition_variable>

class worker{

	public: 
		worker() = default;
		~worker() = default;

		void input_producer_proc();
		void process_consumer_proc();
		void start_thread();
		
	private:
		void extract_information();

	private: 
		std::mutex mutex_;
		std::queue<std::string> input_queue_;
		std::condition_variable condition_var_;

		bool is_active_ ;
		int max_size_ = 10;
		bool is_end_of_file_ = false;

};

#endif// _H_WORKER_H_
