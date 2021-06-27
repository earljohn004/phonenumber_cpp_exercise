#include "common_debug.h"
#include "worker.h"
#include "phonedata_model.h"
#include "prog_settings.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>

#ifndef TEST_MODE
int main( int argc, char *argv[] ){

	std::string default_filename{ "input.csv" };

	if(argc > 1){
		default_filename = std::move(argv[1]);
		VAR_LOG(default_filename);
	}else{
		MESSAGE_LOG("Loading default file input.csv");
	}

	std::shared_ptr<phonedata_model> data = std::make_shared<phonedata_model>();

	std::shared_ptr<prog_settings> settings = std::make_shared<prog_settings>();
	settings->set_config_file("config.xml");
	settings->open_config();

	std::unique_ptr<worker> work = std::make_unique<worker>( data, settings, default_filename );
	work->start_thread();

	return 0;
}
#endif
#ifdef TEST_MODE

TEST( config_input_and_output_rearrange ){
	std::string default_filename{ "input.csv" };

	std::shared_ptr<phonedata_model> data = std::make_shared<phonedata_model>();

	std::shared_ptr<prog_settings> settings = std::make_shared<prog_settings>();
	settings->set_config_file("config_rearrange.xml");
	settings->open_config();

	std::unique_ptr<worker> work = std::make_unique<worker>( data, settings, default_filename );
	work->start_thread();
}

TEST( config_exclude_items ){
	std::string default_filename{ "exclude_input.csv" };

	std::shared_ptr<phonedata_model> data = std::make_shared<phonedata_model>();

	std::shared_ptr<prog_settings> settings = std::make_shared<prog_settings>();
	settings->set_config_file("config_exclude.xml");
	settings->open_config();

	std::unique_ptr<worker> work = std::make_unique<worker>( data, settings, default_filename );
	work->start_thread();
}

TEST( config_delimeter_change ){
	std::string default_filename{ "delimeter_input.csv" };

	std::shared_ptr<phonedata_model> data = std::make_shared<phonedata_model>();

	std::shared_ptr<prog_settings> settings = std::make_shared<prog_settings>();
	settings->set_config_file("config_delimeter_change.xml");
	settings->open_config();

	std::unique_ptr<worker> work = std::make_unique<worker>( data, settings, default_filename );
	work->start_thread();
}

TEST( large_file_test ){
	std::string default_filename{ "big_input.csv" };

	std::shared_ptr<phonedata_model> data = std::make_shared<phonedata_model>();

	std::shared_ptr<prog_settings> settings = std::make_shared<prog_settings>();
	settings->set_config_file("config.xml");
	settings->open_config();

	std::unique_ptr<worker> work = std::make_unique<worker>( data, settings, default_filename );
	work->start_thread();
}


TEST_MAIN()

#endif
