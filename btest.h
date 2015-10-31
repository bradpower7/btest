#ifndef BTEST_H
#define BTEST_H


#include <stdio.h>
#include <vector>


template <class Type>
class TEST{
	
	public:
	TEST(Type, Type);
	
	bool CHK_EQUAL();
	
	
	private:
	
	Type checked;
	Type expected;
	
	
	
	
};

template <class Type>
class TEST_ENVIRON{

	public:
	
	TEST_ENVIRON();
	
	bool EQUALITY(Type test, Type expect);
	
	
	
	private:
	
	// Flags
	bool PRINT_PASS;
	bool PRINT_CHECK;
	bool ADD_TESTS;
	
	
	std::vector<TEST<Type>> tests;
	

	

};


#endif