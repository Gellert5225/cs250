#include "InputHandler.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	CandidateList candidateList1, candidateList2;

	CandidateType c11, c12, c13;
	c11.setPersonInfo("Bob", "Peterson", 111111111);
	c12.setPersonInfo("Jane", "Monroe", 122222222);
	c13.setPersonInfo("Sue", "Cloud", 133333333);
	candidateList1.addCandidate(c11);
	candidateList1.addCandidate(c12);
	candidateList1.addCandidate(c13);
	
	cout << "List 1:\n";
	candidateList1.printAllCandidates();

	CandidateType c21, c22, c23;
	c21.setPersonInfo("Kate", "Carrington", 211111111);
	c22.setPersonInfo("Mark", "Jefferson", 222222222);
	c23.setPersonInfo("Dave", "Morris", 233333333);
	candidateList2.addCandidate(c21);
	candidateList2.addCandidate(c22);
	candidateList2.addCandidate(c23);

	cout << "\nList 2:\n";
	candidateList2.printAllCandidates();

	cout << "\nTEST copy constructor...\n";
	cout << "\nCreate list 3 by copying from list 1...";
	CandidateList candidateList3 = candidateList1;
	cout << "\nDestroy list 1...\n";
	candidateList1.~CandidateList();
	cout << "\nPrint list 3...\n";
	candidateList3.printAllCandidates();

	cout << "\nTEST overloaded assignment operator...\n";
	cout << "\nCopy list 2 into list 3...";
	candidateList3 = candidateList2;
	cout << "\nDestroy list 2...\n";
	candidateList2.~CandidateList();
	cout << "\nPrint list 3...\n";
	candidateList3.printAllCandidates();

	cout  <<  endl;
	system("Pause");
	return 0;
}
