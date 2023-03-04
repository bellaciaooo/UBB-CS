#include "entitati.h"
#include "teste.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "validare.h"
#include "repo.h"
#include "service.h"
#include "utils.h"
#include <limits.h>

void run_teste_domeniu_cheltuiala() {
    cheltuiala* test_pay = creeaza_cheltuiala(1, 100, "apa");
    assert(getNumarApartament(test_pay) == 1);
    assert(getSuma(test_pay) == 100);
    assert(!strcmp(getTip(test_pay), "apa"));

    setNumarApartament(test_pay, 4);
    assert(getNumarApartament(test_pay) == 4);

    setSuma(test_pay, 120);
    assert(getSuma(test_pay) == 120);

    setTip(test_pay, "canal");
    assert(!strcmp(getTip(test_pay), "canal"));

    cheltuiala* test_pay2 = creeaza_cheltuiala(2, 50, "incalzire");
    swap_cheltuiala(test_pay, test_pay2);
    assert(test_pay->numar_apartament == 2);
    assert(test_pay->suma == 50);
    assert(!strcmp(test_pay->tip, "incalzire"));

    assert(test_pay2->numar_apartament == 4);
    assert(test_pay2->suma == 120);
    assert(!strcmp(test_pay2->tip, "canal"));

    destructor_cheltuiala(test_pay);
    destructor_cheltuiala(test_pay2);
}


void run_teste_validator_cheltuiala() {
    char erori[300];
    valideaza_cheltuiala(1, 100, "aa", erori);
    assert(!strcmp(erori, "Tipul trebuie sa fie apa/canal/incalzire/gaz.\n"));
    valideaza_cheltuiala(1, -1, "apa", erori);
    assert(!strcmp(erori, "Suma trebuie sa fie pozitiva.\n"));
    valideaza_cheltuiala(-1, 1, "incalzire", erori);
    assert(!strcmp(erori, "Numarul de apartament trebuie sa fie pozitiv.\n"));
    valideaza_cheltuiala(-1, -1, "apaa", erori);
    assert(!strcmp(erori, "Numarul de apartament trebuie sa fie pozitiv.\nSuma trebuie sa fie pozitiva.\nTipul trebuie sa fie apa/canal/incalzire/gaz.\n"));
    valideaza_cheltuiala(-1, -1, "apa", erori);
    assert(!strcmp(erori, "Numarul de apartament trebuie sa fie pozitiv.\nSuma trebuie sa fie pozitiva.\n"));

    valideaza_suma(-12, erori);
    assert(!strcmp(erori, "Suma trebuie sa fie pozitiva.\n"));

    valideaza_ap(-1, erori);
    assert(!strcmp(erori, "Numarul de apartament trebuie sa fie pozitiv.\n"));

    valideaza_tip("ap", erori);
    assert(!strcmp(erori, "Tipul trebuie sa fie apa/canal/incalzire/gaz.\n"));

    valideaza_suma(100, erori);
    assert(strlen(erori) == 0);
    valideaza_ap(1, erori);
    assert(strlen(erori) == 0);
    valideaza_tip("apa", erori);
    assert(strlen(erori) == 0);

    //strcpy(erori, "\0");
    valideaza_cheltuiala(1, 100, "apa", erori);
    assert(strlen(erori) == 0);
}


