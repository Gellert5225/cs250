#include "DoublyList.h"

	// constructor
DoublyList::DoublyList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

	// destructor
DoublyList::~DoublyList()
{
	destroyList();
}

	// insertFront
void DoublyList::insertFront(int newData)
{
	Node *newNode = new Node(newData, nullptr, first);

	if(first == nullptr) 
    {
       first = newNode;		//set "first" to be the new node
       last = newNode;		//set "last" to be the new node
    }
    else
	{
        first->setPrev(newNode);	//make first's previous link point to the new node
		first = newNode;			//set "first" to the the new node
	}

	++count;
}

// isEmpty
bool DoublyList::isEmpty() const
{
	return (first == nullptr);
}

	// destroyList
void DoublyList::destroyList()
{ 	
    while (first != nullptr)
    {
        Node  *temp = first;
        first = first->getNext();
        delete temp;
		temp = nullptr;
    }

    last = nullptr;
	count = 0;
}
