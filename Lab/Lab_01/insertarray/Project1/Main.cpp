/*
	(name header)
*/

#include <iostream>
using namespace std;

const int CAPACITY = 10;

// Declaration function insertAtIndex
// Your code here...
void insertAtIndex(int arr[], int &size, int element, int index);

#include "Testing.hxx"

int main() {
	testCases();

	cout << endl;
	system("Pause");
    return 0;
}

// Definition function insertAtIndex
// Your code here...
void insertAtIndex(int arr[], int &size, int element, int index) {
	if (index > CAPACITY) {
		cerr << "The array cannot have more than 10 element." << endl;
	} else if (index > size) {
		cerr << "You can only insert contiguous elements in the array." << endl;
	} else {
		if (size < CAPACITY) {
			int temp;
			size++;
			for (int i = 0; i < size; i++) {
				if (i < index) {
					//temp[i] = arr[i];
				} else if (i == index) {
					temp = arr[i];
					arr[i] = element;
				} else {
					arr[i] = temp;
				}
			}
		} else {
			cerr << "Array is full. Cannot insert another element." << endl;
		}
	}

}
