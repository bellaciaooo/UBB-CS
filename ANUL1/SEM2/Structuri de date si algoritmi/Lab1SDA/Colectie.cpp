#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
	if (e1 <= e2)
		return true;
	return false;
}

Colectie::Colectie() {
	//setam capacitatea
	this->cp = 2;

	//setam dimensiunea vectorului
	this->size = 0;

	//alocam spatiu de memorare pt vectorul de perechi
	this->p = new pair<TElem, int>[cp];
}

void Colectie::resize() {
	//alocam un spatiu de capacitate dubla
	pair <TElem, int>* pNou = new pair <TElem, int>[2 * cp];

	//copiem vechile valori in zona noua alocata
	for (int i = 0; i < this->size; i++)
	{
		pNou[i].first = this->p[i].first;
		pNou[i].second = this->p[i].second;
	}

	//dublam capacitatea
	cp = 2 * cp;

	//dealocam vechea zona de memorie
	delete[] p;

	//vectorul pointeaza spre noua zona de memorie
	this->p = pNou;
}

void Colectie::adauga(TElem e) {
	//Worst case: theta(n)
	//Overall: O(n)
	//Best case: theta(1)

	//daca s-a atins capacitatea maxima , redimensionam
	if (this->size == this->cp)
		resize();

	//adaugam pe pozitia corespunzatoare in functie de relatie
	if (cauta(e) == true)
	{
		int i;
		for (i = 0; i < this->size && rel(this->p[i].first, e) == true; i++);
		i--;
		this->p[i].second++;
	}
	else 
	{
		int i = 0,j = 0;
		for (i = 0; i < this->size && rel(this->p[i].first,e) == true; i++);
		this->size++;
		for (j = this->size-1; j > i; j--)
		{
			p[j].first = p[j - 1].first;
			p[j].second = p[j - 1].second;
		}
		p[i].first = e;
		p[i].second = 1;
	}

}


bool Colectie::sterge(TElem e) {
	//Worst case: theta(n)
	//Overall: O(n)
	//Best case: theta(1)
	int i = 0;
	while (i < this->size && rel(this->p[i].first, e) == true)
	{
		if (this->p[i].first == e)
		{
			if (p[i].second == 1)
			{
				for (int j = i; j < this->size - 1; j++)
				{
					p[j].first = p[j + 1].first;
					p[j].second = p[j + 1].second;
				}
				this->size--;
				return true;
			}
			else
			{
				p[i].second--;
				return true;
			}

		}
		else i++;
	}
	return false;
}


bool Colectie::cauta(TElem elem) const {
	//Worst case: theta(n)
	//Overall: O(n)
	//Best case: theta(1)
	for (int i = 0; i < this->size; i++)
		if (this->p[i].first == elem)
			return true;
	return false;
}


int Colectie::nrAparitii(TElem elem) const {
	//Worst case: theta(n)
	//Overall: O(n)
	//Best case: theta(1)
	for (int i = 0; i < this->size; i++)
		if (this->p[i].first == elem)
			return this->p[i].second;
	return 0;
}


int Colectie::dim() const {
	//Worst case: theta(n)
	//Overall: theta(n)
	//Best case: theta(n)
	int n = 0;
	for (int i = 0; i < this->size; i++)
		n = n + this->p[i].second;
	return n;
}


bool Colectie::vida() const {
	//Worst case: theta(1)
	//Overall: theta(1)
	//Best case: theta(1)
	if (this->size != 0)
		return false;
	return true;
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	//eliberam zona de memorie alocata vectorului
	delete[] p;
}
