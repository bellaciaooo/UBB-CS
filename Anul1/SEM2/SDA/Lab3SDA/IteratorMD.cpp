#include "IteratorMD.h"
#include "MD.h"
#include <exception>

using namespace std;

IteratorMD::IteratorMD(const MD& _md) : md(_md) {
	/*
	Overall complexity: theta(1)
	*/
	curent = md.prim;
}

TElem IteratorMD::element() const {
	/*
	Overall complexity: theta(1)
	*/
	if (valid())
		return curent->el();
	else
		throw std::exception();
}

bool IteratorMD::valid() const {
	/*
	Overall complexity: theta(1)
	*/
	if (curent != nullptr)
		return true;
	return false;
}

void IteratorMD::urmator() {
	/*
	Overall complexity: theta(1)
	*/
	curent = curent->urmator();
}

void IteratorMD::prim() {
	/*
	Overall complexity: theta(1)
	*/
	curent = md.prim;
}

void IteratorMD::avanseazaKPasi(int k) {
	/*
	Overall complexity: O(n)

	PSEUDOCOD:
	pre: it - iterator , k - numar pozitiv, valid(it) 
	post: it' - iterator, refera urmatoarea a k-a pereche incepand de la cea curenta
	@ arunca exceptie
	@ iteratorul este nevalid sau k este 0 ori numar negativ
	Subalgoritm avanseazaKPasi 
	Daca valid(it) = fals || k <= 0 atunci
		arunca @exceptie
	SfDaca
	Cattimp valid(it) = adevarat && k > 0 executa
		it.curent <- [it.curent].urm
		k <- k - 1
	SfCattimp
	SfSubalgortim avanseazaKPasi
	*/
	if (valid() == false || k <= 0)
		throw std::exception();
	while (valid() && k > 0) {
		curent = curent->urmator();
		k--;
	}
}
