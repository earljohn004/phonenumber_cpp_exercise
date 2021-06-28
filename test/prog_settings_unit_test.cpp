/**
 * prog_settings unit test source - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains the unit tests for phonedata_model cpp
 *
 **/

#include "common_debug.h"
#include "prog_settings.h"
#include "pugixml.hpp"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <cstdio>

#ifdef TEST_MODE

/** Test Description
 *		Test the function to open the config which is valid
 */
TEST(valid_config){
	retcode ret = retcode::ret_ng;
	std::unique_ptr<prog_settings> setting = std::make_unique<prog_settings>();
	setting->set_config_file("config.xml");
	ret = setting->open_config();
	ASSERT_EQUAL( retcode::ret_ok, ret );
}

/** Test Description
 *		Test the function to open the config which is invalid
 */
TEST(invalid_config){
	retcode ret = retcode::ret_ng;
	std::unique_ptr<prog_settings> setting = std::make_unique<prog_settings>();
	setting->set_config_file("asfdf.xml");
	ret = setting->open_config();
	ASSERT_EQUAL( retcode::ret_ng, ret );
}

TEST_MAIN()

#endif
