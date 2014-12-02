
template<class T>
struct Node {
	T info;
	Node<T> *next;

	Node<T>() {
		next = nullptr;
	}

	Node<T>(T info) {
		this->info = info;
		next = nullptr;
	}
};

template<class T>
class queue {
private:
	Node<T> *head;
	Node<T> *tail;

public:
	//konstruktor
	queue() {
		head = new Node<T>();
		tail = new Node<T>();
		head->next = tail;
	}
};