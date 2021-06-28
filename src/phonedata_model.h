/**
 * phonedata_model header - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains the data information of the phone model 
 *
 **/

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
		void get_largest_element( const std::vector<std::string> list, std::string & output );
		std::tuple<std::string, int, std::string> get_phone_max_date( const std::string phonenumber );
		void add_date_information( const std::string phonenumber, const std::string date, const std::string recepient);
		std::string display_output(const std::vector<std::string> setting);
		std::vector<std::string> get_list_of_elements();

	private:
		void increment_receive(const std::string phonenumber);
		void increment_send(const std::string phonenumber);
		std::string list_largest_element( const std::vector<std::string> list );

	private:
		std::map<std::string, unsigned int> total_receive_;
		std::map<std::string, unsigned int> total_send_;
		std::map<std::string, std::deque<date_information>> date_information_q_;

};


#endif// _H_PHONEDATAMODEL_H_
