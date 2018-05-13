/*
	memoryLeak

	Li, Gellert
	Wegener, Brian

	CS A250

	May 6th, 2018
	Project 2 - STL Candidate List
*/

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>

using namespace std;

class PersonType
{
public:
	PersonType();

	PersonType(const string& newFirstName, const string& newLastName, int newSocialSecurity);

	void setPersonInfo(const string& newFirstName, const string& newLastName, int newSocialSecurity);

	string getFirstName() const;

	string getLastName() const;

	int getSSN() const;

	void printName() const;

	void printPersonInfo() const;

	string printSSN() const;

	~PersonType();

private:
	string firstName;
	string lastName;
	int socialSecurity;
	
};

#endif