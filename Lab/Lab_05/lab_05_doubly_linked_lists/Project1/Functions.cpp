/*
	Name header
*/

#include "DoublyList.h"

void DoublyList::print() const {
	Node *current = first;
	while (current != nullptr) {
		cout << current->getData() << endl;
		current = current->getNext();
	}
}

void DoublyList::reversePrint() const {
	Node *current = last;
	while (current != nullptr) {
		cout << current->getData() << endl;
		current = current->getPrev();
	}
}

int DoublyList::front() const {
	return first->getData();
}

int DoublyList::back() const {
	return last->getData();
}

void DoublyList::copyToList(DoublyList& list) const {
	Node *current = last;
	while (current != nullptr) {
		list.insertFront(current->getData());
		current = current->getPrev();
	}
}

void DoublyList::insertInOrder(const int element) {
	if (isEmpty()) {
		cout << "EMPTY" << endl;
		insertFront(element);
		count++;
	} else {
		Node *current = first;
		bool done = false;
		while (!done) {
			if (current->getData() > element) {
				Node *newNode = new Node(element, current, current->getNext());
				current->getNext()->setPrev(newNode);
				current->setNext(newNode);
				done = true;
				count++;
			}
			current = current->getNext();
		}
	}
}