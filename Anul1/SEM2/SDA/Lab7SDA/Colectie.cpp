#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
	//Overall Complexity: theta(1)
	return e1 <= e2;
}

void Colectie::resize() {
	// redimensionarea 
	TComparabil* newElems = new TComparabil[cp * 2];
	int* newDrept = new int[cp * 2];
	int* newStang = new int[cp * 2];
	for (int i = 0; i < cp; i++) {
		newElems[i] = elems[i];
		newDrept[i] = drept[i];
		newStang[i] = stang[i];
	}
	// dealocarea spatiului
	delete elems;
	delete drept;
	delete stang;
	//crearea noilor legaturi
	elems = newElems;
	drept = newDrept;
	stang = newStang;
	// reinitializarea listei de spatii libere
	for (int i = cp; i < cp * 2 - 1; i++) {
		drept[i] = i + 1;
	}
	stang[cp * 2 - 1] = -1;
	primLiber = cp;
	cp = cp * 2;
}

void Colectie::dealoca(int p) {
	//Overall Complexity: theta(1)
	drept[p] = primLiber;
	stang[p] = -1;
	primLiber = p;
}

int Colectie::aloca() {
	//Overall Complexity: theta(1)
	// alocam un spatiu pe prima pozitie libera
	int p = primLiber;
	primLiber = drept[primLiber];
	return p;
}

int Colectie::creeazaNod(TElem e) {
	//Overall Complexity: O(n)
	if (size >= cp) {
		resize();
	}
	int pos = aloca();
	elems[pos] = std::make_pair(e, 1);
	stang[pos] = -1;
	drept[pos] = -1;
	return pos;
}

Colectie::Colectie() {
	//intializare capacitate si dimensiune
	cp = 10;
	size = 0;
	//alocare spatiu de memorie pt liste
	elems = new TComparabil[cp];
	stang = new int[cp];
	drept = new int[cp];
	//colectia la inceput este vida
	rad = -1;
	//initializam spatiile libere din lista
	for (int i = 0; i < cp - 1; i++)
	{
		drept[i] = i + 1;
		stang[i + 1] = i;
	}
	stang[0] = -1;
	drept[cp - 1] = -1;

	//primul spatiu liber este pe pozitia 0
	primLiber = 0;
}

void Colectie::adauga(TElem e) {
	//Overall Complexity: O(n)
	size++;
	// daca colectia e vida
	if (rad == -1) {
		rad = creeazaNod(e);
		return;
	}
	// parcurgem arborele pana gasim locul de adaugat
	int pos = rad;
	int parent = pos;
	while (pos != -1) {
		parent = pos;
		// daca elementul exista deja incrementam frecventa
		if (e == elems[pos].first) {
			elems[pos].second++;
			return;
		}
		// daca este in relatie cu elementul curent parcurgem subarborele stang, altfel pe cel drept
		if (rel(e, elems[pos].first)) {
			pos = stang[pos];
		}
		else {
			pos = drept[pos];
		}
	}
	// creem noul nod si subarborii
	int p = creeazaNod(e);
	if (rel(e, elems[parent].first)) {
		stang[parent] = p;
	}
	else {
		drept[parent] = p;
	}
}

