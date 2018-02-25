/*
	Li, Gellert

	CS A250
	10th February, 2018

	Lab 2 Pokemon
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon {
public:
	Pokemon();
	Pokemon(std::string name, int number, std::string firstType);
	Pokemon(std::string name, int number, std::string firstType, std::string secondType);

	~Pokemon();

	std::string getType1() const;
	std::string getType2() const;

	bool commonType(Pokemon p) const;

	void print() const;
private:
	std::string name;
	int number;
	std::string firstType;
	std::string secondType;
};

#endif

