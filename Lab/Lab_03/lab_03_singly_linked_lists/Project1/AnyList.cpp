#include "AnyList.h"

	//constructor
AnyList::AnyList()
{
	ptrToFirst = nullptr;
	count = 0;
}

	//insertFront
void AnyList::insertFront(int newData)
{
	ptrToFirst = new Node(newData, ptrToFirst);

	++count;
}

	//print
void AnyList::print() const
{
	if (ptrToFirst == nullptr)
		cerr << "List is empty." << endl;
	else
	{
		Node *current;	//create a pointer to traverse the list 
		current = ptrToFirst;	//set the current pointer to point to the first node

		while (current != nullptr)	//while the current pointer is not pointing to NULL
		{						//  that is, the current pointer has not reached the 
			//  end of the list
			cout << current->getData() << " ";	//output the data 
			current = current->getPtrToNext();		//move the current pointer forward
		}
	}
}

	//destroyList
void AnyList::destroyList()
{ 
    Node  *temp; //pointer to delete the node
	
	while (ptrToFirst != nullptr)
    {
		temp = ptrToFirst;
		ptrToFirst = ptrToFirst->getPtrToNext();
        delete temp;
		temp = nullptr;
    }

	count = 0;
}

	//destructor
AnyList::~AnyList()
{
	destroyList();
}