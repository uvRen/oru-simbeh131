#include "stdafx.h"
#include "CppUnitTest.h"
#include "../forward_list/forward_list.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TESTforward_list
{		
	TEST_CLASS(forward_list_test)
	{
	public:
		
		TEST_METHOD(TestListaEmpty) {
			forward_list<std::string> lista;
			Assert::AreEqual(true, lista.empty());

			lista.push_front("Hej");
			Assert::AreEqual(false, lista.empty());
		}

		TEST_METHOD(TestListaPush) {
			forward_list<int> lista;
			lista.push_front(10);
			Assert::AreEqual(10, lista.front());
			lista.push_front(20);
			Assert::AreEqual(20, lista.front());
			lista.push_front(30);
			Assert::AreEqual(30, lista.front());
		}

		TEST_METHOD(TestListaBeginEnd) {
			forward_list<int> lista;

			lista.push_front(1);
			lista.push_front(2);
			lista.push_front(3);
			lista.push_front(4);

			int tal = 4;

			for (forward_list<int>::iterator i = lista.begin(); i != lista.end(); ++i) {
				Assert::AreEqual(*i, tal);
				tal--;
			}

		}

	};
}