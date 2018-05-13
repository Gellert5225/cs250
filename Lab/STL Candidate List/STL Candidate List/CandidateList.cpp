/*
	memoryLeak

	Li, Gellert
	Wegener, Brian

	CS A250

	May 6th, 2018
	Project 2 - STL Candidate List
*/

#include "CandidateList.h"

CandidateList::CandidateList() {

}

void CandidateList::addCandidate(const CandidateType &candidate) {
	candidates.push_back(candidate);
}

int CandidateList::getWinner() const {
	if (isEmpty()) {
		cerr << "=>List is empty." << endl;
		return 0;
	}
	vector<CandidateType>::const_iterator iter = candidates.cbegin();
	vector<CandidateType>::const_iterator iterEnd = candidates.cend();
	CandidateType winner = *iter;
	while (iter != iterEnd) {
		if (iter->getTotalVotes() > winner.getTotalVotes()) 
			winner = *iter;
		iter++;
	}
	return winner.getSSN();
}

bool CandidateList::isEmpty() const {
	return candidates.empty();
}

void CandidateList::printCandidateName(int ssn) const {
	vector<CandidateType>::const_iterator iter = candidates.cbegin();

	if (searchCandidate(ssn, iter)) {
		iter->printName();
	}
}

void CandidateList::printAllCandidates() const {
	if (isEmpty()) {
		cerr << "=>List is empty." << endl;
	} else {
		vector<CandidateType>::const_iterator iter = candidates.cbegin();
		vector<CandidateType>::const_iterator iterEnd = candidates.cend();

		while (iter != iterEnd) {
			iter->printCandidateInfo();
			iter++;
		}
	}
}

void CandidateList::printCandidateDivisionVotes(int ssn, int division) const {
	vector<CandidateType>::const_iterator iter = candidates.cbegin();

	if (searchCandidate(ssn, iter)) {
		iter->printCandidateDivisionVotes(division);
	}
}

void CandidateList::printCandidateTotalVotes(int ssn) const {
	vector<CandidateType>::const_iterator iter = candidates.cbegin();

	if (searchCandidate(ssn, iter)) {
		cout << "    => Total votes: " << iter->getTotalVotes() << endl;
	}
}

CandidateList::~CandidateList() {
}

/* should we use else? */
bool CandidateList::searchCandidate(int ssn, vector<CandidateType>::const_iterator &candidate) const {
	if (isEmpty()) {
		cerr << "=>List is empty" << endl;
		return false;
	} 

	vector<CandidateType>::const_iterator iterEnd = candidates.cend();

	while (candidate != iterEnd) {
		if (candidate->getSSN() == ssn) {
			return true;
		}
		candidate++;
	}

	cout << "=>SSN not in the list." << endl;
	return false;
}

bool CandidateList::searchCandidate(int ssn) const {
	vector<CandidateType>::const_iterator iter = candidates.cbegin();
	return searchCandidate(ssn, iter);
}
