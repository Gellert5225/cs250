/*
	Li, Gellert
	Wegener, Brian

	Team: memoryLeak

	CS A250
	March 4, 2018
	Project 1 (Part D) - Final Results
*/


#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Node
{
public:
	Node() : link(nullptr) {}
    Node(const CandidateType& votes, Node *theLink) 
		: candidate(votes), link(theLink){}
    Node* getLink( ) const { return link; }
	CandidateType getCandidate( ) const { return candidate; }
    void setCandidate(const CandidateType& votes) { candidate = votes; }
    void setLink(Node *theLink) { link = theLink; }
	~Node() {}
private:
    CandidateType candidate;
    Node *link;		//pointer that points to next node
};

class CandidateList
{
	friend Node* sort(CandidateList &list);
	friend Node* getMax(CandidateList &list);
public:
	// default constructor
	CandidateList();

	// member functions
	void addCandidate(const CandidateType &candidate);
	int getWinner() const;
	bool searchCandidate(int ssn) const;
	void printCandidateName(int ssn) const;
	void printAllCandidates() const;
	void printCandidateDivisionVotes(int ssn, int division) const;
	void printCandidateTotalVotes(int ssn) const;
	void destroyList();
	void printFinalResults();

	// destructor
	~CandidateList();

private:
	Node *first; 	// pointer to point to the first candidate in the list
	Node *last;		// pointer to point to last candidate in the list
	int count;		// keeps track of number of candidates in the list
	bool searchCandidate(int ssn, Node* &candidate) const;
};

#endif
