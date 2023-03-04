#include "repo.h"
#include "entitati.h"
#include "validare.h"
#include <string.h>
#include <stdio.h>

void srv_adauga_cheltuiala(int numar_apartament, int suma, char* tip, vectorDinamic* vect, char* erori) {
    valideaza_cheltuiala(numar_apartament, suma, tip, erori);
    if (strlen(erori) == 0) {
        cheltuiala* pay = creeaza_cheltuiala(numar_apartament, suma, tip);
        if (!exista_cheltuiala(pay, vect))
            adauga_cheltuiala(pay, vect);
        else {
            strcat(erori, "Cheltuiala deja existenta.\n");
            destructor_cheltuiala(pay);
        }
    }
}


void srv_modifica_cheltuiala(int numar_apartament, int new_suma, char* new_tip, char* erori, cheltuiala* elem) {
    valideaza_cheltuiala(numar_apartament, new_suma, new_tip, erori);
    if (strlen(erori) == 0) {
        cheltuiala* pay = creeaza_cheltuiala(numar_apartament, new_suma, new_tip);
        modifica_cheltuiala(pay, elem);
        destructor_cheltuiala(pay);
    }
}


void srv_exista_cheltuiala(int numar_apartament, int suma, char* tip, vectorDinamic* vect, char* erori, cheltuiala** elem) {
    valideaza_cheltuiala(numar_apartament, suma, tip, erori);
    if (strlen(erori) == 0) {
        cheltuiala* pay = creeaza_cheltuiala(numar_apartament, suma, tip);
        *elem = exista_cheltuiala(pay, vect);
        destructor_cheltuiala(pay);
        if (*elem != NULL)
            strcat(erori, "Cheltuiala deja existenta.\n");
    }
}


void srv_sterge_cheltuiala(int numar_apartament, int suma, char* tip, vectorDinamic* vect, char* erori) {
    valideaza_cheltuiala(numar_apartament, suma, tip, erori);
    if (strlen(erori) == 0) {
        cheltuiala* pay = creeaza_cheltuiala(numar_apartament, suma, tip);
        int stare = sterge_cheltuiala(pay, vect);
        destructor_cheltuiala(pay);
        if (stare == 0)
            strcat(erori, "Nu exista aceasta cheltuiala.");
    }
}


void srv_destructor_vector(vectorDinamic* vect) {
    destructor_vector(vect);
}


void srv_sort(vectorDinamic* vect, int (*cmp)(cheltuiala*, cheltuiala*)) {
    sort(vect, cmp);
}

void srv_copy(vectorDinamic* vect_copy, vectorDinamic* vect) {
    copy(vect_copy, vect);
}