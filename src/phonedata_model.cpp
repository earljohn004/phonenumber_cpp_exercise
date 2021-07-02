/**
 * phonedata_model source - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains the data information of the phone model 
 *
 **/

#include "phonedata_model.h"
#include "common_debug.h"

int phonedata_model::get_total_receive( const std::string  phonenumber ) {
	return total_receive_[phonenumber];
}

int phonedata_model::get_total_send( const std::string  phonenumber ) {
	return total_send_[phonenumber];
}

void phonedata_model::increment_phonenumber_receive( const std::string phonenumber ){
	increment_receive(phonenumber);
}

void phonedata_model::increment_phonenumber_send( const std::string phonenumber ){
	increment_send(phonenumber);
}

void phonedata_model::increment_receive(const std::string phonenumber){
	++total_receive_[phonenumber];
}

void phonedata_model::increment_send(const std::string phonenumber){
	++total_send_[phonenumber];
}

std::string phonedata_model::display_output(const std::vector<std::string> setting){

	std::stringstream ss;

	for( auto it = total_send_.begin();  it != total_send_.end(); it++){
		auto key = it->first;

		auto [ date_highest_send, count, highestnumber] = get_phone_max_date( key );

		for( auto str : setting ){
			if( str == "PhoneNumber" ){
				ss <<  std::setw(10) << key;
			}else if( str == "TotalSent"){
				ss << std::setw(10) << total_send_[key];
			}else if( str == "TotalReceived"){
				ss << std::setw(10) << total_receive_ [key];
			}else if( str == "DayHighestSent" ){
				ss <<  std::setw(18) <<date_highest_send;
			}else if( str == "NumberHighestSent"){
				ss <<  std::setw(10) <<highestnumber;
			}else{ /*Do nothing*/}

			ss << ", ";
		}

		ss << std::endl;
	}
	return ss.str();
}

/** @Description This function will return 3 information, 
 * @return std::string date : date with the most number of occurence
 * @return int		   count: the number of dates registered
 * @return std::string recipient : the recipient phone number with the highest number of occurence
 */
std::tuple<std::string, int, std::string> phonedata_model::get_phone_max_date( const std::string phonenumber ){
	auto get_queue = &date_information_q_[phonenumber];

	auto info_front = get_queue->front();
	auto info_back = get_queue->back();

	auto map_element_front_date = info_front.date_count.begin()->first;
	auto map_element_back_date = info_back.date_count.begin()->first;

	auto map_element_front_count = info_front.date_count.begin()->second;
	auto map_element_back_count = info_back.date_count.begin()->second;


	if( map_element_front_count > map_element_back_count ){
		auto get_vector = info_front.phone_number_list;
		return std::make_tuple( map_element_front_date, map_element_front_count, list_largest_element( get_vector ) ); 

	}else{
		auto get_vector = info_back.phone_number_list;
		return std::make_tuple( map_element_back_date, map_element_back_count, list_largest_element( get_vector ) ); 
	}

}

void phonedata_model::get_largest_element( const std::vector<std::string> list, std::string &output ){
	output = list_largest_element( list );
}

std::string phonedata_model::list_largest_element( const std::vector<std::string> list ){

	std::vector<std::string> copyvector;
	std::copy( list.begin(), list.end(), std::back_inserter(copyvector) );
	int occurences_of_element = 0;
	std::string largest_element {};

	//Sort copy vector
	std::sort( copyvector.begin(), copyvector.end());

	//Find the unique elements inside the vector
	auto it = std::unique(copyvector.begin(), copyvector.end());
	copyvector.resize( std::distance( copyvector.begin(), it ));

	//Compare unique elements and check occurence in original vector
	std::for_each(copyvector.begin(), copyvector.end(), [&occurences_of_element, &largest_element, &list](auto item){
		auto count = std::count( list.begin(), list.end(), item );
		
		//Update occurence count and largest element when count is greater than listed element
		if( count > occurences_of_element ){
			occurences_of_element = count;
			largest_element = item;
		}else { /* Do nothing */ }
	});

	return largest_element;
}	

void phonedata_model::add_date_information( const std::string phonenumber, const std::string date, const std::string recepient){

	//Increment send phonenumber count
	increment_send(phonenumber);

	if( !date_information_q_.empty() && 
		(date_information_q_.find(phonenumber)!=date_information_q_.end()))
	{
		auto get_queue = &date_information_q_[phonenumber];
		auto get_info = &get_queue->front();

		//Count if date exist in current map
		if( get_info->date_count.count(date)  > 0 ){
			++get_info->date_count[ date ];
			get_info->phone_number_list.push_back(recepient);
		}else{

			//Check if there are already 2 elements in queue
			//Delete the queue with the lowest number of dates
			auto map_size = date_information_q_[phonenumber].size();
			if(  map_size >= 2 ){
				MESSAGE_LOG("Delete elements with the lowest count of date");
				//Traverse map and compare
				auto info_front = get_queue->front();
				auto info_back = get_queue->back();

				auto map_element_front_count = info_front.date_count.begin()->second;
				auto map_element_back_count = info_back.date_count.begin()->second;

				// Delete front
				if( map_element_front_count < map_element_back_count ){
					get_queue->pop_front();
				}else{
					//Delete back
					get_queue->pop_back();
				}
			}else { /*Do nothing */}

			// Insert the new element
			{
				date_information info {};
				++info.date_count[date];
				info.phone_number_list.push_back(recepient);

				date_information_q_[phonenumber].push_front(info);
			}
		}

	}else{
		date_information info {};
		++info.date_count[date];
		info.phone_number_list.push_back(recepient);

		date_information_q_[phonenumber].push_front(info);
	}
}

#if 0
/** New implementation for the lacking function
 * determine the difference between send and receive date
 */
void phonedata_model::compute_date_difference( const date_format date_sent, const date_format date_receive ){

	auto year_diff = date_receive.year - date_sent.year;
	auto month_diff = date_receive.month - date_sent.month;
	auto day_diff = date_receive.day - date_sent.day;

}
#endif
