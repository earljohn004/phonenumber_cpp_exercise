#include "utility.h"
#include "common_defines.h"
#include "common_debug.h"

#include <iostream>
#include <algorithm>
#include <regex>
#include <string>
#include <memory>
#include <ctime>
#include <iomanip>

retcode utility::extract_phonenumber( const std::string phonenumber, std::string &output ){
	retcode ret { retcode::ret_ok };

	if( phonenumber.empty() ){
		ERROR_LOG("No Phone number to extract");
		return retcode::ret_ng;
	}else  {/* Do nothing */} 

	//Check for a valid phonenumber time input, return error if there is an alphabet
	if( !std::none_of(phonenumber.begin(), phonenumber.end(), [](unsigned char c){ return std::isalpha(c);})) {
		ERROR_LOG("Invalid phone number format");
		return retcode::ret_ng;
	}else  {/* Do nothing */} 

	std::regex remove_nonnumeric(R"([^0-9])");
	output = std::regex_replace(phonenumber, remove_nonnumeric, "");

	return ret;
}

retcode utility::extract_date_from_epoch( const std::string epoch_time, date_format &date ){
	retcode ret { retcode::ret_ok };

	//Check for empty string
	if( epoch_time.empty() ){
		ERROR_LOG("No Date to extract");
		return retcode::ret_ng;
	}else  {/* Do nothing */} 
	
	//Check for a valid epoch time input, return error if there is a non-numeric
	if( !std::all_of(epoch_time.begin(), epoch_time.end(), [](unsigned char c){ return std::isdigit(c); })) {
		ERROR_LOG("Invalid epoch time format");
		return retcode::ret_ng;
	}else  {/* Do nothing */} 

	std::time_t epoch = std::stol(epoch_time);
	std::tm tm = *std::gmtime(&epoch);
	date = { tm.tm_mon, tm.tm_mday, tm.tm_year };

	return ret;
}
