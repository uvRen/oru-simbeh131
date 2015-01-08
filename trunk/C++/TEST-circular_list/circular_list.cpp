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

		TEST_METHOD(ListaRemove) {
			Betyg4::circular_list lista;

			lista.add("1");
			lista.add("2");
			lista.add("3");
			lista.add("4");
			lista.add("5");

			lista.remove();

			string test = "4";
			Assert::AreEqual(test, lista.front());
		}

		TEST_METHOD(ListaIterator) {
			Betyg4::circular_list lista;

			lista.add("1");
			lista.add("2");
			lista.add("3");
			lista.add("4");
			lista.add("5");

			string test = "5";

			Betyg4::circular_list::iterator it = lista.begin()+1;
			Assert::AreEqual(test, *it);
			it = ++it;
			test = "4";
			Assert::AreEqual(test, *it);
			it = ++it;
			test = "3";
			Assert::AreEqual(test, *it);
			it = ++it;
			test = "2";
			Assert::AreEqual(test, *it);
			it = ++it;
			test = "1";
			Assert::AreEqual(test, *it);


			it = lista.end();
			Assert::AreEqual(test, *it);

			it = lista.begin() + 2;
			test = "4";
			Assert::AreEqual(test, *it);

			it = lista.begin() + 5;
			test = "1";
			Assert::AreEqual(test, *it);

			it = lista.begin();
			it = ++it;

			test = "5";
			Assert::AreEqual(test, *it);

			it = lista.begin();
			Betyg4::circular_list::iterator it2 = lista.begin();
			bool result = (it2 == it);
			Assert::AreEqual(true, result);

			it2 = ++it2;
			result = (it2 != it);
			Assert::AreEqual(true, result);


		}
	};
}