#include "repo.h"
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include"vector.h"


using std::ostream;
using std::stringstream;
using std::to_string;

repo::~repo()
{
}

/*
* adauga un film
* arunca exceptie daca filmul cu titlul introdus exista deja
*/
void repo::adauga(Film f)
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
	int index = -1;
	for (int i = 0; i < this->lungime(); i++) {
		if (this->all[i].getTitlu() == f.getTitlu())
			index = i;
	}

	if (index == -1) {
		throw repoException("Filmul nu exista!\n");
	}
	all.remove(index);

}

/*
* cauta
* arunca exceptie daca nu exista filmul
*/
bool repo::cauta(const Film& f) {
	for (auto film : all) {
		if (film.getTitlu() == f.getTitlu()) {
			return true;
		}
	}
	return false;
}

/*
* modifica titlul unui film 
* arunca exceptie daca nu exista filmul
*/
void repo::modifica(Film& f1, const Film& f2) {
	int index = -1;
	for (int i = 0; i < this->lungime(); i++) {
		if (all[i].getTitlu() == f1.getTitlu()) {
			index = i;
		}
	}

	if (index == -1) {
		throw repoException("Filmul nu exista!\n");;
	}
	all[index] = f2;
}

/*
* returneaza toate filmele salvate
*/
vector<Film> repo::getAll() const noexcept {
	return all;
}

string repoException::getMesaj()const {
	return msg;

}

int repo::lungime() {
	return all.size();
}