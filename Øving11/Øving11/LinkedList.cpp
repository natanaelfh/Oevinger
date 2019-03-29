#include "LinkedList.h"
using namespace std;

LinkedList::Node * LinkedList::LinkedList::insert(Node * pos, const std::string & value)
{
	//if (this->isEmpty() == false) {
	//	//lag en ny node som har pos som next og prev som prev til pos

	//	//Node mynode(value, (move(pos->next)), pos->getPrev());
	//	pos->next = make_unique<Node>(value, (move(pos->next)), pos);
	//	pos->prev = pos->getPrev();

	//	return pos->next.get();
	//}
	//else {
	//	//pos->next = make_unique<Node>(value, this->head, this->tail);


	//	pos->next = make_unique<Node>(value, (move(head)), nullptr);
	//	return pos->next.get();
	//}
	if (pos == head.get()) {
		head = make_unique<Node>(value, move(head), nullptr);
		pos->prev = head.get();
	}
	else {
		Node * prev = pos->getPrev();
		prev->next = make_unique<Node>(value, move(prev->next), prev);
		pos->prev = prev->next.get();
	}
	return pos->prev;
}

std::ostream & LinkedList::operator<<(std::ostream & os, const Node & node)
{
	os << node.getValue();
	return os;
}

std::ostream & LinkedList::operator<<(std::ostream & os, const LinkedList & list)
{

	const Node* currentNode{list.begin()};
	while (true) {
		if (currentNode != list.end()) {
			os << *currentNode << endl;

			currentNode = currentNode->getNext();
		}
		else {
			break;
		}
	}
	return os;
}

LinkedList::Node * LinkedList::LinkedList::remove(Node* pos) {
	if (pos != this->begin()) {
		pos->next->prev = pos->prev;
		pos->prev->next = move(pos->next);
	}
	else {
		if (pos == this->end()) {
		pos
		}
		pos->next->prev = nullptr;
		head = move(pos->next);
	}
	return pos->prev;
}


void testLinkedList() {
	LinkedList::LinkedList list{};
	list.insert(list.end(),"ok");
	LinkedList::Node* p = list.insert(list.end(),"nexxxl");
	list.insert(list.end(), "1");
	list.insert(p, "2");
	list.insert(list.end(), "3");
	list.insert(list.end(), "4");

	list.remove(list.end());


	cout << list;
}

