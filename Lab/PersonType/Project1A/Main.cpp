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

	/* NEED TO HANDLE THE CASE WHERE SSN STARTS WITH 0 */

	// defualt constructor

	// overloaded constructor
	PersonType *person = new PersonType("Gellert", "Li", 123456789);
	person->printPersonInfo();

	// test accessors and mutators
	PersonType john;
	john.setPersonInfo("John", "Smith", 100000001);
	cout << john.getSSN();

	cout << endl;
	system("Pause");
	return 0;
}