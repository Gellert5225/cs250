/*
	Li, Gellert

	CS A250
	10th February, 2018

	Lab 3 Linked Lists
*/

#include "AnyList.h"

//Declaration function search
bool AnyList::search(int element) {
	if (this->count == 0) cerr << "The list is empty" << endl;
	Node *n = this->ptrToFirst;
	while (n != nullptr) {
		int data = n->getData();
		if (element == data) return true;
		n = n->getPtrToNext();
	}

	return false;
}

//Definition function commonEnds
bool AnyList::commonEnds(AnyList &list) {
	int last1, last2;

	Node *n1 = this->ptrToFirst;
	Node *n2 = list.ptrToFirst;

	while (n1 != nullptr) {
		last1 = n1->getData();
		n1 = n1->getPtrToNext();
	}

	while (n2 != nullptr) {
		last2 = n2->getData();
		n2 = n2->getPtrToNext();
	}

	return last1 == last2 && this->ptrToFirst->getData() == list.ptrToFirst->getData();
}
