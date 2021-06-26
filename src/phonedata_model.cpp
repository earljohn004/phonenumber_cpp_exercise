#include "phonedata_model.h"

int phonedata_model::get_total_receive( const std::string  phonenumber ) {
	return total_receive_[phonenumber];
}

int phonedata_model::get_total_send( const std::string  phonenumber ) {
	return total_send_[phonenumber];
}

void phonedata_model::increment_phonenumber_receive( const std::string phonenumber ){
	++total_receive_[phonenumber];
}

void phonedata_model::increment_phonenumber_send( const std::string phonenumber ){
	++total_send_[phonenumber];
}

void phonedata_model::add_date_information( const std::string phonenumber, const std::string date){

	if( !date_information_.empty() ){
		auto get_stack = date_information_[phonenumber];

		if( get_stack.top() == date ){
			++total_send_of_date_[phonenumber];
		}else {
			total_send_of_date_[phonenumber] = 1;

			std::stack<std::string> temp;
			temp.push(date);
			date_information_[phonenumber] = std::move(temp);
		}

	}else{

		//if top of stack is same with date, increment the count of date
		total_send_of_date_[phonenumber] = 1;

		std::stack<std::string> temp;
		temp.push(date);
		date_information_[phonenumber] = std::move(temp);
	}

}

std::tuple<std::string, std::string, int> phonedata_model::get_phone_max_date( const std::string phonenumber ){

	auto get_stack = date_information_[phonenumber];
	auto total = total_send_of_date_[phonenumber];

	return std::make_tuple( phonenumber, get_stack.top(), total ); 
}

void phonedata_model::add_date_information_q( const std::string phonenumber, const std::string date, const std::string recepient){

#if 0
	if( !date_information_q_.empty() ){
		auto get_queue = date_information_q_[phonenumber];

		if( get_queue.front() == date ){
			++total_send_of_date_[phonenumber];
		}else {
			get_queue.push_front(date);
		}

	}else{

		//if top of deque is same with date, increment the count of date
		total_send_of_date_[phonenumber] = 1;

		std::deque<std::string> temp;
		temp.push_back(date);
		date_information_q_[phonenumber] = std::move(temp);
	}
#endif

	if( !date_information_q_.empty() ){

	}else{
		date_information info {};
		++info.date_count[date];
		info.phone_number_list.push_back(recepient);

		date_information_q_[phonenumber].push_front(info);
	}

}


