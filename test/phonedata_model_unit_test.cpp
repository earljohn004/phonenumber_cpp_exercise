/**
 * phonedata_model unit test source - version 1.00
 * --------------------------------------------------------
 * Created June 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains the unit tests for phonedata_model cpp
 *
 **/

#include "common_debug.h"
#include "common_defines.h"
#include "phonedata_model.h"
#include "utility.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#include <iostream>
#include <string>
#include <tuple>

#ifdef TEST_MODE

/** Test Description
 *		Test the function to increase the phonenumber_send count of each 
 *		phone numbers receive with the same format
 */
TEST( phonenumber_send_increase ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };

	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	auto total = phonedata->get_total_send("1234567890");
	VAR_LOG(total);

	ASSERT_EQUAL(10, total);
}

/** Test Description
 *		Test the function to increase the phonenumber_send count of each 
 *		phone numbers receive with different formats
 */
TEST( phonenumber_send_increase_diff_format ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };
	std::unique_ptr<utility> util { std::make_unique<utility>() };
	std::string test_output {};

	retcode ret { retcode::ret_ng };


	// ------- Begin of format 1 ---------
	ret = util->extract_phonenumber("+1 234 5678 900",test_output);

	ASSERT_EQUAL( "12345678900", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	if(ret == retcode::ret_ok){
		phonedata->increment_phonenumber_send( test_output );
	}else {/* Do nothing */}
	// ------- End of format 1 ----------
	
	// ------- Begin of format 2 ---------
	ret = util->extract_phonenumber("+(1) 234 5678 900",test_output);

	ASSERT_EQUAL( "12345678900", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	if(ret == retcode::ret_ok){
		phonedata->increment_phonenumber_send( test_output );
	}else {/* Do nothing */}
	// ------- End of format 2----------
	
	// ------- Begin of format 3 ---------
	ret = util->extract_phonenumber("+(1) 234-567-8900",test_output);

	ASSERT_EQUAL( "12345678900", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	if(ret == retcode::ret_ok){
		phonedata->increment_phonenumber_send( test_output );
	}else {/* Do nothing */}
	// ------- End of format 3----------
	
	// ------- Begin of format 4 ---------
	ret = util->extract_phonenumber("12345678900",test_output);

	ASSERT_EQUAL( "12345678900", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	if(ret == retcode::ret_ok){
		phonedata->increment_phonenumber_send( test_output );
	}else {/* Do nothing */}
	// ------- End of format 4----------

	auto total = phonedata->get_total_send("12345678900");
	VAR_LOG(total);

	ASSERT_EQUAL(4, total);
}

/** Test Description
 *		Test the function to increase the phonenumber_receive count of each 
 *		phone numbers receive with same format
 */
TEST( phonenumber_receive_increase ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };
	std::string test_output {};

	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	auto total = phonedata->get_total_receive("1234567890");
	VAR_LOG(total);

	ASSERT_EQUAL(10, total);
}

/** Test Description
 *		Test the function to increase the phonenumber_receive count of each 
 *		phone numbers receive with different formats
 */
TEST( phonenumber_receive_increase_diff_format ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };
	std::unique_ptr<utility> util { std::make_unique<utility>() };
	std::string test_output {};

	retcode ret { retcode::ret_ng };


	// ------- Begin of format 1 ---------
	ret = util->extract_phonenumber("+1 234 5678 900",test_output);

	ASSERT_EQUAL( "12345678900", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	if(ret == retcode::ret_ok){
		phonedata->increment_phonenumber_receive( test_output );
	}else {/* Do nothing */}
	// ------- End of format 1 ----------
	
	// ------- Begin of format 2 ---------
	ret = util->extract_phonenumber("+(1) 234 5678 900",test_output);

	ASSERT_EQUAL( "12345678900", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	if(ret == retcode::ret_ok){
		phonedata->increment_phonenumber_receive( test_output );
	}else {/* Do nothing */}
	// ------- End of format 2----------
	
	// ------- Begin of format 3 ---------
	ret = util->extract_phonenumber("+(1) 234-567-8900",test_output);

	ASSERT_EQUAL( "12345678900", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	if(ret == retcode::ret_ok){
		phonedata->increment_phonenumber_receive( test_output );
	}else {/* Do nothing */}
	// ------- End of format 3----------
	
	// ------- Begin of format 4 ---------
	ret = util->extract_phonenumber("12345678900",test_output);

	ASSERT_EQUAL( "12345678900", test_output );
	ASSERT_EQUAL( retcode::ret_ok, ret );

	if(ret == retcode::ret_ok){
		phonedata->increment_phonenumber_receive( test_output );
	}else {/* Do nothing */}
	// ------- End of format 4----------

	auto total = phonedata->get_total_receive("12345678900");
	VAR_LOG(total);

	ASSERT_EQUAL(4, total);
}

/** Test Description
 *		Test the function to increase the phonenumber_send count of each 
 *		phone numbers send with different numbers
 */
TEST( phonenumber_multiple_send_increase ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };

	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	phonedata->increment_phonenumber_send("1234567890");
	auto total = phonedata->get_total_send("1234567890");
	ASSERT_EQUAL(4, total);

	phonedata->increment_phonenumber_send("0987654321");
	phonedata->increment_phonenumber_send("0987654321");
	phonedata->increment_phonenumber_send("0987654321");
	phonedata->increment_phonenumber_send("0987654321");
	total = phonedata->get_total_send("0987654321");
	ASSERT_EQUAL(4, total);

	total = phonedata->get_total_send("111111111");
	ASSERT_EQUAL(0, total);
}

/** Test Description
 *		Test the function to increase the phonenumber_receive count of each 
 *		phone numbers receive with different numbers
 */
TEST( phonenumber_multiple_receive_increase ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };

	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	phonedata->increment_phonenumber_receive("1234567890");
	auto total = phonedata->get_total_receive("1234567890");
	ASSERT_EQUAL(4, total);

	phonedata->increment_phonenumber_receive("0987654321");
	phonedata->increment_phonenumber_receive("0987654321");
	phonedata->increment_phonenumber_receive("0987654321");
	phonedata->increment_phonenumber_receive("0987654321");
	total = phonedata->get_total_receive("0987654321");
	ASSERT_EQUAL(4, total);

	total = phonedata->get_total_receive("111111111");
	ASSERT_EQUAL(0, total);
}

/** Test Description
 *		Test the function to get the correct information of the phone number
 *		with the highest recorded date and highest recorded recipient numbers
 *		with a single phone number
 */
TEST( phonenumber_date_send_countqueue_test ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };
	std::string phonenumber {"12345678900"};

	phonedata->add_date_information( phonenumber, "06-04-1993", "3830656" );
	phonedata->add_date_information( phonenumber, "06-04-1993", "3830656" );
	phonedata->add_date_information( phonenumber, "06-04-1993", "3844724" );

	phonedata->add_date_information( phonenumber, "08-08-1996", "3844724" );
	phonedata->add_date_information( phonenumber, "08-08-1996", "3830656" );

	phonedata->add_date_information( phonenumber, "12-12-1996", "3830656" );
	phonedata->add_date_information( phonenumber, "12-12-1996", "3830656" );

	ASSERT_EQUAL(7, phonedata->get_total_send(phonenumber));

	auto [getdate, gettotal, recepient] = phonedata->get_phone_max_date(phonenumber);

	ASSERT_EQUAL("06-04-1993", getdate);
	VAR_LOG(getdate);
	ASSERT_EQUAL(3, gettotal );
	VAR_LOG(gettotal);
	ASSERT_EQUAL("3830656", recepient);
	VAR_LOG(recepient);
}

/** Test Description
 *		Test the function to get the correct information of the phone number
 *		with the highest recorded date and highest recorded recipient numbers
 *		with multiple phonenumbers and varying dates
 */
TEST( phonenumber_date_send_countqueue_multiple_test ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };
	std::string phonenumber {"12345678900"};

	phonedata->add_date_information( phonenumber, "06-04-1993", "3844724" );
	phonedata->add_date_information( phonenumber, "06-04-1993", "3830656" );
	phonedata->add_date_information( phonenumber, "06-04-1993", "3844724" );
	phonedata->add_date_information( phonenumber, "06-04-1993", "3844724" );

	phonedata->add_date_information( phonenumber, "08-08-1996", "3844724" );
	phonedata->add_date_information( phonenumber, "08-08-1996", "3830656" );

	phonedata->add_date_information( phonenumber, "12-12-1996", "3830656" );
	phonedata->add_date_information( phonenumber, "12-12-1996", "3830656" );

	ASSERT_EQUAL(8, phonedata->get_total_send(phonenumber));

	{
		auto [getdate, gettotal, recepient] = phonedata->get_phone_max_date(phonenumber);

		ASSERT_EQUAL("06-04-1993", getdate);
		VAR_LOG(getdate);
		ASSERT_EQUAL(4, gettotal );
		VAR_LOG(gettotal);
		ASSERT_EQUAL("3844724", recepient);
		VAR_LOG(recepient);
	}

	phonenumber =  "12222333300";

	phonedata->add_date_information( phonenumber, "01-01-2002", "3830656" );

	phonedata->add_date_information( phonenumber, "03-14-2002", "3830656" );
	phonedata->add_date_information( phonenumber, "03-14-2002", "3844724" );

	phonedata->add_date_information( phonenumber, "08-01-2003", "3844724" );
	phonedata->add_date_information( phonenumber, "08-01-2003", "3844724" );
	phonedata->add_date_information( phonenumber, "08-01-2003", "3830656" );

	phonedata->add_date_information( phonenumber, "02-28-2000", "3844724" );
	phonedata->add_date_information( phonenumber, "02-28-2000", "3844724" );
	phonedata->add_date_information( phonenumber, "02-28-2000", "3830656" );
	phonedata->add_date_information( phonenumber, "02-28-2000", "3844724" );

	ASSERT_EQUAL(10, phonedata->get_total_send(phonenumber));

	{
		auto [getdate, gettotal, recepient] = phonedata->get_phone_max_date(phonenumber);

		ASSERT_EQUAL("02-28-2000", getdate);
		VAR_LOG(getdate);
		ASSERT_EQUAL(4, gettotal );
		VAR_LOG(gettotal);
		ASSERT_EQUAL("3844724", recepient);
		VAR_LOG(recepient);
	}
}

/** Test Description
 *		Test the function to get the correct information of the phone number
 *		with the highest recorded recipient number
 */
TEST( phonenumber_vector_highest_element_check ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };
	std::vector<std::string> test_vector {"123", "456", "123", "456", "123", "789"};
	std::string output;

	phonedata->get_largest_element(test_vector, output);
	ASSERT_EQUAL( "123", output );
}

TEST_MAIN()

#endif
