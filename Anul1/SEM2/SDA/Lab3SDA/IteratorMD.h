#pragma once
#include "MD.h"

class MD;

class IteratorMD
{
	friend class MD;
	friend class Nod;

private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMD(const MD& c);

	//contine o referinta catre containerul pe care il itereaza
	const MD& md;

	/* aici e reprezentarea  specifica a iteratorului */
	PNod curent;

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const;

	//muta cursorul iteratorului a.i. sa refere a k-a pereche incepand de la cea curenta.
	//Iteratorul devine nevalid in cazul in care exista mai putin de k perechi ramase in multidictionar.
	//arunca exceptie in cazul in care iteratorul este nevalid sau k este zero ori negativ.
	void avanseazaKPasi(int k);
};


