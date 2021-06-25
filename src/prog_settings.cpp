#include "prog_settings.h"
#include "pugixml.hpp"
#include "common_debug.h"

#include <iostream>

void prog_settings::open_config(){
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("config.xml");

	if(!result){
		MESSAGE_LOG("[ERROR] file not found. loading default configuration");
	}

	auto included = doc.child("config").child("input_setting").child("included").first_child();
	for( included.first_child(); included ; included = included.next_sibling()){
		std::cout << included.name() << std::endl;
	}

}
