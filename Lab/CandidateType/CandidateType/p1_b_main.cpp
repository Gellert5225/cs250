/*
	Li, Gellert & Wegener, Brian
	Team: memoryLeak

	CS A250
	March 7, 2018

	Candidate Type
*/


#include "CandidateType.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "===================================================\n"
		<< "TEST: default constructor...\n\n";
	CandidateType bob;
	bob.printCandidateInfo();

	cout << "\n\n===================================================\n"
		<< "TEST: setPersonInfo...\n\n";
	bob.setPersonInfo("Bob", "Peterson", 111663333);
	bob.printCandidateInfo();

	cout << "\n\n===================================================\n"
		<< "TEST: updateVotesByDivision...\n";
	cout << "TEST: getTotalVotes...\n\n";
	bob.updateVotesByDivision(1,10);
	bob.updateVotesByDivision(2,22);
	bob.updateVotesByDivision(3,45);	
	cout << "Total votes: " << bob.getTotalVotes();

	cout << "\n\n===================================================\n"
		<< "TEST: getVotesByDivision...\n";
	cout << "\nVotes Division 1: " << bob.getVotesByDivision(1);
	cout << "\nVotes Division 2: " << bob.getVotesByDivision(2);
	cout << "\nVotes Division 3: " << bob.getVotesByDivision(3);
	cout << "\nVotes Division 4: " << bob.getVotesByDivision(4);

	cout << "\n\n===================================================\n"
		<< "TEST: printCandidateInfo...\n\n";
	bob.printCandidateInfo();

	cout << "\n\n===================================================\n"
		<< "TEST: printCandidateTotalVotes...\n\n";
	bob.printCandidateTotalVotes();

	cout << "\n\n===================================================\n"
		<< "TEST: printCandidateDivisionVotes...\n\n";
	bob.printCandidateDivisionVotes(1);
	cout << endl << endl;
	bob.printCandidateDivisionVotes(2);
	cout << endl << endl;
	bob.printCandidateDivisionVotes(3);
	cout << endl << endl;
	bob.printCandidateDivisionVotes(4);
	cout << endl << endl;

	cout  <<  endl;
	system("Pause");
	return 0;
}
