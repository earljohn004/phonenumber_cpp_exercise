#include "prog_settings.h"
#include "pugixml.hpp"
#include "common_debug.h"
#include "common_defines.h"

#include <iostream>

retcode prog_settings::open_config(){

	retcode ret = retcode::ret_ok;

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("config.xml");

	if(!result){
		MESSAGE_LOG("[ERROR] config error. loading default configuration");
		return retcode::ret_ng;
	}

	auto input_included = doc.child("config").child("input_setting").child("included").first_child();
	MESSAGE_LOG("Input settings");
	for( input_included.first_child(); input_included ; input_included = input_included.next_sibling()){
		//TODO: add implementation for program settings
		VAR_LOG(input_included.name());
	}

	auto output_included = doc.child("config").child("output_setting").child("included").first_child();
	MESSAGE_LOG("Output settings");
	for( output_included.first_child(); output_included ; output_included = output_included.next_sibling()){
		//TODO: add implementation for program settings
		VAR_LOG(output_included.name());
	}

	auto delimeter_setting = doc.child("config").child("delimeter_setting").first_child().value();
	VAR_LOG(delimeter_setting);

	return ret;

}
