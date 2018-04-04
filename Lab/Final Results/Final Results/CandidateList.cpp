/*
	Li, Gellert
	Wegener, Brian

	Team: memoryLeak

	CS A250
	March 4, 2018
	Project 1 (Part D) - Final Results
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
		if (count == 1) first->setLink(node);
		else {
			last->setLink(node);
		}
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

void CandidateList::printCandidateName(int ssn) const {
	Node *candidateNode = first;

	if (searchCandidate(ssn, candidateNode)) {
		candidateNode->getCandidate().printName();
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
	Node *candidateNode = first;

	if (searchCandidate(ssn, candidateNode)) {
		candidateNode->getCandidate().printCandidateDivisionVotes(division);
	}
}

void CandidateList::printCandidateTotalVotes(int ssn) const {

	Node *candidateNode = first;

	if (searchCandidate(ssn, candidateNode)) {
		cout << "    => Total votes: " << candidateNode->getCandidate().getTotalVotes() << endl;
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

void CandidateList::printFinalResults() {
	// find max vote first
	CandidateList finalList;

	int counter = 1;
	Node *current = sort(*this);
	while (current != nullptr) {
		cout << counter << "  " << current->getCandidate().getTotalVotes() << " " 
			<< current->getCandidate().getFirstName() << ", " << current->getCandidate().getLastName() << endl;
		current = current->getLink();
		counter++;
	}
}

CandidateList::~CandidateList() {
	destroyList();
}

bool CandidateList::searchCandidate(int ssn, Node* &candidate) const {
	if (count == 0) {
		cerr << "=>List is empty" << endl;
		return false;
	} 

	Node *candidateNode = first;
	while (candidateNode != nullptr) {
		if (candidateNode->getCandidate().getSSN() == ssn) {
			candidate = candidateNode;
			return true;
		}
		candidateNode = candidateNode->getLink();
	}

	cout << "=>SSN not in the list." << endl;
	return false;
}

bool CandidateList::searchCandidate(int ssn) const {
	Node *n = nullptr;
	return searchCandidate(ssn, n);
}

Node* sort(CandidateList &list) {
	if (list.count == 0) return nullptr;
	// get the max node
	Node *maxNode = getMax(list);

	// swap with first node, get prev first
	Node *second = list.first->getLink();

	if (second != maxNode) {
		if (list.first != maxNode) {
			Node *maxPrev = list.first;
			while (maxPrev->getLink() != maxNode) {
				maxPrev = maxPrev->getLink();
			}
			list.first->setLink(maxNode->getLink());
			maxNode->setLink(second);
			maxPrev->setLink(list.first);
		}
	} else {
		list.first->setLink(maxNode->getLink());
		maxNode->setLink(list.first);
	}
	list.first = maxNode;

	list.first = list.first->getLink();
	list.count--;

	maxNode->setLink(sort(list));

	return maxNode;
}

Node* getMax(CandidateList &list) {
	Node *current = list.first;
	Node *maxNode = nullptr;
	int max = 0;
	while (current != nullptr) {
		if (current->getCandidate().getTotalVotes() >= max) { 
			max = current->getCandidate().getTotalVotes(); 
			maxNode = current;
		}
		current = current->getLink();
	}

	return maxNode;
}