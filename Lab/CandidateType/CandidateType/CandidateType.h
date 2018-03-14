/*
	Li, Gellert & Wegener, Brian
	Team: memoryLeak

	CS A250
	March 7, 2018
	Candidate Type
*/

#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "PersonType.h"

const int NUM_OF_DIVISIONS = 4;

class CandidateType : public PersonType {
public:
	CandidateType();

	void updateVotesByDivision(int divisionNumber, int numVotes);

	int getTotalVotes() const;

	int getVotesByDivision(int divisionNumber) const;

	void printCandidateInfo() const;

	void printCandidateTotalVotes() const;

	void printCandidateDivisionVotes(int divisionNumber) const;

	~CandidateType();

 private:
	int numberOfVotes;
	int divisions[NUM_OF_DIVISIONS] = {0};
};

#endif // !CANDIDATETYPE_H
