#include "common_debug.h"
#include "common_defines.h"
#include "worker.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <fstream>

#ifdef TEST_MODE


TEST( simple_thread_test ){
	std::unique_ptr<worker> work = std::make_unique<worker>();
}

TEST_MAIN()

#endif
