
/*
	Li, Gellert

	CS A250
	March 14, 2018
	The Big Three
*/

/*
	After you completed the implementation, answer the following questions.

	1) Why are the parameter lists in the testCopyConstructor and 
	   testOverloadedAssignment functions passed by VALUE and not reference?
	   
	   Answer: Because we want to preserver oringinal list


	2) When the function testOverloadedAssignment is called, why is it being 
	   re-directed to the copy constructor instead of the overloaded assignment 
	   operator?  

	   Answer: 


	3) The first testing case for the overloaded assignment operator compares 
	   a list to itself (line 6). Shouldn't an error message be displayed? 
	   Why is it not displaying?

	   Answer: Because both param are passed by value(a copy), therefore they have different memory address even they have same identifier


*/

#include "DoublyList.h"

// overloaded insertion operator
ostream& operator<<(ostream &out, const DoublyList &list) {
	if (list.count == 0) out << "List is empty";
	else {
		Node *node = list.first;
		while (node != nullptr) {
			out << node->getData() << " ";
			node = node->getNext();
		} 
	}

	return out;
}

// copy constructor
DoublyList::DoublyList(const DoublyList &otherList) {
	Node *node = otherList.first;
	first = nullptr;
	last = nullptr;
	count = 0;
	while (node != nullptr) {
		insertBack(node->getData());
		node = node->getNext();
	}
}


// overloaded assignment operator
DoublyList& DoublyList::operator=(const DoublyList &list) {
	if (&list == this) {
		cerr << "Attempted assignment to itself";
	} else if (count == 0) {
		Node *node = list.first;
		while (node != nullptr) {
			insertBack(node->getData());
			node = node->getNext();
		}
	} else if (list.count == 0) {
		destroyList();
	} else if (count > list.count) {
		Node *node = list.first;
		Node *originalNode = first;
		while (node != nullptr) {
			originalNode->setData(node->getData());
			node = node->getNext();
			originalNode = originalNode->getNext();
		}

		originalNode->getPrev()->setNext(nullptr);
		Node *temp = originalNode;
		last = originalNode->getPrev();
		while (temp != nullptr) {
			temp = temp->getNext();
			delete originalNode;
			originalNode = temp;
		}
		
	} else if (count == list.count) {
		Node *node = list.first;
		Node *originalNode = first;
		while (node != nullptr) {
			originalNode->setData(node->getData());
			node = node->getNext();
			originalNode = originalNode->getNext();
		}
	} else if (count < list.count) {
		Node *node = list.first;
		Node *originalNode = first;
		while (node->getNext() != nullptr) {
			originalNode->setData(node->getData());
			originalNode = originalNode->getNext();
			node = node->getNext();
			if (originalNode == nullptr && node != nullptr) {
				insertBack(node->getData());
				originalNode = last;
			}
		}
	}
	count = list.count;
	return *this;
}