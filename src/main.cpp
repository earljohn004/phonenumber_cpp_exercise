/**
 * phonedata_model source - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains the main function
 *
 **/

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

/** including -DTEST_MODE in Makefile CXXFlags will result to 
 * below codes being run. Refer to the unit_test_framework documentation how to run
 * specific tests
 */
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
