
template<class INFO>
struct Node {
	INFO information;
	Node<INFO> *next;

	Node<INFO>() {
		next = nullptr;
	}

	Node<INFO>(INFO a) {
		information = a;
	}
};

template<class INFO>
class List {
private:
	Node<INFO> *head;
	Node<INFO> *tail;

public:
	//konstruktor
	List() {
		head = tail = nullptr;
	}

	//funktioner
	bool isEmpty() {
		return (head == nullptr);
	}

	//add_at_head
	void push_front(INFO a) {
		//om listan är 
		Node<INFO> *n = new Node<INFO>(a);
		if (head == nullptr) {
			head = n;
			tail = head;
		}
		else {
			n->next = head;
			head = n;
		}
	}
};