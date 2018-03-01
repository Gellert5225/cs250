/*
	Li, Gellert & Wegener, Brian
	Team: memoryLeak

	CS A250
	February 28th, 2018

	Lab 5: Doubly-linked Lists
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

// traverse from beginning and the end
void DoublyList::insertInOrder(const int element) {
	if (isEmpty() || first->getData() > element) insertFront(element);
	else if (last->getData() < element) {
		Node *newNode = new Node(element, last, nullptr);
		last->setNext(newNode);
		last = newNode;
	} else {
		Node *begin = first;
		Node *end = last;
		bool done = false;

		while (!done) {
			if (begin->getData() > element) {
				Node *newNode = new Node(element, begin->getPrev(), begin);
				begin->getPrev()->setNext(newNode);
				begin->setPrev(newNode);
				done = true;
			} else if (end->getData() < element) {
				Node *newNode = new Node(element, end, end->getNext());
				end->setNext(newNode);
				end->getNext()->setPrev(newNode);
				done = true;
			}
			begin = begin->getNext();
			end = end->getPrev();
		}
	}
	count++;
}

// old way(not efficient)
void DoublyList::insertInOrder2(const int element) {
	if (isEmpty() || first->getData() > element) insertFront(element);
	else if (last->getData() < element) {
		Node *newNode = new Node(element, last, nullptr);
		last->setNext(newNode);
		last = newNode;
	} else {
		Node *current = first;
		bool done = false;
		while (!done) {
			if (current->getData() > element) {
				Node *newNode = new Node(element, current->getPrev(), current);
				current->getPrev()->setNext(newNode);
				current->setPrev(newNode);
				done = true;
			}
			current = current->getNext();
		}
	}
	count++;
}