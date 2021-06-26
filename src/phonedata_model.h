#ifndef _H_PHONEDATAMODEL_H_
#define _H_PHONEDATAMODEL_H_

#include "common_defines.h"

#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <tuple>
#include <deque>


class phonedata_model{

	public:
		phonedata_model() = default;
		~phonedata_model() = default;

		int get_total_receive( const std::string  phonenumber ); 
		int get_total_send( const std::string  phonenumber ); 
		void increment_phonenumber_receive( const std::string phonenumber );
		void increment_phonenumber_send( const std::string phonenumber );

		void add_date_information( const std::string phonenumber, const std::string date);
		std::tuple<std::string, std::string, int> get_phone_max_date( const std::string phonenumber );

		void add_date_information_q( const std::string phonenumber, const std::string date, const std::string recepient);

	private:

	private:
		std::map<std::string, unsigned int> total_receive_;
		std::map<std::string, unsigned int> total_send_;

		std::map<std::string, std::stack<std::string>> date_information_;
		std::map<std::string, unsigned int> total_send_of_date_; 

		std::map<std::string, std::deque<date_information>> date_information_q_;

};


#endif// _H_PHONEDATAMODEL_H_
