#pragma once
#include <iostream>
#include <string>

using std::string;

class Jucator {
	std::string nume;
	std::string tara;
	int punctaj;
	int ranking;

public:
	//constructorul
	Jucator(const string nume, const string tara, int punctaj, int ranking) : nume{ nume }, tara{ tara }, punctaj{ punctaj }, ranking{ ranking } {}
	
	Jucator(const Jucator& ot): nume{ot.nume}, tara{ot.tara}, punctaj{ot.punctaj},ranking{ot.ranking}{}
	//Jucator& operator= (const Jucator& j);

	//functie pentru accesare camp nume a jucatorului
	string getNume()const;

	//functie pentru accesare camp tara a jucatorului
	string getTara()const;

	//functie pentru accesare camp punctaj a jucatorului
	int getPunctaj()const noexcept;

	//functie pentru accesare camp ranking a jucatorului
	int getRanking()const noexcept;
};