bool Colectie::stergeRecursiv(int curent, int anterior, TElem e) {
	//Overall Complexity: O(n)
	// daca am ajuns la un subarbore vid
	if (curent == -1) {
		return false;
	}
	// daca am ajuns la elementul de sters
	if (elems[curent].first == e) {
		size--;
		// daca elementul are mai mult de o singura aparitie, decrementam frecventa
		if (elems[curent].second > 1) {
			elems[curent].second--;
			return true;
		}
		// daca nodul are si subarbore stang si drept
		else if (stang[curent] != -1 && drept[curent] != -1) {
			int min = minim(drept[curent]);
			elems[curent] = elems[min];
			return stergeRecursiv(drept[curent], curent, elems[min].first);
		}
		// daca nodul este o frunza
		else if (stang[curent] == -1 && drept[curent] == -1) {
			if (curent == rad) {
				rad = -1;
			}
			else {
				if (stang[anterior] == curent) {
					stang[anterior] = -1;
				}
				else {
					drept[anterior] = -1;
				}
			}
		}
		// daca nodul are un singur fiu, stang
		else if (stang[curent] == -1) {
			if (anterior == -1) {
				rad = drept[curent];
			}
			else if (stang[anterior] == curent) {
				stang[anterior] = drept[curent];
			}
			else {
				drept[anterior] = drept[curent];
			}
		}
		// daca nodul are un singur fiu, drept
		else {
			if (anterior == -1) {
				rad = stang[curent];
			}
			else if (stang[anterior] == curent) {
				stang[anterior] = stang[curent];
			}
			else {
				drept[anterior] = stang[curent];
			}
		}
		dealoca(curent);
		return true;
	}
	// daca este in relatie cu elementul curent parcurgem subarborele stang, altfel pe cel drept
	if (rel(e, elems[curent].first)) {
		return stergeRecursiv(stang[curent], curent, e);
	}
	else {
		return stergeRecursiv(drept[curent], curent, e);
	}
}

bool Colectie::sterge(TElem e) {
	//Overall Complexity: O(n)
	return  stergeRecursiv(rad, -1, e);
}


bool Colectie::cauta(TElem elem) const {
	//Overall Complexity: O(n)
	// parcurgem arborele pana gasim elementul sau ajungem la capatul arborelui
	int pos = rad;
	while (pos != -1) {
		if (elem == elems[pos].first) {
			return true;
		}
		// daca este in relatie cu elementul curent parcurgem subarborele stang, altfel pe cel drept
		if (rel(elem, elems[pos].first)) {
			pos = stang[pos];
		}
		else {
			pos = drept[pos];
		}
	}
	return false;
}


int Colectie::nrAparitii(TElem elem) const {
	// Overall Complexity: O(n) 
	// parcurgem arborele
	int pos = rad;
	while (pos != -1) {
		// daca am gasit elementul
		if (elem == elems[pos].first) {
			return elems[pos].second;
		}
		// daca este in relatie cu elementul curent parcurgem subarborele stang, altfel pe cel drept
		if (rel(elem, elems[pos].first)) {
			pos = stang[pos];
		}
		else {
			pos = drept[pos];
		}
	}
	// daca elementul nu a fost gasit
	return 0;
}

int Colectie::minim(int pos) {
	//Overall Complexity: O(n)
	while (stang[pos] != -1)
	{
		pos = stang[pos];
	}
	return pos;
}

int Colectie::maxim(int pos) {
	//Overall Complexity: O(n)
	while (drept[pos] != -1)
	{
		pos = drept[pos];
	}
	return pos;
}

int Colectie::diferentaMaxMin() {
    //Overall Complexity: O(n)
    /*
    *  PSEUDOCOD
	*  Daca col.rad = -1 atunci
	*     returneaza -1
	*  SfDaca
	*  elemMax <- col.elem[maxim(col.rad)].first
	*  elemMin <- col.elem[minim(col.rad)].first
	*  returneaza elemMax - elemMin
    */
    // daca colectia e vida
	if (rad == -1)
		return -1;
	//colectia nu este vida
	int elemMax = elems[maxim(rad)].first;
	int elemMin = elems[minim(rad)].first;
	
	return elemMax - elemMin;
}

int Colectie::dim() const {
	//Overall Complexity: theta(1)
	return size;
}


bool Colectie::vida() const {
	//Overall Complexity: theta(1)
	return size == 0;
}


IteratorColectie Colectie::iterator() const {
	//Overall Complexity: O(n)
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	//Overall Complexity: theta(1)
	delete[] elems;
	delete[] stang;
	delete[] drept;
}
