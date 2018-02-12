#include "AnyList.h"

#include <iostream>
using namespace std;

int main()
{
	/******************************************
		A very short list of test cases.

		Modify the test cases to try 
		different lists.
	******************************************/
	
	AnyList myList;
	myList.insertFront(4);
	myList.insertFront(3);
	myList.insertFront(2);

	cout << "My list: ";
	myList.print();

	cout << ((myList.search(4)) ? "\nElement 4 found." : "\nElement 4 not found.");
	cout << ((myList.search(100)) ? "\nElement 100 found." : "\nElement 100 not found.");
	cout << endl;

	AnyList yourList;
	yourList.insertFront(4);
	yourList.insertFront(30);
	yourList.insertFront(20);

	cout << "\nYour list: ";
	yourList.print();

	cout << "\nCommon ends? ";
	cout << ((myList.commonEnds(yourList)) ? "Yes." : "No.");
	cout << endl;
	
	cout << endl;
	system("Pause");
	return 0;
}

