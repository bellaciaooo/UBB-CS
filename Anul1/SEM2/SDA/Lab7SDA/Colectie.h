#pragma once;

#include <vector>

typedef int TElem;

using std::pair;
typedef pair<TElem, int> TComparabil;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	int cp;    //capacitatea
	int size;  //dimensiunea 
	TComparabil* elems; //elementele 
	int* stang;   //fii stangi
	int* drept;   //fii drepti
	int rad;      //radacina
	int primLiber = 0;  //primul spatiu liber disponibil in lista

	//functie pentru dealocare spatiu pentru un element
	void dealoca(int pos);

	//functie pentru alocare spatiu pentru un nou element
	int aloca();

	//functie pentru redimensionare
	void resize();

	// sterge recursiv
	bool stergeRecursiv(int curent, int anterior, TElem e);

	//returneaza pozitia elementului minim al unui subarbore 
	int minim(int pos);

	//returneaza pozitia elementului maxim al unui subarbore
	int maxim(int pos);

	//functie pentru crearea unui nod nou in arbore
	//returneaza pozitia unde este adaugat elementul
	int creeazaNod(TElem e);

public:
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;

	//returneaza diferenta dintre valoarea maxima si cea minima
	//daca colectia este vida, se returneaza -1
	int diferentaMaxMin();

	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();


};

