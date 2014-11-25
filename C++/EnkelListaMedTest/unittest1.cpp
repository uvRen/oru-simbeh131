#include "stdafx.h"
#include "CppUnitTest.h"
#include "List.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EnkelListaMedTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestListIsEmpty) {
			List<std::string> a;
			Assert::AreEqual(true, a.isEmpty());
			a.push_front("Simon");
			Assert::AreEqual(false, a.isEmpty());
		}

		TEST_METHOD(TestListPushFront) {

		}

	};
}