void run_teste_repo_cheltuiala() {
    vectorDinamic* vect = creeaza_vector();
    assert(vect->nr == 0);
    cheltuiala* pay = creeaza_cheltuiala(1, 1, "apa");

    adauga_cheltuiala(pay, vect);
    assert(vect->nr == 1);

    assert(exista_cheltuiala(pay, vect) != NULL);
    assert(size_of_vector(*vect) == vect->nr);
    cheltuiala* elem = vect->elem[0];
    cheltuiala* pay2 = creeaza_cheltuiala(1, 2, "incalzire");
    modifica_cheltuiala(pay2, elem);
    assert(!strcmp(vect->elem[0]->tip, "incalzire"));
    int r = sterge_cheltuiala(pay2, vect);
    assert(r == 1);
    assert(vect->nr == 0);

    int r2 = sterge_cheltuiala(pay, vect);
    assert(r2 == 0);
    assert(vect->nr == 0);

    destructor_cheltuiala(pay2);

    cheltuiala* a1 = creeaza_cheltuiala(4, 4, "apa");
    cheltuiala* a2 = creeaza_cheltuiala(5, 5, "apa");
    cheltuiala* a3 = creeaza_cheltuiala(6, 6, "apa");
    cheltuiala* a4 = creeaza_cheltuiala(7, 7, "apa");
    cheltuiala* a5 = creeaza_cheltuiala(8, 8, "apa");
    cheltuiala* a6 = creeaza_cheltuiala(9, 9, "apa");
    cheltuiala* a7 = creeaza_cheltuiala(10, 10, "apa");
    cheltuiala* a8 = creeaza_cheltuiala(11, 11, "apa");
    cheltuiala* a9 = creeaza_cheltuiala(12, 12, "apa");
    cheltuiala* a10 = creeaza_cheltuiala(13, 13, "incalzire");
    adauga_cheltuiala(a1, vect);
    adauga_cheltuiala(a2, vect);
    adauga_cheltuiala(a3, vect);
    adauga_cheltuiala(a4, vect);
    adauga_cheltuiala(a5, vect);
    adauga_cheltuiala(a6, vect);
    adauga_cheltuiala(a7, vect);
    adauga_cheltuiala(a8, vect);
    adauga_cheltuiala(a9, vect);
    adauga_cheltuiala(a10, vect);

    r = sterge_cheltuiala(a1, vect);
    r = sterge_cheltuiala(a2, vect);
    r = sterge_cheltuiala(a3, vect);
    r = sterge_cheltuiala(a4, vect);
    r = sterge_cheltuiala(a5, vect);
    r = sterge_cheltuiala(a6, vect);
    r = sterge_cheltuiala(a7, vect);


    vectorDinamic* vect2 = creeaza_vector();
    copy(vect2, vect);
    int i = 0;
    for (; i < vect->nr; i++)
        assert(vect->elem[i]->numar_apartament == vect2->elem[i]->numar_apartament),
        assert(vect->elem[i]->suma == vect2->elem[i]->suma),
        assert(!strcmp(vect->elem[i]->tip, vect2->elem[i]->tip));

    sort(vect2, comparaSumaCresc);
    for (i = 0; i < vect2->nr; i++)
        assert(vect2->elem[i]->suma == 11 + i);

    sort(vect2, comparaSumaDescresc);
    for (i = 0; i < vect2->nr; i++)
        assert(vect2->elem[i]->suma == 13 - i);

    sort(vect2, comparaTipCresc);
    for (i = 0; i < vect2->nr; i++)
        if (i == 2)
            assert(!strcmp(vect2->elem[i]->tip, "incalzire"));
        else
            assert(!strcmp(vect2->elem[i]->tip, "apa"));

    sort(vect2, comparaTipDescresc);
    for (i = 0; i < vect2->nr; i++)
        if (i == 0)
            assert(!strcmp(vect2->elem[i]->tip, "incalzire"));
        else
            assert(!strcmp(vect2->elem[i]->tip, "apa"));

    destructor_vector(vect);
    destructor_vector(vect2);
}


void run_teste_service_cheltuiala() {
    vectorDinamic* vect = creeaza_vector();
    char erori[202] = "";
    srv_adauga_cheltuiala(1, 1, "apa", vect, erori);
    assert(vect->nr == 1);
    assert(strlen(erori) == 0);

    srv_adauga_cheltuiala(-1, 1, "apa", vect, erori);
    assert(vect->nr == 1);
    assert(!strcmp(erori, "Numarul de apartament trebuie sa fie pozitiv.\n"));

    srv_adauga_cheltuiala(1, 1, "apa", vect, erori);
    assert(vect->nr == 1);
    assert(!strcmp(erori, "Cheltuiala deja existenta.\n"));

    cheltuiala* elem;
    srv_exista_cheltuiala(1, 2, "apa", vect, erori, &elem);
    assert(elem == NULL);

    srv_exista_cheltuiala(1, 1, "gaz", vect, erori, &elem);
    assert(elem == NULL);

    srv_exista_cheltuiala(1, 1, "apa", vect, erori, &elem);
    assert(elem != NULL);
    assert(strlen(erori) != 0);

    srv_modifica_cheltuiala(1, 2, "gaz", erori, elem);
    assert(!strcmp(vect->elem[0]->tip, "gaz"));
    assert(vect->elem[0]->suma == 2);

    srv_sterge_cheltuiala(1, 3, "gaz", vect, erori);
    assert(strlen(erori) != 0);

    srv_sterge_cheltuiala(1, 2, "gaz", vect, erori);
    assert(strlen(erori) == 0);

    srv_sterge_cheltuiala(1, 3, "gaz", vect, erori);
    assert(strlen(erori) != 0);

    cheltuiala* a1 = creeaza_cheltuiala(4, 4, "apa");
    cheltuiala* a2 = creeaza_cheltuiala(5, 5, "apa");
    cheltuiala* a3 = creeaza_cheltuiala(6, 6, "apa");
    adauga_cheltuiala(a1, vect);
    adauga_cheltuiala(a2, vect);
    adauga_cheltuiala(a3, vect);

    vectorDinamic* vect2 = creeaza_vector();
    srv_copy(vect2, vect);

    srv_sort(vect2, comparaSumaCresc);
    int i;
    for (i = 0; i < vect2->nr; i++)
        assert(vect2->elem[i]->suma == 4 + i);

    srv_destructor_vector(vect);
    srv_destructor_vector(vect2);
}


void run_teste_utils() {
    char str[8];
    strcpy(str, "123\n");
    int s = strtoint(str);
    assert(s == 123);

    strcpy(str, "\n");
    s = strtoint(str);
    assert(s == INT_MAX);

    strcpy(str, "123asd\n");
    s = strtoint(str);
    assert(s == INT_MAX);

    strcpy(str, "-123\n");
    s = strtoint(str);
    assert(s == -123);
}


void run_all_tests() {
    run_teste_domeniu_cheltuiala();
    run_teste_validator_cheltuiala();
    run_teste_repo_cheltuiala();
    run_teste_service_cheltuiala();
    run_teste_utils();
}