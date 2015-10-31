#include "btest.h"
#include <iostream>

// TEST
template <typename Type>
TEST<Type>::TEST(Type check, Type expect)
	: checked(check), expected(expect) {
}

template <typename Type>
bool TEST<Type>::CHK_EQUAL() {
	if (checked == expected) { return true; }
	else { return false; }
}




// TEST_ENVIRON
template <typename Type>
TEST_ENVIRON<Type>::TEST_ENVIRON() {

	PRINT_PASS = true;
	PRINT_CHECK = true;
	ADD_TESTS = true;

}


template <typename Type>
bool TEST_ENVIRON<Type>::EQUALITY(Type test, Type expect) {

	TEST<Type> newtest(test, expect);

	if (PRINT_CHECK) { std::cout << "Expecting: " << expect << std::endl; 	std::cout << "Checking: " << test << std::endl;
	}

	if (newtest.CHK_EQUAL()) {
		if (PRINT_PASS) std::cout << "[PASS]" << std::endl;
		if (ADD_TESTS) tests.push_back(newtest);
		return true;

	}
	else {

		if (PRINT_PASS) std::cout << "[FAIL]" << std::endl;
		if (ADD_TESTS) tests.push_back(newtest);
		return false;

	}
}


