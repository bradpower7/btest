#ifndef BTEST_H
#define BTEST_H


#include <stdio.h>
#include <vector>

namespace testing {


	template <class Type>
	class TEST {

	public:
		TEST(Type, Type);

		bool CHK_EQUAL();


	private:

		Type checked;
		Type expected;




	};

	class TEST_ENVIRON {

	public:

		TEST_ENVIRON(bool, bool, bool);

		template <class Type>
		bool EQUALITY(Type test, Type expect);

		double RESULTS();

	private:

		// Flags
		bool PRINT_PASS;
		bool PRINT_CHECK;
		bool ADD_TESTS;

		unsigned int passed;
		unsigned int tests;




	};


} // testing

#endif