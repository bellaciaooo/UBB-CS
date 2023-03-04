#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorColectie;

struct element
{
	TElem value;
	int frecv;
};

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	int len;
	int maxSize;
	int usedSize;
	element* elems;
	int* next;
	int prim;

public:
	//constructorul implicit
	Colectie();

	void resize();

	int primLiber();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;

	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//elimina toate elementele colectiei
	void goleste();

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();

};
