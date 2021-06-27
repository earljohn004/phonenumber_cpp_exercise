#include "prog_settings.h"
#include "pugixml.hpp"
#include "common_debug.h"
#include "common_defines.h"

#include <iostream>

std::vector<std::string> prog_settings::get_input_settings() { 
	return settings_; 
}

std::vector<std::string> prog_settings::get_output_settings(){
	for( auto str: output_){
		std::cout << std::setw(13) << str << ",";
	}
	std::cout << std::endl;
	return output_;
}

char prog_settings::get_delimeter(){
	return delimeter_.at(0);
}

retcode prog_settings::set_config_file( std::string file ){
	retcode ret = retcode::ret_ok;

	config_file_ =  file ;

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file( config_file_.c_str() );

	if(!result){
		MESSAGE_LOG("[ERROR] config error. loading default configuration");
		return retcode::ret_ng;
	}

	return ret;
}

retcode prog_settings::open_config(){

	retcode ret = retcode::ret_ok;

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file( config_file_.c_str() );

	if(!result){
		MESSAGE_LOG("[ERROR] config error. loading default configuration");
		return retcode::ret_ng;
	}

	auto input_included = doc.child("config").child("input_setting").child("included").first_child();
	MESSAGE_LOG("Loading Input settings");
	for( input_included.first_child(); input_included ; input_included = input_included.next_sibling()){
		settings_.push_back( input_included.name());
	}

	auto output_included = doc.child("config").child("output_setting").child("included").first_child();
	MESSAGE_LOG("Loading  Output settings");
	for( output_included.first_child(); output_included ; output_included = output_included.next_sibling()){
		output_.push_back( output_included.name() );
	}

	auto delimeter_setting = doc.child("config").child("delimeter_setting").first_child().value();
	VAR_LOG(delimeter_setting);
	delimeter_ = delimeter_setting;

	return ret;

}
