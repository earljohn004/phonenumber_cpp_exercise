#include "common_debug.h"
#include "worker.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>

#ifndef TEST_MODE
int main(){
	std::unique_ptr<worker> work = std::make_unique<worker>();
	work->start_thread();

	return 0;
}
#endif
#ifdef TEST_MODE

TEST_MAIN()

#endif
