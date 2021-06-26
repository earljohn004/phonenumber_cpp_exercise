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

TEST( phonenumber_date_send_count_test ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };
	std::string phonenumber {"12345678900"};
	std::string date {"06-04-1993"};

	phonedata->increment_phonenumber_send( phonenumber );
	phonedata->add_date_information( phonenumber, "06-04-1993" );
	phonedata->increment_phonenumber_send( phonenumber );
	phonedata->add_date_information( phonenumber, "06-04-1993" );
	phonedata->increment_phonenumber_send( phonenumber );
	phonedata->add_date_information( phonenumber, "06-04-1993" );

	ASSERT_EQUAL( 3 , phonedata->get_total_send(phonenumber));

	auto [getnumber, getdate, gettotal] = phonedata->get_phone_max_date(phonenumber);

	ASSERT_EQUAL(phonenumber, getnumber);
	ASSERT_EQUAL(getdate, "06-04-1993");
	ASSERT_EQUAL(gettotal, 3);
}

TEST( phonenumber_date_send_countqueue_test ){
	std::unique_ptr<phonedata_model> phonedata { std::make_unique<phonedata_model>() };
	std::string phonenumber {"12345678900"};
	std::string date {"06-04-1993"};

	phonedata->increment_phonenumber_send( phonenumber );
	phonedata->add_date_information_q( phonenumber, "06-04-1993", "0987654321" );
	phonedata->increment_phonenumber_send( phonenumber );
	phonedata->add_date_information_q( phonenumber, "06-04-1993", "0987654321" );
	phonedata->increment_phonenumber_send( phonenumber );
	phonedata->add_date_information_q( phonenumber, "06-04-1993", "0987654321" );

	ASSERT_EQUAL( 3 , phonedata->get_total_send(phonenumber));

	// auto [getnumber, getdate, gettotal] = phonedata->get_phone_max_date(phonenumber);

	// ASSERT_EQUAL(phonenumber, getnumber);
	// ASSERT_EQUAL(getdate, "06-04-1993");
	// ASSERT_EQUAL(gettotal, 3);
}

TEST_MAIN()

#endif
