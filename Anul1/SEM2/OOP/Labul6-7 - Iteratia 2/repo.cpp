#include "repo.h"
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>


using std::ostream;
using std::stringstream;
using std::to_string;

/*
* adauga un film
* arunca exceptie daca filmul cu titlul introdus exista deja
*/
void repo::adauga(const Film& f)
{
	for (const Film& film : all) {
		if (film.getTitlu() == f.getTitlu()) {
			throw repoException("Filmul exista deja!");
		}
	}
	all.push_back(f);
}

/*
* sterge un film in functie de titlul introdus
* arunca exceptie daca filmul nu exista
*/
void repo::sterge(const Film& f) {
	if (cauta(f) == false) {
		throw repoException("Filmul nu exista\n");
	}
	int i = 0;
	for (const Film& film : all) {
		if (film.getTitlu() == f.getTitlu()) {
			for (int j = i; j < all.size() - 1; j++) {
				all.at(j) = all.at(j + 1);
			}
		}
		i++;
	}
	all.pop_back();

}

/*
* cauta
* arunca exceptie daca nu exista filmul
*/
bool repo::cauta(const Film& f) {
	auto film = find_if(all.begin(), all.end(), [f](const Film film) {return f.getTitlu() == film.getTitlu(); });
	if (film != all.end()) 
		return true; 
	else 
		return false; }

/*
* modifica titlul unui film 
* arunca exceptie daca nu exista filmul
*/
void repo::modifica(Film& f1, const Film& f2) {
	if (cauta(f1) == false) {
		throw repoException("Filmul nu exista!\n");
	}
	for (Film& film : all) {
		if (film.getTitlu() == f1.getTitlu()) {
			film.setTitlu(f2.getTitlu());
		}
	}
}

/*
* returneaza toate filmele salvate
*/
const vector<Film>& repo::getAll() const noexcept {
	return all;
}

string repoException::getMesaj()const {
	return msg;

}