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

TEST(numbers_equal){
	std::unique_ptr<prog_settings> setting = std::make_unique<prog_settings>();
	setting->open_config();
}

TEST_MAIN()

#endif
