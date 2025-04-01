#include <iostream>
#include <string>

/*
	delete, search by value, search by index는 구현하지 않음
	매우 기초적인 형태의 단방향 연결 리스트
*/

template<typename T>
struct Node {
	T data{};
	Node* next_node = nullptr;
};

template<typename T>
class SinglyLinkedList {
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
public:
	void add_first(Node<T>* node) {
		if (head == nullptr) {
			head = node;
			tail = node;
			return;
		}
		node->next_node = head;
		head = node;
	}

	void add_last(Node<T>* node) {
		if (head == nullptr) {
			add_first(node);
			return;
		}
		Node<T>* n = head;
		while (n->next_node != nullptr) {
			n = n->next_node;
		}
		n->next_node = node;
		tail = node;
	}

	std::string to_string() {
		std::string str = "[";
		Node<T>* n = head;
		while (n != nullptr) {
			str += std::to_string(n->data);
			if (n->next_node != nullptr) { str += ", "; }
			n = n->next_node;
		}
		str.append("]");
		return str;
	}
};

int main()
{
	SinglyLinkedList<int> singly_linked_list{};
	Node<int> node1{};
	Node<int> node2{};
	Node<int> node3{};
	Node<int> node4{};
	node1.data = 1;
	node1.next_node = &node2;
	node2.data = 2;
	node2.next_node = &node3;
	node3.data = 3;
	node3.next_node = &node4;
	node4.data = 4;

	Node<int> node5{};
	node5.data = 5;
	singly_linked_list.add_last(&node1);
	singly_linked_list.add_last(&node5);
	std::cout << singly_linked_list.to_string() << std::endl;
	return 0;
}
