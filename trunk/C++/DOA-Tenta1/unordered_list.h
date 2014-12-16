#include <string>

namespace Betyg4 {
	using namespace std;

	class Node {
	public:
		string INFO;
		Node *next;

		Node() {
			INFO = "";
			next = nullptr;
		}

		Node(string INFO) {
			this->INFO = INFO;
			next = nullptr;
		}
	};

	class unordered_list {
	private:
		Node *head;
		Node *tail;
		Node *freelist;

	public:
#pragma region Kontruktor
		unordered_list() {
			head = new Node();
			freelist = new Node();
		}

		unordered_list(int size_freelist) {
			head = new Node();
			freelist = new Node();

			for (int i = 0; i < size_freelist; i++) {
				Node *n = new Node();
				n->next = freelist->next;
				freelist->next = n;
			}
		}

		~unordered_list() {
			Node *n = head->next;
			Node *temp = head;

			while (n != nullptr) {
				temp = n->next;
				delete n;
				n = temp;
			}

			n = freelist->next;
			while (n != nullptr) {
				temp = n->next;
				delete n;
				n = temp;
			}

			head->next = nullptr;
			freelist->next = nullptr;
		}

#pragma endregion Konstruktor

#pragma region Iterator
		class iterator {
		public:
			//konstruktor
			iterator(Node *n) {
				current = n;
			}

			//funktioner
			iterator operator++() {
				current = current->next;
				return *this;
			}

			iterator operator+(int plus) {
				for (int i = 0; i < plus; i++) {
					current = current->next;
				}
				return *this;
			}

			bool operator!=(const iterator &rhs) {
				return (current != rhs.current);
			}

			bool operator==(const iterator &rhs) {
				return (current == rhs.current);
			}

			Node* operator->() {
				return current;
			}

			string& operator*() {
				return current->INFO;
			}

		private:
			Node* current;
		};
		};

#pragma endregion Iterator

#pragma region Medlemsfunktioner

		Node* lastNode() {
			Node *n = head;

			while (n->next != nullptr) {
				n = n->next;
			}
			return n;
		}

		void add(string INFO) {
			//om det finns noder lediga i freelist
			if (freelist->next != nullptr) {
				Node *n = freelist->next;
				if (freelist->next->next != nullptr) {
					freelist->next = freelist->next->next;
				}
				else {
					freelist->next = nullptr;
				}
				n->INFO = INFO;
				n->next = nullptr;
				Node *last = lastNode();
				last->next = n;
			}
			//annars allokera minne för en ny nod
			else {
				Node *n = new Node(INFO);
				Node *last = lastNode();
				last->next = n;
			}
		}

		void delete_head_node() {
			Node *n = head->next;
			head->next = n->next;

			n->INFO = "";
			n->next = freelist->next;
			freelist->next = n;
		}

		void clear() {
			Node *n = head->next;
			Node *temp = head;

			while (head->next != nullptr) {
				temp = head->next;
				head->next = head->next->next;
				temp->INFO = "";
				temp->next = freelist->next;
				freelist->next = temp;
			}
		}
		

		
#pragma endregion Medlemsfunktioner

		string showValue(Node *n) {
			return n->INFO;
		}

		void printList() {
			Node *n = head->next;

			while (n != nullptr) {
				cout << n->INFO << endl;
				n = n->next;
			}
			cout << endl;
		}

		void count() {
			int list, free;
			list = free = 0;

			Node *n = head->next;
			while (n != nullptr) {
				list++;
				n = n->next;
			}

			n = freelist->next;
			while (n != nullptr) {
				free++;
				n = n->next;
			}

			cout << "Lista: " << list << endl << "Freelist: " << free << endl;
		}
	};
}