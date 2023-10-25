#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	//seteaza iteratorul pe prima pozitie din vector
	curent = 0;
}

TElem IteratorColectie::element() const {
	//returneaza elementul curent
	return col.p[curent].first;
}

bool IteratorColectie::valid() const {
	//verifica daca iteratorul indica spre un element existent in vector
	return curent < col.size;
}

void IteratorColectie::urmator() {
	//incrementeaza pe urmatoarea pozitie din vector
	curent++;
}

void IteratorColectie::prim() {
	//reseteaza iteratorul pe prima pozitie din vector
	curent = 0;
}
