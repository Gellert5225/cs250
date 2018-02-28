/*
	Li, Gellert & Wegener, Brian
	memoryLeak

	CS A250
	February 21, 2018

	Project 1 (Part A): PersonType Class
*/

#include "PersonType.h"

#include <iostream>
#include <string>
using namespace std;

int main() {

	// overloaded constructor
	PersonType *person = new PersonType("Gellert", "Li", 123456789);
	person->printPersonInfo();

	// test default constructor, accessors and mutators
	PersonType john;
	john.setPersonInfo("John", "Smith", 100000001);
	john.printPersonInfo();

	cout << endl;
	system("Pause");
	return 0;
}