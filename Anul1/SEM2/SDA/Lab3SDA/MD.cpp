#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;

Nod::Nod(TElem e, PNod ant, PNod urm) {
	/*
	Overall complexity: theta(1)
	*/
	this->e = e;
	this->ant = ant;
	this->urm = urm;
}

MD::MD() {
	/*
	Overall complexity: theta(1)
	*/
	prim = nullptr;
	ultim = nullptr;
} 

TElem Nod::el() {
	/*
	Overall complexity: theta(1)
	*/
	return e;
}
PNod Nod::urmator() {
	/*
	Overall complexity: theta(1)
	*/
	return urm;
}

void MD::adauga(TCheie c, TValoare v) {
	/*
	Overall complexity: theta(1)
	*/
	TElem e = make_pair(c, v);
	PNod q = new Nod(e, nullptr, nullptr);
	if (prim == nullptr) {
		prim = q;
		ultim = prim;
		return;
	}
	else {
		ultim->urm = q;
		q->ant = ultim;
		ultim = q;
		return;
	}
}


bool MD::sterge(TCheie c, TValoare v) {
	/*
	Overall complexity: O(n)
	*/
	IteratorMD i = iterator();
	i.prim();
	if (!i.valid())
		return false;
	while (i.valid()) {
		if (i.element().first == c and i.element().second == v) {
			if (i.curent->ant != nullptr and i.curent->urm != nullptr) {
				PNod nod_anterior = i.curent->ant;
				PNod nod_urmator = i.curent->urm;
				nod_anterior->urm = nod_urmator;
				nod_urmator->ant = nod_anterior;
			}
			else if (i.curent->ant == nullptr and i.curent->urm != nullptr) {
				PNod nod_urmator = i.curent->urm;
				nod_urmator->ant = nullptr;
				prim = nod_urmator;
			}
			else if (i.curent->urm == nullptr and i.curent->ant != nullptr) {
				PNod nod_anterior = i.curent->ant;
				nod_anterior->urm = nullptr;
				ultim = nod_anterior;
			}
			else {
				prim = nullptr;
				ultim = nullptr;
			}
			delete i.curent;
			return true;
		}
		i.urmator();
	}
	return false;
}


vector<TValoare> MD::cauta(TCheie c) const {
	/*
	Overall complexity: theta(n)
	*/
	vector <TValoare> vect;
	IteratorMD i = iterator();
	i.prim();
	while (i.valid()) {
		if (i.curent->e.first == c)
			vect.push_back(i.curent->e.second);
		i.urmator();
	}
	return vect;
}


int MD::dim() const {
	/*
	Overall complexity: theta(n)
	*/
	IteratorMD i = iterator();
	int nr = 0;
	PNod curent = prim;
	while (curent != nullptr) {
		nr++;
		curent = curent->urm;
	}
	return nr;
}


bool MD::vid() const {
	/*
	Overall complexity: theta(1)
	*/
	if (prim == nullptr)
		return true;
	return false;
}

IteratorMD MD::iterator() const {
	/*
	Overall complexity: theta(1)
	*/
	return IteratorMD(*this);
}


MD::~MD() {
	/*
	Overall complexity: theta(n)
	*/
	IteratorMD i = iterator();
	i.prim();
	while (i.valid()) {
		PNod curent = i.curent;
		i.urmator();
		delete curent;
	}
}

int MD::diferentaValoareMaxMin() const {
	/*
	Overall complexity: O(n)

	PSEUDOCOD:
	pre: md - multidictionar
	post: diferentaValoareMaxMin() = * -1 , daca multidictionarul este vid
	                                 * diferenta dintre valoarea maxima si minima, altfel
	Subalgoritm - diferenta dintre valoarea maxima si minima
	Daca md.vid() = adevarat atunci
		returneaza -1
	SfDaca
	p <- md.prim
	val_max <- [p].e
	val_min <- [p].e
	Cattimp p != NIL executa
		Daca [p].e > val_max atunci 
			val_max = [p].e
		SfDaca
		Daca [p].e < val_min atunci
			val_min = [p].e
		SfDaca
		p <- [p].urm
	SfCattimp
	returneaza val_max - val_min
	SfSubalgoritm
	*/
	IteratorMD i = iterator();
	if (this->vid())
		return -1;
	i.prim();
	int val_max=i.element().second, val_min= i.element().second;
	i.urmator();
	while (i.valid())
	{
		if (i.element().second > val_max)
			val_max = i.element().second;
		if (i.element().second < val_min)
			val_min = i.element().second;
		i.urmator();
	}
	return val_max - val_min;
}
