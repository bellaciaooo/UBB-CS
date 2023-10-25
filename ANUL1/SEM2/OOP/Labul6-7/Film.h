#pragma once

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Film {
	std::string titlu;
	std::string gen;
	int anul_aparitiei;
	std::string actor_principal;
public:
	Film(const string t, const string g, int a, const string c) : titlu{ t }, gen{ g }, anul_aparitiei{ a }, actor_principal{ c }{}  Film() = default;

	Film(const Film& ot) :titlu{ ot.titlu }, gen{ ot.gen }, anul_aparitiei{ ot.anul_aparitiei }, actor_principal{ ot.actor_principal }{}
	Film& operator = (const Film& f);

	//functie ca sa accesam campul 'titlu' din film 
	string getTitlu()const;
	//functie ca sa accesam campul 'gen' din film 
	string getGen()const;
	//functie ca sa accesam campul 'an aparitie' din film
	int getAnAparitie()const noexcept;
	//functie ca sa accesam campul 'actor principal' din film
	string getActorPrincipal()const;

	//setam valoarea campului titlu din film
	void setTitlu(string tit);

	bool operator==(const Film& ot) const noexcept
	{
		return titlu == ot.titlu;
	}
	//void setGen(string gen);
	//void setAn(int an);
	//void setActor(string actor);
};