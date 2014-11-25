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
			List<int> a;
			Assert::AreEqual(true, a.isEmpty());
			a.push_front(10);
			Assert::AreEqual(false, a.isEmpty());
		}

		TEST_METHOD(TestListPushFront) {
			List<int> a;
			a.push_front(1);
			a.push_front(2);
			Assert::AreEqual(2, a.count());
		}

	};
}