/*
	Li, Gellert & Wegener, Brian

	Team: memoryLeak

	CS A250
	March 14, 2018
	Candidate List
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
	cout << printSSN() << " " << lastName << ", " << firstName << endl;
}

string PersonType::printSSN() const {
	string ssn = std::to_string(socialSecurity);

	if (static_cast<int>(ssn.size()) == 9) {
		return ssn.substr(0, 3) + "-" + ssn.substr(3, 2) + "-" + ssn.substr(5);
	} else {
		cerr << "SSN must have 9 digits." << endl;
		return "Invalid SSN";
	}
}

PersonType::~PersonType() {}