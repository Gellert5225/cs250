/*
	(name header)
*/

#include "CandidateList.h"

CandidateList::CandidateList() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

void CandidateList::addCandidate(const CandidateType &candidate) {
	if (count == 0) {
		last = new Node(candidate, nullptr);
		first = new Node(candidate, nullptr);
	} else {
		Node *node = new Node(candidate, nullptr);
		last->setLink(node);
		last = node;
	}
	count++;
}

int CandidateList::getWinner() const {
	if (count == 0) {
		cerr << "=>List is empty." << endl;
		return 0;
	}
	Node *candidateNode = first;
	CandidateType winner = first->getCandidate();
	while (candidateNode != nullptr) {
		if (candidateNode->getCandidate().getTotalVotes() > winner.getTotalVotes()) winner = candidateNode->getCandidate();
		candidateNode = candidateNode->getLink();
	}
	return winner.getSSN();
}

bool CandidateList::searchCandidate(int ssn) const {
	if (count == 0) {
		cerr << "=>List is empty." << endl;
		return false;
	}

	Node *candidateNode = first;
	while (candidateNode != nullptr) {
		if (candidateNode->getCandidate().getSSN() == ssn) return true;
		candidateNode = candidateNode->getLink();
	}

	cout << "=>SSN not in the list." << endl;
	return false;
}

void CandidateList::printCandidateName(int ssn) const {
	if (count == 0) {
		cerr << "=>List is empty." << endl;
		return;
	}
	Node *candidateNode = first;
	bool found = false;
	while (!found && candidateNode != nullptr) {
		if (candidateNode->getCandidate().getSSN() == ssn) {
			found = true;
			candidateNode->getCandidate().printName();
		}
		candidateNode = candidateNode->getLink();
	}
}

void CandidateList::printAllCandidates() const {
	if (count == 0) {
		cerr << "=>List is empty." << endl;
		return;
	}

	Node *candidateNode = first;
	while ( candidateNode != nullptr) {
		candidateNode->getCandidate().printCandidateInfo();
		candidateNode = candidateNode->getLink();
	}
}

void CandidateList::printCandidateDivisionVotes(int ssn, int division) const {
	if (count == 0) {
		cerr << "=>List is empty." << endl;
		return;
	}
	Node *candidateNode = first;
	bool found = false;
	while (!found && candidateNode != nullptr) {
		if (candidateNode->getCandidate().getSSN() == ssn) {
			found = true;
			candidateNode->getCandidate().printCandidateDivisionVotes(division);
		}
		candidateNode = candidateNode->getLink();
	}
}

void CandidateList::printCandidateTotalVotes(int ssn) const {
	if (count == 0) {
		cerr << "=>List is empty." << endl;
		return;
	}
	Node *candidateNode = first;
	bool found = false;
	while (!found && candidateNode != nullptr) {
		if (candidateNode->getCandidate().getSSN() == ssn) {
			found = true;
			cout << candidateNode->getCandidate().getTotalVotes() << endl;
		}
		candidateNode = candidateNode->getLink();
	}
}

void CandidateList::destroyList() {
	while (first != nullptr) {
		Node *candidateNode = first;
		first = first->getLink();
		delete candidateNode;
		candidateNode = nullptr;
	}
	count = 0;
}

CandidateList::~CandidateList() {
	destroyList();
}
