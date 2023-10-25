#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>

IteratorColectie::IteratorColectie(const Colectie& c) : col(c)
{
	//Overall Complexity: theta(1)
	curent = c.prim;
	curent_frecv = 1;
}

void IteratorColectie::prim()
{
	//Overall Complexity: theta(1)
	curent = col.prim;
	curent_frecv = 1;
}


void IteratorColectie::urmator()
{
	//Overall Complexity: theta(1)
	if (!valid())
		throw std::exception();

	curent_frecv++;
	if (curent_frecv > col.elems[curent].frecv)
	{
		curent_frecv = 1;
		curent = col.next[curent];
	}
}


bool IteratorColectie::valid() const
{
	//Overall Complexity: theta(1)
	return curent != -1 && col.elems[curent].frecv != 0;
}



TElem IteratorColectie::element() const
{
	if (!valid())
		throw std::exception();
	return col.elems[curent].value;
}
