/*
	Li, Gellert

	CS A250
	18th April, 2018

	Lab 10: DArray Class
*/

#include "DArray.h"

#include <iostream>
using namespace std;

bool operator==(DArray& d1, DArray& d2);

int main()
{
	cout << "TEST 1 ------------------------\n\n";
	DArray a1;
	cout << "Array 1: Empty array with capacity 50\n";
	cout << "\nYour results:\n";
	cout << "\tCapacity: " << a1.getCapacity() << endl;
	cout << "\tNumber of elements: " << a1.getNumOfElem() << endl;
	cout << "\tEmpty? " << (a1.isEmpty() ? "True" : "False") << endl;
	cout << "\tFull? " << (a1.isFull() ? "True" : "False") << endl;

	cout << endl;

	cout << "\nTEST 2 ------------------------\n\n";
	DArray a2(5);
	cout << "Array 2: 3, with capacity 5\n";
	cout << "\nYour results:\n";
	a2.addElement(3);
	cout << "\tArray is: " << a2 << endl;
	cout << "\tCapacity: " << a2.getCapacity() << endl;
	cout << "\tNumber of elements: " << a2.getNumOfElem() << endl;
	cout << "\tEmpty? " << (a2.isEmpty() ? "True" : "False") << endl;
	cout << "\tFull? " << (a2.isFull() ? "True" : "False") << endl;
	cout << "\tElement at idx 0: " << a2[0] << endl;
	cout << "\tSearch for 3: ";
	cout << ((a2.search(3)) ? "Found.\n" : "Not found.\n");
	cout << "\tEmpty the array..." << endl;
	a2.emptyArray();
	cout << "\tEmpty? " << (a2.isEmpty() ? "True" : "False") << endl;
		
	cout << endl;

	cout << "\nTEST 3 ------------------------\n\n";
	cout << "Re-populate..." << endl;
	cout << "Array 2 is now: 21 53 64 19 43, with same capacity 5\n";
	cout << "\nYour results:\n";
	a2.addElement(21);
	a2.addElement(53);
	a2.addElement(64);
	a2.addElement(19);
	a2.addElement(43);
	cout << "\tArray is: " << a2 << endl;
	cout << "\tCapacity: " << a2.getCapacity() << endl;
	cout << "\tNumber of elements: " << a2.getNumOfElem() << endl;
	cout << "\tEmpty? " << (a2.isEmpty() ? "True." : "False") << endl;
	cout << "\tFull? " << (a2.isFull() ? "True" : "False") << endl;
	cout << "\tElement at last index: " << a2[a2.getNumOfElem() - 1] << endl;
	cout << "\tDelete first element..." << endl;
	a2.deleteElement(21);
	cout << "\tAfter deletion: " << a2 << endl;
	cout << "\tDelete last element..." << endl;
	a2.deleteElement(43);
	cout << "\tAfter deletion: " << a2 << endl;
	cout << "\tNumber of elements: " << a2.getNumOfElem() << endl;
	cout << "\tEmpty? " << (a2.isEmpty() ? "True" : "False") << endl;
	cout << "\tFull? " << (a2.isFull() ? "True" : "False") << endl;
	cout << "\tSearch for 53: ";
	cout << ((a2.search(53)) ? "Found.\n" : "Not found.\n");
	cout << "\tSearch for 19: ";
	cout << ((a2.search(19)) ? "Found.\n" : "Not found.\n");
	cout << "\tSearch for 100: ";
	cout << ((a2.search(100)) ? "Found.\n" : "Not found.\n");
	cout << "\tElement at last index: " << a2[a2.getNumOfElem() - 1] << endl;
	cout << "\tDelete remaining elements..." << endl;
	a2.deleteElement(64);
	a2.deleteElement(53);
	a2.deleteElement(19);
	cout << "\tNumber of elements: " << a2.getNumOfElem() << endl;

	cout << endl;
	system("Pause");
    return 0;
}

bool operator==(DArray& d1, DArray& d2)
{
	if (d1.getNumOfElem() != d2.getNumOfElem())
		return false;
	else
	{
		int i = 0;
		int numOfElem = d1.getNumOfElem();
		while (i < numOfElem)
		{
			if (d1[i] != d2[i])
				return false;
			++i;
		}

		return true;
	}
}