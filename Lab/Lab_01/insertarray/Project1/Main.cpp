/*
	Li, Gellert

	CS A250
	February 7, 2018

	Lab 1: Array Insertion
*/

#include <iostream>
using namespace std;

const int CAPACITY = 10;

// Declaration function insertAtIndex
// Your code here...
void insertAtIndex(int arr[], int &numberOfElements, int element, int index);

#include "Testing.hxx"

int main() {
	testCases();

	cout << endl;
	system("Pause");
    return 0;
}

// Definition function insertAtIndex
// Your code here...
void insertAtIndex(int arr[], int &numberOfElements, int element, int index) {
	if (index > CAPACITY) {
		cerr << "The array cannot have more than 10 element." << endl;
	} else if (index > numberOfElements) {
		cerr << "You can only insert contiguous elements in the array." << endl;
	} else {
		if (numberOfElements < CAPACITY) {
			int temp;
			numberOfElements++;
			for (int i = 0; i < numberOfElements; i++) {
				if (i == index) {
					temp = arr[i];
					arr[i] = element;
				} else if (i > index) {
					arr[i] = temp;
				}
			}
		} else {
			cerr << "Array is full. Cannot insert another element." << endl;
		}
	}

}
