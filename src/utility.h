/**
 * utility header - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains helper functions
 *
 **/

#ifndef _H_UTILITY_H_
#define _H_UTILITY_H_

#include "common_defines.h"

#include <iostream>
#include <string>

class utility{
	public:
		utility() = default;
		~utility() = default;

		retcode extract_phonenumber( const std::string phonenumber, std::string &output );
		retcode extract_date_from_epoch( const std::string epoch_time, date_format &date ); 
		int compute_date_difference( const date_format date_sent, const date_format date_receive );

	private:
};

#endif// _H_UTILITY_H_
