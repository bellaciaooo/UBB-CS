#pragma once

#include"Film.h"
#include"repo.h"
#include<string>

#include"vector.h"
#include<functional>
#include"validator.h"

using std::function;

class service {
	repo& rep;
	FilmValidator& val;

	/*
	Functie generala de filtrare
	fct - poate fi o functie
	fct - poate fi lambda, am folosit function<> pentru a permite si functii lambda care au ceva in capture list
	returneaza doar filmele care trec de filtru (fct(film)==true)
	*/
	vector<Film> filterFilm(function<bool(const Film&)> fct);

	/*
	 Functie de sortare generala
	 cmp - functie care compara 2 Film, verifica daca are loc relatia 
			  - poate fi orice functe (in afara clasei) care respecta signatura (returneaza bool are 2 parametrii Film)
			  - poate fi functie lambda (care nu capteaza nimic in capture list)
	 returneaza o lista sortata dupa criteriu dat ca paramatru
	*/
	vector<Film> generalSortFilm(bool (*cmp)(const Film&, const Film&));

public:
	//constructor
	service(repo& rep, FilmValidator& val) noexcept :rep{ rep }, val{ val }{
	}
	//nu permite copierea de obiecte service
	service(const service& ot)noexcept = delete;


	//returneaza toate filmele in ordinea in care o fost adaugate
	vector<Film> getAll() noexcept {
		return rep.getAll();
	}
	/*
	* adauga un nou film
	* arunca exceptie daca : nu se poate salva , nu este valid
	*/
	void addFilm(string titlu, string gen, int anul_aparitiei, string actor_principal);

	/*
	* sterge un film dupa titlu
	* arunca exceptie daca nu gaseste filmul
	*/
	void deleteFilm(string titlu);

	/*
	* modifica titlul unui film
	* arunca exceptie daca nu gaseste filmul
	*/
	void modifyFilm(string titlu1, string titlu2);

	/*
	* cauta un film in functie de titlu
	*  arunca exceptie daca nu gaseste filmul
	*/
	bool cautaFilm(string titlu);

	/*
	* returneaza filmele cu anul aparitiei introdus
	*/
	vector<Film> FilterAnAparitie(int an);

	/*
	* returneaza filmele cu titlul introdus
	*/
	vector<Film> FilterTitlu(string titlu);
	
	/*
	* sorteaza filmele dupa titlu
	*/
	vector<Film> sortByTitlu();

	/*
	* sorteaza filmele dupa actorul principal
	*/
	vector<Film> sortByActorPrincipal();

	/*
	* sorteaza filmele dupa anul aparitiei si gen
	*/
	vector<Film> sortByAnGen();
};
