#include "common_debug.h"
#include "prog_settings.h"

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
	std::unique_ptr<Logic> logic = std::make_unique<Logic>();
	ASSERT_EQUAL(3,logic->get_sum(1,2));
}

TEST(random_test){
	std::unique_ptr<Logic> logic = std::make_unique<Logic>();
	ASSERT_EQUAL(29,logic->get_sum(28,1));
	ASSERT_EQUAL(29,logic->get_sum(24,5));
}

TEST(test_test){
	std::unique_ptr<Logic> logic = std::make_unique<Logic>();
	ASSERT_EQUAL(30,logic->get_sum(28,1));
	ASSERT_EQUAL(35,logic->get_sum(24,5));
}

TEST_MAIN()

#endif
