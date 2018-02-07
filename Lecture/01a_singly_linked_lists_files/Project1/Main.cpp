#include "AnyList.h"

#include <iostream>
using namespace std;

int main()
{
	AnyList myList;

	myList.insertFront(2);
	myList.insertFront(3);
	myList.insertFront(4);
	myList.insertFront(5);
	myList.insertFront(6);

	cout << "Inserted: 2 3 4 5 6\n";
	cout << "List is: ";
	myList.print();
	cout << endl;
	
	myList.destroyList(); // the list object still exists, 
						  // but the list is empty.

	cout << "\nPrint the list after emptying it...";
	cout << "\nList is: ";
	myList.print();
	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}
