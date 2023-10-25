#pragma once
#include"Film.h"

//#include<vector>
#include<string>
#include<ostream>
#include"vector.h"

//using std::vector;
using std::string;
using std::ostream;

class repo {
	vector<Film> all;

	bool exist(const Film& f)const;

public:
	repo() = default;
	//nu permitem copierea de obiecte
	repo(const repo& ot) = delete;
	
	~repo();
	/*
	* Functie pentru adaugare film
	* arunca exceptie daca mai exista alt film cu acelasi titlu
	*/
	void adauga(Film f);

	/*
	* Functie pentru stergere film
	* arunca exceptie daca nu exista alt film cu acest titlu
	*/
	void sterge(const Film& f);

	/*
	* Functie pentru cautare film
	* arunca exceptie daca nu exista alt film cu acest titlu
	*/
	bool cauta(const Film& f);

	/*
	* Functie pentru modificare film
	* arunca exceptie daca nu exista alt film cu acest titlu
	*/
	void modifica(Film& f1, const Film& f2);

	/*
	* returneaza toate masinile salvate
	*/
	vector<Film> getAll() const noexcept;

	int lungime();
};

class repoException {
	string msg;
public:
	repoException(string m) :msg{ m } {}
	string getMesaj()const;
	//functie friend (vreau sa folosesc membru privat msg)
};