#ifndef TESTING_H
#define TESTING_H

#include <iostream>
#include <vector>
using namespace std;

vector< vector<int>> v = { { },
{ 1 },
{ 3 },
{ 5, 3 },
{ 7, 4 },
{ 5, 3, 1, 7 },
{ 4, 2, 7, 4 },
{ 8, 4, 2, 6, 7, 8, 2 },
{ 9, 8, 5, 6, 3, 2, 1, 4 },
{ 1, 6, 4, 8, 9, 0, 7, 5, 2, 3 },
{ 4, 6, 2}, 
{ 0, 1, 2, 3, 4, 5, 6 ,7 ,8, 9 } };

int indices[] = { 0, 0, 1, 1, 2, 4, 5, 7, 8, 10, 20, 5 };

void printArray(const int a[], int numOfElements)
{
	if (numOfElements == 0)
		cout << "No elements in the array.";
	else
		for (int i = 0; i < numOfElements; ++i)
			cout << a[i] << " ";
}

void testing(int i)
{
	int a[CAPACITY];
	int numOfElem = static_cast<int>(v[i].size());
	for (int j = 0; j < numOfElem; ++j)
		a[j] = v[i].at(j);
	cout << "Initial Array: ";
	printArray(a, numOfElem);
	cout << endl;
	int elem = (i + 1) * 10;
	cout << "Insert " << elem << " at idx " << indices[i] << "...\nModified array: ";
	insertAtIndex(a, numOfElem, elem, indices[i]);	
	printArray(a, numOfElem);
	cout << "\n--------------------------------------------------------\n";
}
void testCases()
{
	int vectorSize = static_cast<int>(v.size());

	for (int i = 0; i < vectorSize; ++i)
	{
		testing(i);
	}
}

#endif

