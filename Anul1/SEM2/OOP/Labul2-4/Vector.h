#pragma once
#define CAPACITY 10

typedef void* TElement;
typedef void (*DestroyElementFunctionType)(TElement);

typedef struct
{
	TElement* elems;
	int length;			// lungimea actuala a vectorului
	int capacity;		// capacitatea maxima a vectorului
	DestroyElementFunctionType destroyElemFct; // functie care distruge elementele de tip TElement din vector
} VectorDinamic;


/// <summary>
/// Functie ce creeaza vectorul dinamic.
/// </summary>
/// <param name="capacity"></param>
/// <param name="destroyElemFct"></param>
/// <returns></returns>
VectorDinamic* createVectorDinamic(int capacity, DestroyElementFunctionType destroyElemFct);

/// <summary>
/// Functie care distruge vectorul dinamic.
/// </summary>
/// <param name="vd"></param>
void destroyVector(VectorDinamic* vd);

/// <summary>
/// Functie care adauga un element de tip TElement intr-un vector dinamic.
/// </summary>
/// <param name="vd"></param> 
/// <param name="t"></param>
void addTElem(VectorDinamic* vd, TElement t);

/// <summary>
/// Functie care sterge un element de tip TElement dintr-un vector dinamic.
/// </summary>
/// <param name="vd"></param>
/// <param name="pos"></param>
void deleteTElem(VectorDinamic* vd, int pos);

/// <summary>
/// Functie care returneaza lungimea vectorului dinamic.
/// </summary>
/// <param name="vd"></param>
/// <returns></returns>
int getVectorLen(VectorDinamic* vd);

/// <summary>
/// Functie care interschimba elementele dintr-un vector dinamic in functie de indecsii introdusi.
/// </summary>
/// <param name="vd"></param>
/// <param name="index1"></param>
/// <param name="index2"></param>
void swapTElemets(VectorDinamic* vd, int index1, int index2);

/// <summary>
/// Functie care returneaza un TElement de pe pozitia 'pos' a vectorului dinamic dat.
/// </summary>
/// <param name="vd"></param>
/// <param name="pos"></param>
/// <returns></returns>
TElement get(VectorDinamic* vd, int pos);

void testVectorDinamic();