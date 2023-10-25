#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie()
{
	len = 0;
	usedSize = 0;
	maxSize = 2;
	elems = new element[2];
	next = new int[2];
	prim = 0;
	elems[0].frecv = 0;
	elems[1].frecv = 0;
}

void Colectie::resize()
{
	//dublam capacitatea vectorilor
	maxSize *= 2;
	int* new_next = new int[maxSize];
	//refacem vechile legaturi
	for (int i = 0; i < maxSize / 2; i++)
		new_next[i] = next[i];
	//dealocam zona veche de memorie
	delete[] next;
	//se pointeaza spre noua zona de memorie
	next = new_next;
	element* e = new element[maxSize];
	//refacem vechile legaturi
	for (int i = 0; i < maxSize / 2; i++)
		e[i] = elems[i];
	for (int i = maxSize / 2; i < maxSize; i++)
		e[i].frecv = 0;
	//dealocam zona veche de memorie
	delete[] elems;
	//se pointeaza spre noua zona de memorie
	elems = e;
}

int Colectie::primLiber()
{   
	//Overall Complexity: O(n)
	int pos = 0;
	while (elems[pos].frecv != 0)
		pos++;
	return pos;
}

void Colectie::adauga(TElem elem)
{   
	//Overall Complexity: O(n)
	// lista e vida
	if (vida())
	{
		elems[prim].value = elem;
		elems[prim].frecv = 1;
		next[prim] = -1;
		usedSize++;
	}
	// elementul e pe prima pozitie
	else if (elems[prim].value == elem)
		elems[prim].frecv++;
	// in caz contrar il cautam
	else
	{
		int pos = prim;

		while (next[pos] != -1)
		{
			if (elems[next[pos]].value == elem)
			{
				elems[next[pos]].frecv++;
				break;
			}

			pos = next[pos];
		}
		// daca next[pos] ajunge sa fie -1 atunci am cautat in toata lista si nu am gasit elementul
		// deci trebuie sa il adaugam la sfarsitul listei
		if (next[pos] == -1)
		{
			if (usedSize == maxSize)
				resize();

			int addpos = primLiber();
			next[pos] = addpos;
			elems[addpos].value = elem;
			elems[addpos].frecv = 1;
			next[addpos] = -1;
			usedSize++;
		}
	}

	len++;
}


bool Colectie::sterge(TElem elem)
{
	//Overall Complexity: O(n)
	// lista e vida
	if (vida())
		return false;
	// elem este pe prima pozitie in lista
	else if (elems[prim].value == elem)
	{
		elems[prim].frecv--;
		if (!elems[prim].frecv)
			prim = next[prim] == -1 ? 0 : next[prim];
		len--;
		return true;
	}
	// cautam elementul in restul listei
	else
	{
		int pos = prim;

		while (next[pos] != -1)
		{
			if (elems[next[pos]].value == elem)
			{
				elems[next[pos]].frecv--;
				if (!elems[next[pos]].frecv)
					next[pos] = next[next[pos]];
				len--;
				return true;
			}

			pos = next[pos];
		}
	}

	return false;
}


bool Colectie::cauta(TElem elem) const
{
	//Overall Complexity: O(n)
	if (vida())
		return false;

	int pos = prim;
	while (pos != -1)
	{
		if (elems[pos].value == elem)
			return true;
		pos = next[pos];
	}

	return false;
}

int Colectie::nrAparitii(TElem elem) const
{
	//Overall Complexity: O(n)
	if (vida())
		return false;

	int pos = prim;
	while (pos != -1)
	{
		if (elems[pos].value == elem)
			return elems[pos].frecv;
		pos = next[pos];
	}

	return 0;
}


int Colectie::dim() const
{
	//Overall Complexity: theta(1)
	return len;
}


bool Colectie::vida() const
{
	//Overall Complexity: theta(1)
	return elems[prim].frecv == 0;
}

void Colectie::goleste()
{
	//Overall complexity: theta(n)
    /*
	* PSEUDOCOD
	* subalgoritm goleste
	*   pos <- l.prim
	*   cattimp pos != -1 executa
	*       cattimp l.elem[pos].frecv > 0 executa
	*               sterge(l.elems[pos].value);
	*       sfcattimp
	*       pos <- l.next[pos]
	*   sfcattimp
	* sf subalgoritm
	*/
	int pos = prim;
	while (pos != -1)
	{
		while(elems[pos].frecv > 0)
			sterge(elems[pos].value);
		pos = next[pos];
	}
}

IteratorColectie Colectie::iterator() const
{
	//Overall Complexity: theta(1)
	return  IteratorColectie(*this);
}


Colectie::~Colectie()
{
	delete[] elems;
	delete[] next;
}
