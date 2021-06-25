#include "prog_settings.h"
#include "pugixml.hpp"
#include "common_debug.h"

#include <iostream>

void prog_settings::open_config(){
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("config.xml");

	pugi::xpath_node_set tools = doc.select_nodes("/config/input_setting");
	for(pugi::xpath_node node: tools){
		pugi::xml_node toool = node.node();
		std::cout << "attribute: " << toool.attribute("TimeStamp").value();
	}

	
}
