#include "repo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

vectorDinamic* creeaza_vector() {
    vectorDinamic* v = (vectorDinamic*)malloc(sizeof(vectorDinamic));
    v->cp = 1;
    v->nr = 0;
    v->elem = (cheltuiala**)malloc(sizeof(cheltuiala*) * v->cp);
    return v;
}

void destructor_vector(vectorDinamic* vect) {
    for (int i = 0; i < vect->nr; i++)
        destructor_cheltuiala(vect->elem[i]);
    free(vect->elem);
    free(vect);
}


int size_of_vector(vectorDinamic vect) {
    return vect.nr;
}

void adauga_cheltuiala(cheltuiala* pay, vectorDinamic* vect) {
    if (vect->nr >= vect->cp) {
        vect->cp *= 2;
        cheltuiala** new_elem = (cheltuiala**)malloc(sizeof(cheltuiala*) * vect->cp);
        int i;
        for (i = 0; i < vect->nr; i++) {
            new_elem[i] = vect->elem[i];
        }
        free(vect->elem);
        vect->elem = new_elem;
    }
    vect->elem[vect->nr] = pay;
    vect->nr++;
}

cheltuiala* exista_cheltuiala(cheltuiala* pay, vectorDinamic* vect) {
    int i = 0;
    for (; i < vect->nr; i++)
        if (vect->elem[i]->numar_apartament == pay->numar_apartament
            && vect->elem[i]->suma == pay->suma
            && !strcmp(vect->elem[i]->tip, pay->tip))
            return vect->elem[i];
    return NULL;
}


void modifica_cheltuiala(cheltuiala* pay, cheltuiala* elem) {
    elem->suma = pay->suma;
    free(elem->tip);
    elem->tip = (char*)malloc(sizeof(char) * (strlen(pay->tip) + 1));
    strcpy(elem->tip, pay->tip);
}


int sterge_cheltuiala(cheltuiala* pay, vectorDinamic* vect) {
    int i, ok = 0;
    for (i = 0; i < vect->nr; i++) {
        if (!ok && vect->elem[i]->numar_apartament == pay->numar_apartament
            && vect->elem[i]->suma == pay->suma
            && !strcmp(vect->elem[i]->tip, pay->tip)) {
            ok = 1;
            destructor_cheltuiala(vect->elem[i]);
        }
        if (ok && i < vect->nr - 1) {
            vect->elem[i] = vect->elem[i + 1];
        }
    }
    if (ok) {
        vect->nr--;
    }
    if (vect->nr < vect->cp / 4) {
        vect->cp /= 4;
        cheltuiala** new_elem = (cheltuiala**)malloc(sizeof(cheltuiala*) * vect->cp);
        for (i = 0; i < vect->nr; i++) {
            new_elem[i] = vect->elem[i];
        }
        free(vect->elem);
        vect->elem = new_elem;
    }
    return ok;
}


void copy(vectorDinamic* vect_copy, vectorDinamic* vect) {
    int i = 0;
    for (; i < vect->nr; i++) {
        char* tip = (char*)malloc((strlen(vect->elem[i]->tip) + 1) * sizeof(char));
        strcpy(tip, vect->elem[i]->tip);
        cheltuiala* pay = creeaza_cheltuiala(vect->elem[i]->numar_apartament, vect->elem[i]->suma, tip);
        adauga_cheltuiala(pay, vect_copy);
        free(tip);
    }
}


void sort(vectorDinamic* vect, int (*cmp)(cheltuiala*, cheltuiala*)) {
    int i, j;
    for (i = 0; i < vect->nr - 1; i++)
        for (j = i + 1; j < vect->nr; j++)
            if (cmp(vect->elem[i], vect->elem[j])) {
                cheltuiala* aux = vect->elem[i];
                vect->elem[i] = vect->elem[j];
                vect->elem[j] = aux;
                //swap_cheltuiala(vect->elem[i], vect->elem[j]); 
            }
}