namespace Betyg5 {

	template<class KEY, class VALUE>
	struct Node {
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
	};

	template<class KEY, class VALUE>
	class HashTable {
	private:
		Node<KEY, VALUE> *head;


	public:
		HashTable() {
			head = nullptr;
		}
	};
}