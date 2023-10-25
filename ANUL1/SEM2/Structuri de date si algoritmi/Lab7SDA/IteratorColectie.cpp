#include "IteratorColectie.h"
#include "Colectie.h"

using namespace std;

IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	//Overall complexity: O(n)
	curent = col.rad;
	int anterior = -1;
	// se adauga in stiva ramura stanga a elementului curent
	while (curent != -1) {
		els.push(curent);
		anterior = curent;
		curent = col.stang[curent];
	}
	// se sterge frunza din varful stivei
	if (!els.empty()) {
		els.pop();
		curent = anterior;
	}
}

TElem IteratorColectie::element() {
	//Overall Complexity: theta(1)
	if (!valid()) {
		throw exception();
	}
	return col.elems[curent].first;
}

bool IteratorColectie::valid() const {
	//Overall Complexity: theta(1)
	return curent != -1;
}

void IteratorColectie::urmator() {
	//Overall Complexity: O(n)
	if (!valid()) {
		throw exception();
	}
	// stergem nodul din varful stivei
	if (!els.empty()) {
		curent = els.top();
		els.pop();
	}
	if (col.drept[curent] != -1) {
		curent = col.drept[curent];
		// adaugam in stiva ramura stanga a elementului curent
		while (curent != -1) {
			els.push(curent);
			curent = col.stang[curent];
		}
	}
	// se sterge nodul din varful stivei
	if (!els.empty()) {
		curent = els.top();
	}
	else {
		curent = -1;
	}
}

void IteratorColectie::prim() {
	//Overall Complexity: O(n)
	// stergem toate elementele adaugate din stiva
	while (!els.empty()) {
		els.pop();
	}
	curent = col.rad;
	// se adauga in stiva ramura stanga a elementului curent
	while (curent != -1) {
		els.push(curent);
		curent = col.stang[curent];
	}
	// se sterge frunza din varful stivei
	if (!els.empty()) {
		els.pop();
		curent = els.top();
	}
}