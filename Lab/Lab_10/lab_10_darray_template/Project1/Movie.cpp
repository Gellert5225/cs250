/*
	Li, Gellert

	CS A250
	18th April, 2018

	Lab 10: DArray Class
*/

#include "Movie.h"

Movie::Movie() {

}

Movie::Movie(std::string title, int year) {
	this->title = title;
	this->year = year;
}


Movie::~Movie() {
}

std::string Movie::getTitle() const {
	return title;
}

int Movie::getYear() const {
	return year;
}

void Movie::setTitle(std::string title) {
	this->title = title;
}

void Movie::setYear(int year) {
	this->year = year;
}

bool Movie::operator==(const Movie & movie) const {
	return title == movie.title && year == movie.year;
}

Movie & Movie::operator=(const Movie & movie) {
	if (&movie != this) {
		title = movie.title;
		year = movie.year;
	}
	return *this;
}

std::ostream & operator<<(std::ostream& out, const Movie & movie) {
	return out << "\"" << movie.title << "\"" << "(" << movie.year << ")" << std::endl;
}


