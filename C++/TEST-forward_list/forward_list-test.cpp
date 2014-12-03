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

		TEST_METHOD(TestListaPopFront) {
			forward_list<int> lista;

			lista.push_front(10);
			lista.push_front(20);
			lista.push_front(30);
			lista.push_front(40);

			Assert::AreEqual(40, lista.front());
			lista.pop_front();
			Assert::AreEqual(30, lista.front());
			lista.pop_front();
			Assert::AreEqual(20, lista.front());
			lista.pop_front();
			Assert::AreEqual(10, lista.front());
			lista.pop_front();

			Assert::AreEqual(true, lista.empty());

		}

		TEST_METHOD(TestListaInsertAfter) {
			forward_list<int> lista;
			forward_list<int>::iterator i1 = lista.begin();
			forward_list<int>::iterator i2 = lista.begin();
			forward_list<int>::iterator i3 = lista.begin();
			forward_list<int>::iterator i4 = lista.begin();

			lista.push_front(10);
			lista.push_front(20);
			lista.push_front(30);
			lista.push_front(40);
			lista.push_front(10);
			lista.push_front(20);
			lista.push_front(30);
			lista.push_front(40);

			int tal = 25;

			i1 = lista.insert_after(lista.begin(), tal);
			i2 = lista.insert_after(lista.begin()+1, tal);
			i3 = lista.insert_after(lista.begin()+2, tal);
			i4 = lista.insert_after(lista.begin()+6, tal);

			for (forward_list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
				if (it == i1) {
					Assert::AreEqual(25, *it);
				}
				else if (it == i2) {
					Assert::AreEqual(25, *it);
				}
				else if (it == i3) {
					Assert::AreEqual(25, *it);
				}
				else if (it == i4) {
					Assert::AreEqual(25, *it);
				}
			}


		}

	};
}