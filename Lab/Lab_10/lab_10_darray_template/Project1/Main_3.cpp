/*
	(name header)
*/


#include "DArray.h"
#include "DArray.cpp"
#include "Movie.h"

#include <iostream>
using namespace std;

template<typename T>
bool operator==(const DArray<T>& d1, const DArray<T>& d2);

int main()
{
	cout << "TEST 1 ------------------------\n\n";
	DArray<int> a1;
	cout << "Array 1: Empty array with capacity 50\n";
	cout << "\nYour results:\n";
	cout << "\tCapacity: " << a1.getCapacity() << endl;
	cout << "\tNumber of elements: " << a1.getNumOfElem() << endl;
	cout << "\tEmpty? " << (a1.isEmpty() ? "True" : "False") << endl;
	cout << "\tFull? " << (a1.isFull() ? "True" : "False") << endl;

	cout << endl;

	cout << "\nTEST 2 ------------------------\n\n";
	DArray<int> a2(5);
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

	cout << "\nTEST 4 ------------------------\n\n";
	cout << "Creating a DArray object of type Movie.\n\n";
	DArray<Movie> movies(4);
	cout << "Array 3: capacity 4\n"
		<< "\tFight Club, 1999\n"
		<< "\tSnatch, 2000\n"
		<< "\tDeadpool, 2016\n"
		<< "\tThe Day After Tomorrow, 2004\n";
	
	Movie m1("Fight Club", 1999);
	Movie m2("Snatch", 2000);
	Movie m3("Deadpool", 2016);
	Movie m4("The Day After Tomorrow", 2004);
	movies.addElement(m1);
	movies.addElement(m2);
	movies.addElement(m3);
	movies.addElement(m4);
	cout << "\nYour results:\n";
	cout << "\tArray is:\n " << movies << endl;
	cout << "\tCapacity: " << movies.getCapacity() << endl;
	cout << "\tNumber of elements: " << movies.getNumOfElem() << endl;
	cout << "\tEmpty? " << (movies.isEmpty() ? "True" : "False") << endl;
	cout << "\tFull? " << (movies.isFull() ? "True" : "False") << endl;
	cout << "\tElement at idx 0: " << movies[0] << endl;

	cout << "\tEmpty the array..." << endl;
	movies.emptyArray();
	cout << "\tEmpty? " << (movies.isEmpty() ? "True" : "False") << endl;

	cout << endl;

	cout << "\nTEST 5 ------------------------\n\n";
	cout << "\nRe-populate in reverse order..." << endl;	
	cout << "Array 3 is now: same capacity 4\n"
		<< "\tThe Day After Tomorrow, 2004\n"
		<< "\tDeadpool, 2016\n"
		<< "\tSnatch, 2000\n"
		<< "\tFight Club, 1999\n";
	cout << "\nYour results:\n";
	movies.addElement(m4);
	movies.addElement(m3);
	movies.addElement(m2);
	movies.addElement(m1);
	cout << "\tArray is:\n " << movies << endl;
	cout << "\tCapacity: " << movies.getCapacity() << endl;
	cout << "\tNumber of elements: " << movies.getNumOfElem() << endl;
	cout << "\tEmpty? " << (movies.isEmpty() ? "True." : "False") << endl;
	cout << "\tFull? " << (movies.isFull() ? "True" : "False") << endl;
	cout << "\tElement at last index: " << movies[movies.getNumOfElem() - 1] << endl;

	cout << "\tDelete first element..." << endl;
	movies.deleteElement(m4);

	cout << "\tAfter deletion:\n " << movies << endl;

	cout << "\tDelete last element..." << endl;
	movies.deleteElement(m1);

	cout << "\tArray is:\n " << movies << endl;
	cout << "\tNumber of elements: " << movies.getNumOfElem() << endl;
	cout << "\tEmpty? " << (movies.isEmpty() ? "True" : "False") << endl;
	cout << "\tFull? " << (movies.isFull() ? "True" : "False") << endl;
	cout << "\tElement at last index: " << movies[movies.getNumOfElem() - 1] << endl;
	cout << "\tDelete remaining elements..." << endl;
	movies.deleteElement(m2);
	movies.deleteElement(m3);
	cout << "\tNumber of elements: " << movies.getNumOfElem() << endl;

	cout << endl;
	system("Pause");
    return 0;
}

template<typename T>
bool operator==(const DArray<T>& d1, const DArray<T>& d2)
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