/*
	Li, Gellert

	CS A250
	28th April, 2018

	Lab 12
*/

#include <set>
#include <map>
#include <iterator>
#include <iostream>
using namespace std;

int countClumps(const multiset<int> &set);
bool linearIn(const multimap<int, int> &map);
void multiples(set<int> &set, int multiple);
void printSet(const set<int> set);

int main() {

	// TEST countClumps
	int myints1[] = { 1, 2, 2, 3, 4, 4 };
	multiset<int> mySet1(myints1, myints1+ 6);
	cout << "Clumps: " << countClumps(mySet1) << endl;

	int myints2[] = { 1, 1, 2, 2, 2 };
	multiset<int> mySet2(myints2, myints2 + 5);
	cout << "Clumps: " << countClumps(mySet2) << endl;

	int myints3[] = { 3, 3, 3, 3, 3 };
	multiset<int> mySet3(myints3, myints3 + 5);
	cout << "Clumps: " << countClumps(mySet3) << endl;

	int myints4[] = { 1, 2, 3 };
	multiset<int> mySet4(myints4, myints4 + 3);
	cout << "Clumps: " << countClumps(mySet4) << endl;

	int myints5[] = { 2, 2, 6, 6, 6, 7, 8, 8, 9, 9 };
	multiset<int> mySet5(myints5, myints5 + 10);
	cout << "Clumps: " << countClumps(mySet5) << endl;

	int myints6[] = { 1,2,3,4,5,6,7,8,9,9 };
	multiset<int> mySet6(myints6, myints6 + 10);
	cout << "Clumps: " << countClumps(mySet6) << endl;

	int myints7[] = { 1,3,5,7,7,8,9 };
	multiset<int> mySet7(myints7, myints7 + 7);
	cout << "Clumps: " << countClumps(mySet7) << endl;

	multiset<int> mySet8;
	cout << "Clumps: " << countClumps(mySet8) << endl;

	// TEST linearIn
	multimap<int, int> myMap1 = { {3,3},{ 4,4 },{ 5,1 },{ 6,2 },{ 7,3 },{ 7,5 } };
	cout << (linearIn(myMap1) ? "True" : "False") << endl;

	multimap<int, int> myMap2 = { { 1,2 },{ 2,6 },{ 4,2 },{ 4,6 },{ 6,4 } };
	cout << (linearIn(myMap2) ? "True" : "False") << endl;

	multimap<int, int> myMap3 = { { 2,4 },{ 2,3 },{ 4,6 },{ 4,7 },{ 6,5 },{6,2} };
	cout << (linearIn(myMap3) ? "True" : "False") << endl;

	multimap<int, int> myMap4 = { { 3,6 },{ 4,6 },{ 5,6 },{ 6,6 } };
	cout << (linearIn(myMap4) ? "True" : "False") << endl;

	multimap<int, int> myMap5 = { { 3,3 },{ 3,3 },{ 3,3 },{ 3,3 },{ 3,4 } };
	cout << (linearIn(myMap5) ? "True" : "False") << endl;

	multimap<int, int> myMap6 = { { 3,3 },{ 3,3 },{ 3,3 },{ 3,4 },{ 4,3 } };
	cout << (linearIn(myMap6) ? "True" : "False") << endl;

	set<int> myEmptySet1;
	multiples(myEmptySet1, 2);
	printSet(myEmptySet1);

	set<int> myEmptySet2;
	multiples(myEmptySet2, 3);
	printSet(myEmptySet2);

	set<int> myEmptySet3;
	multiples(myEmptySet3, 5);
	printSet(myEmptySet3);

	system("PAUSE");

	return 0;
}

typedef std::multiset<int>::iterator It;

int countClumps(const multiset<int> &set) {
	multiset<int>::const_iterator iter = set.cbegin();
	multiset<int>::const_iterator iterEnd = set.cend();

	int clumps = 0;

	while (iter != iterEnd) {
		std::pair<It, It> range = set.equal_range(*iter);

		int count = static_cast<int>(std::distance(range.first, range.second));
		if (count > 1) {
			clumps++;
		}

		advance(iter, count);
	}

	return clumps;
}

bool linearIn(const multimap<int, int> &map) {
	multimap<int, int>::const_iterator iter = map.cbegin();
	multimap<int, int>::const_iterator iterEnd = map.cend();

	for (iter; iter != iterEnd; ++iter) {
		if (map.find(iter->second) == iterEnd) return false;
	}

	return true;;
}

void multiples(set<int> &set, int num) {
	int multiple = 2;
	while (set.size() < 10) {
		if (num * multiple % 10 != num) set.insert(num * multiple);
		multiple++;
	}
}

void printSet(const set<int> set) {
	for (int n : set) {
		cout << n << " ";
	}
	cout << endl;
}