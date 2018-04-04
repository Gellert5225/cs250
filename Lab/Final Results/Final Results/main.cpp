/*
Li, Gellert & Wegener, Brian

Team: memoryLeak

CS A250
March 14, 2018
Candidate List
*/

#include "InputHandler.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayMenu();
void processChoice(CandidateList& candidateList);

int main() {
	CandidateList candidateList;

	readCandidateData(candidateList);
	displayMenu();
	processChoice(candidateList);

	candidateList.printFinalResults();
	cout << endl;
	system("Pause");
	return 0;
}

void displayMenu() {
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nSelect one of the following:\n\n";
	cout << "    1: Print all candidates" << endl;
	cout << "    2: Print a candidate's division votes" << endl;
	cout << "    3: Print a candidate's total votes" << endl;
	cout << "    4: Print winner" << endl;
	cout << "    5: To exit" << endl;
}

void processChoice(CandidateList& candidateList) {
	int choice;
	cout << "\nEnter your choice: ";
	cin >> choice;

	while (choice != 5) {
		string fName, lName;
		int division = 0,
			ssn = 0;

		switch (choice) {
			// Print all candidates
		case 1:
			cout << endl;
			candidateList.printAllCandidates();
			break;

			// Print a candidates's division votes
		case 2:
			cout << "\nEnter candidate's social security number (no dashes): ";
			cin >> ssn;
			cout << endl;
			if (candidateList.searchCandidate(ssn)) {
				candidateList.printCandidateName(ssn);
				cout << endl;
				for (int i = 1; i <= NUM_OF_DIVISIONS; ++i)
					candidateList.printCandidateDivisionVotes(ssn, i);
			}
			break;

			// Print a candidate's total votes
		case 3:
			cout << "\nEnter candidate's social security number (no dashes): ";
			cin >> ssn;
			cout << endl;
			if (candidateList.searchCandidate(ssn)) {
				candidateList.printCandidateName(ssn);
				cout << endl;
				candidateList.printCandidateTotalVotes(ssn);
			}
			break;

			// Print winner
		case 4:
			ssn = candidateList.getWinner();
			if (ssn != 0) {
				cout << "\nElection winner: ";
				candidateList.printCandidateName(ssn);
				cout << endl;
				candidateList.printCandidateTotalVotes(ssn);
			} else {
				cout << "\n    => There are no candidates." << endl;
			}
			break;
		case 5:
			candidateList.printFinalResults();
			break;

		default:
			cout << "\n    => Sorry. That is not a selection." << endl;
		}

		cout << endl;
		system("Pause");
		displayMenu();
		cout << "\nEnter your choice: ";
		cin >> choice;
	}

	if (choice == 5)
		cout << "\nThank you and have a great day!" << endl;
}