#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DOA-Tenta150108/circular_list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TESTcircular_list
{		
	TEST_CLASS(circular_list)
	{
	public:
		
		TEST_METHOD(ListIsEmpty)
		{
			Betyg4::circular_list lista;
			Assert::AreEqual(true, lista.empty());
			lista.add("Hej");
			Assert::AreEqual(false, lista.empty());
		}

		TEST_METHOD(ListaAdd) {
			Betyg4::circular_list lista;
			string test = "";
			Assert::AreEqual(test, lista.front());

			lista.add("Hej");
			test = "Hej";
			Assert::AreEqual(test, lista.front());
		}
	};
}