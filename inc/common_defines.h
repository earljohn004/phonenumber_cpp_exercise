/**
 * common_defines  header - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains common definitions used across the code
 *
 **/

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

	/** Overrides the ostream << operator
	 *  date_format can automatically be used in std::cout converting information
	 *  into mm-dd-yyyy format
	 */
	friend std::ostream& operator<<(std::ostream &out, const date_format date){
		return out <<  std::setw(2) << std::setfill('0') << std::to_string( date.month + 1) << "-" 
			<< std::setw(2) << std::setfill('0') << std::to_string(date.day) << "-" 
			<< std::to_string( date.year + 1900 ) << std::endl;
	}

	// Converts the struct into mm-dd--yyyy format
	std::string to_string(){
		std::stringstream ss;
		ss << std::setw(2) << std::setfill('0') << std::to_string( month + 1 ) << "-" 
			<< std::setw(2) << std::setfill('0') << std::to_string(day) << "-" 
			<< std::to_string( year + 1900 );
		return std::move(ss).str(); 
	}


	int month;
	int day;
	int year;
};

struct date_information{

	/** Counts the number of occurence of a certain date which
	 *  belongs to a sender phone number
	 */
	std::map< std::string, unsigned int> date_count;

	/** Contains all the information of recipient  numbers
	 *  all information is stored in the vector
	 */
	std::vector<std::string> phone_number_list;
};

#endif //_H_COMMON_DEFINES_H
