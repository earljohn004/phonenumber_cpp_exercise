/**
 * utility unit test source - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains the unit tests for utility cpp
 *
 **/

#include "common_debug.h"
#include "common_defines.h"
#include "utility.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#include <iostream>
#include <string>

#ifdef TEST_MODE

/** Test Description
 *		Test the function to extract information of valid formats
 */
TEST( phonenumber_valid_format_test ){
	std::unique_ptr<utility> util { std::make_unique<utility>() };
	std::string test_output {};
	retcode ret { retcode::ret_ng };

	ret = util->extract_phonenumber("1-2-3-4(5)6789-0",test_output);
	ASSERT_EQUAL( "1234567890", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	ret = util->extract_phonenumber("+(1  ) 23456-7890 ",test_output);
	ASSERT_EQUAL( "1234567890", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	ret = util->extract_phonenumber("+1  23-456-789-0 ",test_output);
	ASSERT_EQUAL( "1234567890", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );
}

/** Test Description
 *		Test the function to extract information of invalid formats
 */
TEST( phonenumber_invalid_format_test ){
	std::unique_ptr<utility> util { std::make_unique<utility>() };
	std::string test_output {};
	retcode ret { retcode::ret_ng };

	ret = util->extract_phonenumber("1-2-3ABDCSDEIFGSH-4(5)6789-0",test_output);
	ASSERT_EQUAL( retcode::ret_ng, ret );

	ret = util->extract_phonenumber("+1  23-456-789-0ABCDEFGHIJKlmnopqrstuvwxyz",test_output);
	ASSERT_EQUAL( retcode::ret_ng, ret );

	ret = util->extract_phonenumber("",test_output);
	ASSERT_EQUAL( retcode::ret_ng, ret );
}

/** Test Description
 *		Test the function to extract information of valid date formats
 */
TEST( epoch_time_valid_test ){
	std::unique_ptr<utility> util { std::make_unique<utility>() };
	std::string test_output {};
	retcode ret { retcode::ret_ng };
	date_format date {};

	auto epoch = 949588105;
	ret = util->extract_date_from_epoch( std::to_string(epoch), date );
	ASSERT_EQUAL( retcode::ret_ok, ret );
	ASSERT_EQUAL( "02-03-2000", date.to_string());
	std::cout << date;

	epoch = 969988798;
	ret = util->extract_date_from_epoch( std::to_string(epoch), date );
	ASSERT_EQUAL( retcode::ret_ok, ret );
	ASSERT_EQUAL( "09-26-2000", date.to_string());
	std::cout << date;

	epoch = 946775278;
	ret = util->extract_date_from_epoch( std::to_string(epoch), date );
	ASSERT_EQUAL( retcode::ret_ok, ret );
	ASSERT_EQUAL( "01-02-2000", date.to_string());
	std::cout << "correct date: "<< date;
}

/** Test Description
 *		Test the function to extract information of invalid date formats
 */
TEST( epoch_time_invalid_test ){
	std::unique_ptr<utility> util { std::make_unique<utility>() };
	std::string test_output {};
	retcode ret { retcode::ret_ng };

	date_format date {};

	ret = util->extract_date_from_epoch( "abcdefghilmnop", date );
	ASSERT_EQUAL( retcode::ret_ng, ret );

	ret = util->extract_date_from_epoch( "bbccdef1345", date );
	ASSERT_EQUAL( retcode::ret_ng, ret );

	ret = util->extract_date_from_epoch( "0(abcde)129-234-12(876)3-43", date );
	ASSERT_EQUAL( retcode::ret_ng, ret );

	ret = util->extract_date_from_epoch( "-+-----()", date );
	ASSERT_EQUAL( retcode::ret_ng, ret );
}

TEST_MAIN()

#endif
