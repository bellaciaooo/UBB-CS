#pragma once
#include "Film.h"
#include "repo.h"
#include <vector>

using std::vector;

class Cos {
	irepo& rep;
	vector<Film> filme;
public:
	//constructor
	Cos(irepo& rep) noexcept :rep{ rep } {}

	//functie care adauga filme in cos
	void adauga(string titlu);
	
	//functie care goleste cosul de filme 
	void goleste();

	//functie care genereaza automat un cos de filme in functie de numarul de filme introdus
	void genereaza(int nr);
	
	//functie ce returneaza filmele aflate in cos
	const vector<Film>& getAll() const noexcept;

	//functie ce exporta in fisierul file cosul de filme actual
	void exportC(const char* file) const;
};