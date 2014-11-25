
template<class T>
struct Node {
	T information;
	Node<T> *next;

	Node<T>() {
		this->next = nullptr;
	}

	Node<T>(T information) {
		this->information = information;
		next = nullptr;
	}
};

template<class T>
class forward_list {
private:
	Node<T> *head;
	Node<T> *tail;

public:
	//konstruktor
	forward_list() {
		head = tail = nullptr;
	}

	//funktioner
	bool empty() {
		return (head == nullptr);
	}

	void push_front(T info) {
		//om listan �r tom
		if (head == nullptr) {
			head = new Node<T>(info);
			tail = head;
		}
		//om listan inte �r tom
		else {
			Node<T> *n = new Node<T>(info);
			n->next = head;
			head = n;
		}
	}
};