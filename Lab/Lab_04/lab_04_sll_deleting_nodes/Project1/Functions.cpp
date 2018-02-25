/*
	Li, Gellert

	CS A250
	February 24, 2018

	Lab 4: Delete Node
*/

#include "AnyList.h"

//deleteNode
void AnyList::deleteNode(int deleteData) {
	/*
		PSEUDOCODE:

		IF the list is emtpy
			print an error message, "Cannot delete from an empty list."

		ELSE
			Create pointer current to traverse the list, and start by
			pointing it to the first node.
			Set a Boolean value to keep track of whether the item is found 
			or not.

			IF the node to be deleted is the first node in the list
				Connect the list object to the second node in the list.
				Delete the first node.
				Set current to NULL.
				Decrement the count.
				Set the Boolean value to true (you found the node to delete).
			ELSE (keep searching the list)
				Create a pointer trailCurrent to point to the first node
				(you already know that the first node is not the one that 
				 needs to be deleted.)
				Make pointer current point to the second node.

				WHILE there are still nodes to check and the node has not been found
					IF the node is found
						Connect the node to which trailCurrent is pointing
						to the node after the node current is pointing to.
						(This would work also if current is pointing to the last node. Why?)
						Delete the node current is pointing to.
						Re-set both current and trailCurrent to NULL.
						Decrement the count.
						Set the Boolean value to true (you found the node to delete).
					ELSE
						Move trailCurrent and current forward.

			IF the node is not found
				print out the error message, "Item to be deleted is not in the list." 
	*/

	// Write your code here...
	if (count == 0) std::cerr << "Cannot delete from an empty list." << std::endl;
	else {
		Node *current = ptrToFirst;
		bool found = false;

		if (current->getData() == deleteData) {
			ptrToFirst = current->getPtrToNext();
			delete current;
			current = nullptr;
			count--;
			found = true;
		} else {
			Node *trailCurrent = ptrToFirst;
			current = trailCurrent->getPtrToNext();

			while (current != nullptr && !found) {
				if (current->getData() == deleteData) {
					trailCurrent->setPtrToNext(current->getPtrToNext());
					delete current;
					current = nullptr;
					trailCurrent = nullptr;
					count--;
					found = true;
				} else {
					trailCurrent = current;
					current = current->getPtrToNext();
				}
			}

			if (!found)	std::cerr << "Item to be deleted is not in the list." << std::endl;
		}
	}

}