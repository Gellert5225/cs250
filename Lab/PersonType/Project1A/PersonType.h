/*
Li, Gellert & Wegener, Brian
Team...

CS A250
February 21, 2018

Project 1 (Part A): PersonType Class
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

	void setPersonInfo(const string& newFirstName, const string& newLastName, const int newSocialSecurity);

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