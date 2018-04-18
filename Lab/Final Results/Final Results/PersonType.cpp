/*
	Li, Gellert
	Wegener, Brian

	Team: memoryLeak

	CS A250
	March 4, 2018
	Project 1 (Part D) - Final Results
*/

#include "PersonType.h"

PersonType::PersonType() {
	socialSecurity = 0;
}

PersonType::PersonType(const string &newFirstName, const string &newLastName, int newSocialSecurity) {
	firstName = newFirstName;
	lastName = newLastName;
	socialSecurity = newSocialSecurity;
}

void PersonType::setPersonInfo(const string& newFirstName, const string& newLastName, int newSocialSecurity) {
	firstName = newFirstName;
	lastName = newLastName;
	socialSecurity = newSocialSecurity;
}

string PersonType::getFirstName() const {
	return firstName;
}

string PersonType::getLastName() const {
	return lastName;
}

int PersonType::getSSN() const {
	return socialSecurity;
}

void PersonType::printName() const {
	cout << lastName << ", " << firstName;
}

void PersonType::printPersonInfo() const {
	cout << printSSN() << " - " << lastName << ", " << firstName << endl;
}

string PersonType::printSSN() const {
	
	int thirdPart = socialSecurity % 10000;
	int secondPart = socialSecurity / 10000 % 100;
	int firstPart = socialSecurity / 1000000;

	return to_string(firstPart) + "-" + to_string(secondPart) + "-" + to_string(thirdPart);
}

PersonType::~PersonType() {}