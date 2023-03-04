#pragma warning(disable : 4996)
#pragma once

typedef struct {
    int numar_apartament, suma;
    char* tip;
} cheltuiala;


/*
    creeaza o noua instanta de tip cheltuiala
    date de intrare: numar - integer
                     suma - integer
                     tip - adresa unui sir de caractere
    date de iesire: cheltuiala* - adresa unei cheltuieli alocata dinamic
*/
cheltuiala* creeaza_cheltuiala(int, int, char*);


/*
    returneaza numarul de apartament a unei instante de tip cheltuiala
    date de intrare: pay - instanta de tip cheltuiala
    date de iesire: integer
*/
int getNumarApartament(cheltuiala*);


/*
    returneaza suma unei instante de tip cheltuiala
    date de intrare: pay - instanta de tip cheltuiala
    date de iesire: integer
*/
int getSuma(cheltuiala*);


/*
    returneaza tipul unei instante de tip cheltuiala
    date de intrare: pay - instanta de tip cheltuiala
    date de iesire: char* - adresa unui sir de caractere
*/
char* getTip(cheltuiala*);


/*
    modifica numarul de apartament a unei instante de tip cheltuiala alocata dinamic cu "new_numar_apartament"
    date de intrare: pay - o isntanta de tip cheltuiala
                     new_numar_apartament - integer
    return: -
*/
void setNumarApartament(cheltuiala*, int);


/*
    modifica suma unei instante de tip cheltuiala alocata dinamic cu "new_suma"
    date de intrare: pay - o isntanta de tip cheltuiala
                     new_suma - integer
    return: -
*/
void setSuma(cheltuiala*, int);


/*
    modifica tipul unei instante de tip cheltuiala alocata dinamic cu "new_tip"
    date de intrare: pay - o isntanta de tip cheltuiala
                     new_tip - pointer catre un sir de caractere
    return: -
*/
void setTip(cheltuiala* pay, char* tip_nou);


/*
    functie care distruge o instanta de tip cheltuiala
    date de intrare: pay - o instanta de tip cheltuiala
*/
void destructor_cheltuiala(cheltuiala* pay);


/*
    functie care primeste ca parametrii 2 instante de tip cheltuiala si le interschimba valorile
    date de intrare: pay1 - instanta de tip cheltuiala
                     pay2 - instanta de tip cheltuiala
    date de iesire: instantele de tip cheltuiala interschimbate
*/
void swap_cheltuiala(cheltuiala*, cheltuiala*);