/***********************************************

	Class DoublyList

************************************************/
/*
	Li, Gellert & Wegener, Brian
	Team: memoryLeak

	CS A250
	February 28th, 2018

	Lab 5: Doubly-linked Lists
*/
#include "DoublyList.h"

#include <iostream>
using namespace std;

int main()
{
	DoublyList intList;

	intList.insertInOrder(37);
	intList.insertInOrder(53);
	intList.insertInOrder(21);
	intList.insertInOrder(18);
	intList.insertInOrder(73);
	intList.insertInOrder(49);
	
	cout << "TESTING: insertInOrder() and print()" 
		<< "\n\nEXPECTED OUTPUT: "
		<< "\nList: 18  21  37  49  53  73\n";
	cout << "\nACTUAL OUTPUT:";
	cout << "\nList: ";
	intList.print();

	cout << "\n\n-----------------------------------------------------\n";
	cout << "TESTING: printReverse()" 
		<< "\n\nEXPECTED OUTPUT: "
		<< "\nList (reversed): 73  53  49  37  21  18\n";
	cout << "\nACTUAL OUTPUT:";
	cout << "\nList (reversed): ";
	intList.reversePrint();

	cout << "\n\n-----------------------------------------------------\n";
	cout << "FINAL TESTING: Check first and last nodes" 
		<< "\n\nEXPECTED OUTPUT: "
		<< "\nFirst node data: 18"
		<< "\nLast node data: 73\n";
	cout << "\nACTUAL OUTPUT:";
	cout << "\nFirst node data: "
		<< intList.front()
		<< "\nLast node data: "
		<< intList.back() << endl;

	intList.destroyList();	
	
	cout << "\nYour testing cases...\n";
	// Create your testing cases here.

	DoublyList mylist;
	mylist.insertInOrder(9);
	mylist.insertInOrder(8);
	mylist.insertInOrder(11);
	mylist.insertInOrder(1);
	mylist.insertInOrder(7);
	mylist.insertInOrder(20);

	mylist.print();
	cout << endl;
	mylist.reversePrint();

	cout << endl << endl;
	system("Pause");
	return 0;
}
