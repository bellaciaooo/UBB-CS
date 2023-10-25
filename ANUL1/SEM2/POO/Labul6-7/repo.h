#pragma once
#include"Film.h"
#include"irepo.h"
#include<vector>
#include<string>
#include<ostream>

using std::vector;
using std::string;
using std::ostream;

class repo : public irepo
{
protected:
	vector<Film> all;

public:
	repo() = default;
	//nu permitem copierea de obiecte
	repo(const repo& ot) = delete;
	
	/*
	* Functie pentru adaugare film
	* arunca exceptie daca mai exista alt film cu acelasi titlu
	*/
	virtual void adauga(const Film& f) override;

	/*
	* Functie pentru stergere film
	* arunca exceptie daca nu exista alt film cu acest titlu
	*/
	virtual void sterge(const Film& f) override;

	/*
	* Functie pentru cautare film
	* arunca exceptie daca nu exista alt film cu acest titlu
	*/
	virtual bool cauta(const Film& f) override;

	/*
	* Functie pentru modificare film
	* arunca exceptie daca nu exista alt film cu acest titlu
	*/
	virtual void modifica(Film& f1, const Film& f2) override;

	/*
	* returneaza toate masinile salvate
	*/
	virtual const vector<Film>& getAll() override;

	virtual ~repo() {}
};

//clasa pentru exceptii repo
class repoException {
	string msg;
public:
	repoException(string m) :msg{ m } {}
	string getMesaj()const { return msg; }
};