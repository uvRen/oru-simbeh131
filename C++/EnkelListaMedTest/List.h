
template<class INFO>
struct Node {
	INFO information;
	Node<INFO> *next;
};

template<class INFO>
class List {
private:
	Node<INFO> *head;
	Node<INFO> *tail;

public:
	List() {
		head = tail = nullptr;
	}

	/*bool isEmpty() {
		if (head == nullptr)
			return true;
		return false;
	}*/
};