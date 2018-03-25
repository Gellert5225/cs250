/*
	Li, Gellert & Wegener, Brian

	Team: memoryLeak

	CS A250
	March 14, 2018
	Candidate List
*/

#include "CandidateType.h"

CandidateType::CandidateType() 
:PersonType() {
	numberOfVotes = 0;
}

void CandidateType::updateVotesByDivision(int divisionNumber, int numVotes) {
	divisions[divisionNumber] = numVotes;
	this->numberOfVotes += numVotes;
}

int CandidateType::getTotalVotes() const {
	return numberOfVotes;
}

int CandidateType::getVotesByDivision(int divisionNumber) const {
	return divisions[divisionNumber - 1];
}

void CandidateType::printCandidateInfo() const {
	printPersonInfo();
}

void CandidateType::printCandidateTotalVotes() const {
	printName();
	cout << "=> Total Votes (all divisions): " << numberOfVotes << endl;
}

void CandidateType::printCandidateDivisionVotes(int divisionNumber) const {
	cout << "   => Division " << divisionNumber << ": "<< divisions[divisionNumber - 1] << endl;
}

CandidateType::~CandidateType() {}
