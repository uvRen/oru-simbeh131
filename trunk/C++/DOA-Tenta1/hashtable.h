#include <iostream>
#include <ostream>

using namespace std;

namespace Betyg5 {

	template<class KEY, class VALUE>
	class Node {
	public:
		KEY key;
		VALUE value;
		Node<KEY, VALUE> *next;

		Node<KEY, VALUE>() {
			next = nullptr;
		}

		Node<KEY, VALUE>(KEY key, VALUE value) {
			this->key = key;
			this->value = value;
			next = nullptr;
		}

		friend ostream& operator<<(ostream &ut, const Node<KEY, VALUE> &n) {
			ut << '[' << n.key << ',' << n.value << ',' << n.next << ']';
			return ut;
		}
	};

	template<class KEY, class VALUE>
	class HashTable {
	private:
		Node<KEY, VALUE> *head;
		vector <Node<KEY, VALUE>> *table;

	public:
		HashTable(int tableSize) {
			head = nullptr;
			
			table = new vector <Node<KEY, VALUE>>(tableSize);
			for (auto &a : *table) {
				a = Node<KEY, VALUE>();
			}
		}

		void size() {
			for (auto &a : *table) {
				cout << a << endl;
			}
		}
	};
}