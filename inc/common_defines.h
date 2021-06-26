#ifndef _H_COMMON_DEFINES_H
#define _H_COMMON_DEFINES_H

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

enum class retcode : int 
{
	ret_ng = -1,
	ret_ok = 0
};

struct date_format 
{

	friend std::ostream& operator<<(std::ostream &out, const date_format date){
		return out <<  std::setw(2) << std::setfill('0') << std::to_string(date.month) << "-" 
			<< std::setw(2) << std::setfill('0') << std::to_string(date.day) << "-" 
			<< std::to_string( date.year + 1900 ) << std::endl;
	}

	std::string to_string(){
		std::stringstream ss;
		ss << std::setw(2) << std::setfill('0') << std::to_string(month) << "-" 
			<< std::setw(2) << std::setfill('0') << std::to_string(day) << "-" 
			<< std::to_string( year + 1900 );
		return std::move(ss).str(); 
	}


	int month;
	int day;
	int year;
};

struct date_information{

	std::map< std::string, unsigned int> date_count;
	std::vector<std::string> phone_number_list;
};

#endif //_H_COMMON_DEFINES_H
