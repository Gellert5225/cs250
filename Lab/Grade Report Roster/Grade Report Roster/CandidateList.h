/*
	Li, Gellert
	Wegener, Brian

	Team: memoryLeak

	CS A250

	May 13th, 2018
	Project 2 - Grade Repoprt Roster
*/


#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class CandidateList
{
public:
	// default constructor
	CandidateList();
	// copy constructor
	CandidateList(const CandidateList& otherList);

	// member functions
	void addCandidate(const CandidateType &candidate) const;
	int getWinner() const;
	bool searchCandidate(int ssn) const;
	bool isEmpty() const;
	void printCandidateName(int ssn) const;
	void printAllCandidates() const;
	void printCandidateDivisionVotes(int ssn, int division) const;
	void printCandidateTotalVotes(int ssn) const;

	// destructor
	~CandidateList();

	CandidateList& operator=(const CandidateList& otherList);

private:
	vector<CandidateType> *candidates;
	int count;		// keeps track of number of candidates in the list
	bool searchCandidate(int ssn, vector<CandidateType>::const_iterator &candidate) const;
};

#endif
