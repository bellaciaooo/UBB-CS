#pragma once

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Apartament {
	std::string strada;
	int suprafata;
	int pret;
public:
	Apartament(const string str, int sup, int p) : strada{ str }, suprafata{ sup }, pret{ p } {}

	Apartament(const Apartament& ot) : strada{ot.strada}, suprafata{ot.suprafata}, pret{ot.pret} {}
	Apartament& operator = (const Apartament& a);

	//functie pentru a accesa campul strada din apartament
	string getStrada()const;

	//functie pentru a accesa campul suprafata din apartament
	int getSuprafata()const noexcept;

	//functie pentru a accesa campul pret din apartament
	int getPret()const noexcept;

	void setStrada(string strada);


};
