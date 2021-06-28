/**
 * prog settings header - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains helper functions
 *
 **/

#ifndef _PROG_SETTINGS_H
#define _PROG_SETTINGS_H

#include "common_defines.h"

class prog_settings{
	public:
		prog_settings() = default;
		~prog_settings() = default;

		retcode open_config();
		retcode set_config_file( std::string file );

		std::vector<std::string> get_input_settings();
		std::vector<std::string> get_output_settings();
		char get_delimeter();

	private:
		std::vector<std::string> settings_;
		std::vector<std::string> output_;
		std::string delimeter_;
		std::string config_file_;

};

#endif//_PROG_SETTINGS_H
