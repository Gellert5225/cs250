/*
	Name header
*/

#include "DoublyList.h"

// createAList
void DoublyList::createAList()
{
	/*
		NOTE:
			
			* You will need to declare one pointer and 
			  you may re-use this pointer throughout the function, but
			  you are NOT allowed to create additional pointers.

			* DO NOT REMOVE EXISTING COMMENTS.

			* Pay CLOSE attention to instructions.
	*/

	/*----------------------------------------------------------------
	SECTION 1
	------------------------------------------------------------------*/

	// Create a node that stores the value 2 and make 
	// this node be the first node of the calling object.
	// List becomes: 2
	// Use the overloaded constructor.
	Node* node = new Node(2, nullptr, nullptr);
	first = node;
	last = node;
	count++;
	// Update count;

	cout << "Section 1 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 2
	------------------------------------------------------------------*/

	// Create another node that stores the value 3 and 
	// insert this node to the left of the node that is 
	// storing value 2.
	// List becomes: 3 2
	node = new Node(3, nullptr, first);
	first->setPrev(node);
	first = node;
	
	// Update count;
	count++;

	cout << "\n\nSection 2 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 3
	------------------------------------------------------------------*/

	// Create another node that stores the value 4 and
	// insert this node to the right of the node that is
	// storing value 3.
	// List becomes: 3 4 2
	// NO MORE than 3 statements.
	node = new Node(4, first, last);
	first->setNext(node);
	last->setPrev(node);

	// Update count;
	count++;

	cout << "\n\nSection 3 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 4
	------------------------------------------------------------------*/

	// Delete the first node.
	// List becomes: 4 2
	node = first;
	first = first->getNext();
	first->setPrev(nullptr);

	// Update count.
	count--;

	cout << "\n\nSection 4 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 5
	------------------------------------------------------------------*/

	// Insert three nodes at the end of the list storing 
	// 5 6 7 in this order.
	// List becomes: 4 2 5 6 7
	for (int i = 5; i < 8; i++) {
		node = new Node(i, last, nullptr);
		last->setNext(node);
		last = node;
	}
		
	// Update count.
	// One statement only.
	count += 3;

	cout << "\n\nSection 5 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 6
	------------------------------------------------------------------*/

	// Move last node to second position.
	// Here steps are very important. Carefully think 
	// how you can move nodes around without losing any
	// nodes and keeping all pointers pointing to the
	// correct nodes.
	// Note: 
	//		You may NOT create an additional node.
	//		NO loops are necessary.
	// List is 4 2 5 6 7 => will become 4 7 2 5 6
	
	last = last->getPrev();
	last->getNext()->setPrev(first);
	last->getNext()->setNext(first->getNext());

	first->getNext()->setPrev(last->getNext());
	first->setNext(last->getNext());
	last->setNext(nullptr);

	cout << "\n\nSection 6 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 7
	------------------------------------------------------------------*/
	
	// Move the first node in between the node before last and
	// last node (the second node will become the first node
	// in the list, and the first node will become the before-last 
	// node in the list).
	//		You may NOT create an additional node.
	//		No loops are necessary.
	// List is 4 7 2 5 6 => will become 7 2 5 4 6
	first = first->getNext();
	first->getPrev()->setNext(last);
	first->getPrev()->setPrev(last->getPrev());

	last->getPrev()->setNext(first->getPrev());
	last->setPrev(first->getPrev());
	first->setPrev(nullptr);
	
	cout << "\n\nSection 7 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 8
	------------------------------------------------------------------*/

	// WITHOUT moving any nodes, swap around the values to 
	// create an ordered list. 
	// Note that there is no need to move the value 5.
	// You may declare an int, BUT do NOT use any literals.
	// List will become: 2 4 5 6 7
	int temp = first->getData();
	first->setData(first->getNext()->getData());
	first->getNext()->setData(last->getData());
	last->setData(temp);

	temp = first->getNext()->getData();
	first->getNext()->setData(last->getPrev()->getData());
	last->getPrev()->setData(temp);
	
	cout << "\n\nSection 8 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 9
	------------------------------------------------------------------*/

	// Add two nodes storing 1 and 3 to complete the ordered list.
	// List becomes: 1 2 3 4 5 6 7
	node = new Node(1, nullptr, first);
	first->setPrev(node);
	first = node;
	
	node = new Node(3, first->getNext(), first->getNext()->getNext());
	first->getNext()->getNext()->setPrev(node);
	first->getNext()->setNext(node);
	
	// Add 2 to count.
	count += 2;

	cout << "\n\nSection 9 - TEST ALL" << endl;
	testAll();

}