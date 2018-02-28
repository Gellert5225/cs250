/*
	Name header
*/

#include "DoublyList.h"

void DoublyList::print() const {
	Node *current = first;
	while (current != nullptr) {
		cout << current->getData() << "  ";
		current = current->getNext();
	}
}

void DoublyList::reversePrint() const {
	Node *current = last;
	while (current != nullptr) {
		cout << current->getData() << "  ";
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
		if (first->getData() > element) {
			insertFront(element);
			count++;
		} else {
			Node *current = first;
			bool done = false;
			while (!done) {
				if (current->getData() > element) {
					Node *newNode = new Node(element, current->getPrev(), current);
					current->getPrev()->setNext(newNode);
					current->setPrev(newNode);
					done = true;
					count++;
				} else if (current->getNext() == nullptr) { // insert last
					Node *newNode = new Node(element, current, nullptr);
					current->setNext(newNode);
					last = newNode;
					count++;
					done = true;
				}
				current = current->getNext();
			}
		}
		
	}
}