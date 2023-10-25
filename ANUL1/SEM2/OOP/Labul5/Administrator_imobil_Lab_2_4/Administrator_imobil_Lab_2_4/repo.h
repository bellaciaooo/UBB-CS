#pragma warning(disable : 4996)
#pragma once
#include "entitati.h"

typedef struct vectorDinamic {
    int nr;
    int cp; // capacitate
    cheltuiala** elem;
} vectorDinamic;

/*
    creeaza o noua entitate de tip "vectorDinamic"
    date de intrare: -
*/
vectorDinamic* creeaza_vector();

/*  functie care elibereaza memoria de spatiul ocupat de instantele
    date de intrare : lista - o lista de adrese de cheltuieli alocate dinamic
    date de iesire : -
*/
void destructor_vector(vectorDinamic*);

/*
    functie care returneaza dimensiunea vectorului static
    date de intrare: vect - lista de cheltuieli
    return: integer
*/
int size_of_vector(vectorDinamic);


/*
    functie care adauga o adresa a unei instante de tip cheltuiala intr-o lista de adrese de tip cheltuiala
    date de intrare: pay - adresa unei instante de tip cheltuiala
                     vect - lista de adrese de cheltuieli
    date de iesire: -
*/
void adauga_cheltuiala(cheltuiala*, vectorDinamic*);


/*
    functie care verifica daca exista deja cheltuiala in vector
    date de intrare: pay - adresa unei instante de tip cheltuiala
                     vect - lista de adrese de cheltuieli
    date de iesire: 1 daca exista cheltuiala deja
                    0 altfel
*/
cheltuiala* exista_cheltuiala(cheltuiala*, vectorDinamic*);

/*
    functie care sterge o cheltuiala, daca exista.
    date de intrare: pay - adresa unei instante de tip cheltuiala
                     vect - lista de adrese de cheltuieli
    date de iesire: 1 daca s-a sters cheltuiala
                    0 altfel
*/
int sterge_cheltuiala(cheltuiala*, vectorDinamic*);


/*
    functie care modifica o cheltuiala
    date de intrare: pay - adresa unei instante de tip cheltuiala
                     elem - adresa elementului care trebuie modificat
*/
void modifica_cheltuiala(cheltuiala*, cheltuiala*);


/*
    functie care primeste ca parametru un vector alocat dinamic si il sorteaza dupa functie
    date de intrare: vect - pointer catre o instanta de tip "vectorDinamic"
                     cmp - pointer la o functie care returneaza un integer si are ca parametrii 2 pointer la cate o instanta de tip cheltuiala
    date de iesire: vectorul sortat
*/
void sort(vectorDinamic*, int (*)(cheltuiala*, cheltuiala*));


/*
    functie care copie datele dintr-un vector alocat dinamic intr-un alt vector alocandu-i si acestuia memorie
    date de intrare: vect_copy - pointer catre o instanta de tip "vectorDinamic"
                     vect - pointer catre o instanta de tip "vectorDinamic"
    date de iesire: datele din vect sunt salvate in vect_copy
*/
void copy(vectorDinamic*, vectorDinamic*);