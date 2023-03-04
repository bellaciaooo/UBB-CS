#pragma warning(disable : 4996)
#pragma once

/*
    functie care primeste campurile unei instante cheltuiala si le valideaza
    date de intrare: numar_apartament - integer
                     suma - integer
                     tip - ponter catre un sir de caractere
    date de iesire: erori - pointer catre un sir de caractere(in care ne salvam mesajul de eroare)
*/
void valideaza_cheltuiala(int, int, char*, char*);

/*
    functie care primeste numarul de apartament a unei instante cheltuiala si il valideaza
    date de intrare: suma - integer
    date de iesire: erori - pointer catre un sir de caractere(in care ne salvam mesajul de eroare)
*/
void valideaza_ap(int, char*);

/*
    functie care primeste suma unei instante cheltuiala si o valideaza
    date de intrare: numar_apartament - integer
    date de iesire: erori - pointer catre un sir de caractere(in care ne salvam mesajul de eroare)
*/
void valideaza_suma(int, char*);

/*
    functie care primeste tipul unei instante cheltuiala si il valideaza
    date de intrare: tip - ponter catre un sir de caractere
    date de iesire: erori - pointer catre un sir de caractere(in care ne salvam mesajul de eroare)
*/
void valideaza_tip(char*, char*);