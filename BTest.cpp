#include "btest.h"
#include <iostream>
#include <cmath>


namespace testing {

	// TEST
	template <typename Type>
	TEST<Type>::TEST(Type check, Type expect)
		: checked(check), expected(expect) {
	}

	template <>
	bool TEST<float>::CHK_EQUAL() {
		if (fabs(checked - expected) < 0.001) { return true; }
		else { return false; }
	}

	template <>
	bool TEST<double>::CHK_EQUAL() {
		if (fabs(checked - expected) < 0.001) { return true; }
		else { return false; }
	}

	template <typename Type>
	bool TEST<Type>::CHK_EQUAL() {
		if (checked == expected) { return true; }
		else { return false; }
	}




	// TEST_ENVIRON
	TEST_ENVIRON::TEST_ENVIRON(bool pass, bool check, bool add) 
		: PRINT_PASS(pass), PRINT_CHECK(check), ADD_TESTS(add),
			passed(0), tests(0){

	}


	template <typename Type>
	bool TEST_ENVIRON::EQUALITY(Type test, Type expect) {

		TEST<Type> newtest(test, expect);
		if (ADD_TESTS) tests++;

		if (PRINT_CHECK) {
			std::cout << "Expecting: " << expect << std::endl; 	std::cout << "Checking: " << test << std::endl;
		}

		if (newtest.CHK_EQUAL()) {
			if (PRINT_PASS) std::cout << "[PASS]" << std::endl;
			if (ADD_TESTS) passed++;
			return true;

		}
		else {

			if (PRINT_PASS) std::cout << "[FAIL]" << std::endl;
			return false;

		}
	}

	double TEST_ENVIRON::RESULTS() {

		double grade = passed / tests;
		std::cout << "Results: " << passed << "/" << tests << " tests passed. Grade: " << grade*100 << "%" << std::endl;
		return grade;
	}


} //testing