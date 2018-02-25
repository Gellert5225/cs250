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
		cerr << "List is empty.";  
	else
	{
		Node *current = ptrToFirst;   

		while (current != nullptr)	
		{						    
			cout << current->getData() << " ";	
			current = current->getPtrToNext();		
		}
	}
}

	//destroyList - Does not delete the list object; it ONLY deletes the nodes.
void AnyList::destroyList()
{ 
    Node  *temp = ptrToFirst; 
	
	while (ptrToFirst != nullptr)
    {
		ptrToFirst = ptrToFirst->getPtrToNext();
        delete temp;
		temp = ptrToFirst;
    }

	count = 0;
}

	//destructor
AnyList::~AnyList()
{
	destroyList();
}