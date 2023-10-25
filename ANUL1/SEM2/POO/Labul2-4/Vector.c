#include "Vector.h"
#include "Participant.h"
#include <assert.h>
#include <stdlib.h>

VectorDinamic* createVectorDinamic(int capacity, DestroyElementFunctionType destroyElemFct)
{
	VectorDinamic* vd = (VectorDinamic*)malloc(sizeof(VectorDinamic));
	// ne asiguram ca spatiul a fost alocat
	if (vd == NULL)
		return NULL;

	vd->capacity = capacity;
	vd->length = 0;

	// alocam spatiu pentru elemente
	vd->elems = (TElement*)malloc(capacity * sizeof(TElement));
	if (vd->elems == NULL)
		return NULL;

	// initializam pointer-ul functiei
	vd->destroyElemFct = destroyElemFct;

	return vd;
}

//functie pentru distrugerea vectorului
void destroyVector(VectorDinamic* vd)
{
	if (vd == NULL)
		return;

	// dealocam fiecare element
	for (int i = 0; i < vd->length; i++)
		vd->destroyElemFct(vd->elems[i]);

	// eliberam spatiul alocat pentru elementele vectorului
	free(vd->elems);
	vd->elems = NULL;
	// elibereaza spatiul alocat pentru vectorul dinamic
	free(vd);
}

// Redimensionam vectorul alocand mai mult spatiu
// Daca nu poate fi alocat mai mult spatiu, returneaza -1, altfel returneaza 0.
int resize(VectorDinamic* vd)
{
	if (vd == NULL)
		return -1;

	vd->capacity *= 2;

	//utilizam realloc
	TElement* aux = (TElement*)realloc(vd->elems, vd->capacity * sizeof(TElement));
	if (aux == NULL)
		return -1;
	vd->elems = aux;

	return 0;
}

//functie pentru adaugarea unui element in vector
void addTElem(VectorDinamic* vd, TElement t)
{
	if (vd == NULL)
		return;
	if (vd->elems == NULL)
		return;

	// redimensioneaza vectorul daca e necesar
	if (vd->length == vd->capacity)
		resize(vd);
	vd->elems[vd->length++] = t;
}

//functie pentru eliminarea unui element din vector de pe o anumita pozitie
void deleteTElem(VectorDinamic* vd, int pos)
{
	if (vd == NULL || pos < 0 || pos >= vd->length)
		return;

	vd->destroyElemFct(vd->elems[pos]);

	if (pos != vd->length)
		vd->elems[pos] = vd->elems[vd->length - 1];
	vd->length--;

}

//functie pentru lungimea vectorului dinamic
int getVectorLen(VectorDinamic* vd)
{
	if (vd == NULL)
		return -1;

	return vd->length;
}

//functie pentru returnarea unui element de pe o anumita pozitie
TElement get(VectorDinamic* vd, int pos)
{
	if (vd == NULL || pos < 0)
		return NULL;
	return vd->elems[pos];
}

//functie pentru inversarea elementelor vectorului dinamic
void swapTElemets(VectorDinamic* vd, int index1, int index2)
{
	if (vd == NULL)
	{
		return;
	}
	TElement* aux = vd->elems[index1];
	vd->elems[index1] = vd->elems[index2];
	vd->elems[index2] = aux;
	
}

// ------------------------------TESTS----------------------------------------
// functie pentru testare functii vector dinamic
void testVectorDinamic()
{
	VectorDinamic* vd = createVectorDinamic(5, destroyParticipant);
	//testam pentru NULL case
	swapTElemets(NULL, 1, 2);
	assert(get(NULL, 10) == NULL);
	assert(getVectorLen(NULL) == -1);
	deleteTElem(NULL, 10);
	deleteTElem(NULL, 1);
	addTElem(NULL, NULL);

	destroyVector(vd);
	// adaugam participanti 
	Participant* p1, * p2, * p3;
	p1 = createParticipant("a", "a", 100);
	p2 = createParticipant("b", "b", 200);
	p3 = createParticipant("c", "c", 300);
	VectorDinamic* vd2 = createVectorDinamic(1, destroyParticipant);
	addTElem(vd2, p1);
	addTElem(vd2, p2);
	addTElem(vd2, p3);
	assert(getVectorLen(vd2) == 3);
	deleteTElem(vd2, 2);
	assert(getVectorLen(vd2) == 2);
	swapTElemets(vd2, 1, 0);
	assert(getVectorLen(vd2) == 2);
	assert(getNume(vd2->elems[0]) == getNume(p2));
	assert(getPrenume(vd2->elems[0]) == getPrenume(p2));
	assert(getScor(vd2->elems[0]) == getScor(p2));
	assert(resize(NULL) == -1);
	destroyVector(vd2);
	destroyVector(NULL);
}
