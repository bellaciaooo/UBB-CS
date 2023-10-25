#pragma once
#include "repo.h"

/*
    functie care primeste atributele unei cheltuieli, le valideaza, verifica daca cheltuiala nu mai exista deja
    (dupa toate atributele), creeaza o instanta de tip cheltuiala si ii salveaza adresa intr-un vector.
    date de intrare: numar_apartament - integer
                     suma - integer
                     tip - pointer catre un sir de caractere
                     vect - pointer catre o instanta de tip "vectorDinamic"
                     erori - pointer catre un sir de caractere(in care salvam mesajul de eroare)
*/
void srv_adauga_cheltuiala(int, int, char*, vectorDinamic*, char*);


/*
    functie care primeste atributele unei cheltuieli, le valideaza si dupa modifica
    instanta de tip cheltuiala cu noile valori
    date de intrare: numar_apartament - integer
                     new_suma - integer
                     new_tip - pointer catre un sir de caractere
                     erori - pointer catre un sir de caractere(in care salvam mesajul de eroare)
                     elem - pointer catre instanta de tip cheltuiala care trebuie modificata
*/
void srv_modifica_cheltuiala(int, int, char*, char*, cheltuiala*);


/*
    functie care primeste atributele unei cheltuieli, le valideaza si dupa verifica daca exista
    deja instanta de tip cheltuiala
    date de intrare: numar_apartament - integer
                     suma - integer
                     tip - pointer catre un sir de caractere
                     vect - pointer catre o instanta de tip "vectorDinamic"
                     erori - pointer catre un sir de caractere(in care salvam mesajul de eroare)
                     elem - pointer catre o instanta de tip cheltuiala
    date de iesire:  elem primeste pointerul cautat din lista de instante de tip cheltuiala
*/
void srv_exista_cheltuiala(int, int, char*, vectorDinamic*, char*, cheltuiala**);


/*
    functie care primeste atributele unei cheltuieli, le valideaza si dupa sterge
    cheltuiala cautata daca exista
    date de intrare: numar_apartament - integer
                     suma - integer
                     tip - pointer catre un sir de caractere
                     vect - pointer catre o instanta de tip "vectorDinamic"
                     erori - pointer catre un sir de caractere(in care salvam mesajul de eroare)
*/
void srv_sterge_cheltuiala(int, int, char*, vectorDinamic*, char*);

/*
    functie care primeste ca parametru un vector alocat dinamic si ii dealoca memoria
    date de intrare: vect - pointer catre o instanta de tip "vectorDinamic"
*/
void srv_destructor_vector(vectorDinamic*);


/*
    functie care primeste ca parametru un vector alocat dinamic si il sorteaza dupa functie
    date de intrare: vect - pointer catre o instanta de tip "vectorDinamic"
                     cmp - pointer la o functie care returneaza un integer si are ca parametrii 2 pointer la cate o instanta de tip cheltuiala
    date de iesire: vectorul sortat
*/
void srv_sort(vectorDinamic*, int (*)(cheltuiala*, cheltuiala*));


/*
    functie care copie datele dintr-un vector alocat dinamic intr-un alt vector alocandu-i si acestuia memorie
    date de intrare: vect_copy - pointer catre o instanta de tip "vectorDinamic"
                     vect - pointer catre o instanta de tip "vectorDinamic"
    date de iesire: datele din vect sunt salvate in vect_copy
*/
void srv_copy(vectorDinamic*, vectorDinamic*);