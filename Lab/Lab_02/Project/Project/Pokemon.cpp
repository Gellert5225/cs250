#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon() {

}

Pokemon::Pokemon(std::string name, int number, std::string firstType) {
	this->name = name;
	this->number = number;
	this->firstType = firstType;
}

Pokemon::Pokemon(std::string name, int number, std::string firstType, std::string secondType) {
	this->name = name;
	this->number = number;
	this->firstType = firstType;
	this->secondType = secondType;
}

Pokemon::~Pokemon() {

}

std::string Pokemon::getType1() const {
	return this->firstType;
}

std::string Pokemon::getType2() const {
	return this->secondType;
}

bool Pokemon::commonType(Pokemon p) const {
	if (p.secondType == "" && this->secondType == "") return this->firstType == p.firstType;

	return this->firstType == p.firstType ||
		this->secondType == p.secondType ||
		this->firstType == p.secondType ||
		this->secondType == p.firstType;
}

void Pokemon::print() const {
	std::cout << this->name << ": " << firstType << " " << secondType;
}
