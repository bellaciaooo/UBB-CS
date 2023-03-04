#pragma once
#include "irepo.h"
#include "repo.h"
#include "Film.h"
#include <map>
#include <vector>
using std::map;
using std::vector;

class repoProb : public irepo
{
private:
	map<string, Film> all;
	float p;	
	vector<Film> replica;
	void AruncaExceptie(string mesaj) const;
public:
	// Constructor
	// p - Probabilitatea cu care va arunca
	repoProb(float p);

	// Adauga un film in repository
	// f - filmul care va fi adaugat
	// daca filmul este deja adaugat se arunca exceptie
	void adauga(const Film& f) override;

	// Sterge un film din repository
	// f - filmul care va fi sters
	// daca filmul nu exista se arunca exceptie
	void sterge(const Film& f) override;

	// Modifica un locatar din repository
	// f1 - filmul care va fi modificat
	// f2 - filmul cu care va fi modificat
	// daca filmul cu acel titlu nu exista se arunca exceptie
	void modifica(Film& f1, const Film& f2)  override;

	// Cauta un locatar dupa apartament
	// f - filmul cautat
	// daca filmul nu exista se arunca exceptie
	bool cauta(const Film& f) override;

	// Returneaza toate filmele
	const vector<Film>& getAll() override;

	virtual ~repoProb() {}
};

//clasa pentru exceptii aruncate la intamplare
class randomException {
	string msg;
public:
	randomException(string m) :msg(m) {} string getMesaj()const { return "Exceptie aruncata la intamplare in "+msg; }
};