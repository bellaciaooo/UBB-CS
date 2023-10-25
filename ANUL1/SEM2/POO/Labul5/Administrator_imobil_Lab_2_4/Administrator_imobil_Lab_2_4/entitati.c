#include <stdio.h>
#include "entitati.h"
#include <malloc.h>
#include <string.h>

cheltuiala* creeaza_cheltuiala(int numar, int suma, char* tip) {
    cheltuiala* pay = (cheltuiala*)malloc(sizeof(cheltuiala));
    if (pay) {
        pay->numar_apartament = numar;
        pay->suma = suma;
        pay->tip = (char*)malloc(sizeof(char) * (strlen(tip) + 1));
        if (pay->tip)
            strcpy(pay->tip, tip);
    }
    return pay;
}

int getNumarApartament(cheltuiala* pay) {
    return pay->numar_apartament;
}

int getSuma(cheltuiala* pay) {
    return pay->suma;
}

char* getTip(cheltuiala* pay) {
    return pay->tip;
}

void setNumarApartament(cheltuiala* pay, int new_numar_apartament) {
    pay->numar_apartament = new_numar_apartament;
}

void setSuma(cheltuiala* pay, int new_suma) {
    pay->suma = new_suma;
}

void setTip(cheltuiala* pay, char* new_tip) {
    free(pay->tip);
    pay->tip = (char*)malloc(sizeof(char) * (strlen(new_tip) + 1));
    if (pay->tip)
        strcpy(pay->tip, new_tip);
}

void destructor_cheltuiala(cheltuiala* pay) {
    free(pay->tip);
    free(pay);
}


void swap_cheltuiala(cheltuiala* pay1, cheltuiala* pay2) {
    int aux1 = pay1->numar_apartament;
    pay1->numar_apartament = pay2->numar_apartament;
    pay2->numar_apartament = aux1;

    int aux2 = pay1->suma;
    pay1->suma = pay2->suma;
    pay2->suma = aux2;

    char aux3[15];
    strcpy(aux3, pay1->tip);
    free(pay1->tip);
    pay1->tip = (char*)malloc((strlen(pay2->tip) + 1) * sizeof(char));
    strcpy(pay1->tip, pay2->tip);
    free(pay2->tip);
    pay2->tip = (char*)malloc((strlen(aux3) + 1) * sizeof(char));
    strcpy(pay2->tip, aux3);
}
