/*
	Li, Gellert

	CS A250
	18th April, 2018

	Lab 10: DArray Class
*/

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <ostream>

class Movie {

	friend std::ostream& operator<<(std::ostream& out, const Movie &movie);

public:
	Movie();
	Movie(std::string title, int year);
	~Movie();

	std::string getTitle() const;
	int getYear() const;

	void setTitle(std::string title);
	void setYear(int year);

	bool operator==(const Movie &movie) const;
	Movie& operator=(const Movie &movie);

private:
	std::string title;
	int year;
};

#endif

