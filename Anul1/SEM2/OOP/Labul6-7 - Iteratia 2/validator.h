#pragma once
#include<string>
#include"Film.h"



using std::string;
using std::ostream;

class ValidateException {
	vector<string> msgs;
public:
	ValidateException(const vector<string>& errors) :msgs{ errors } {}
	//functie friend (folosim mereu membru privat msg)
	friend ostream& operator<<(ostream& out, const ValidateException& ex);
};

ostream& operator<<(ostream& out, const ValidateException& ex);

class FilmValidator {
public:
	//functie pentru validare instanta film
	void validate(const Film& f);
};