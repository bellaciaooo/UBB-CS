#include <stdio.h>
#include "consola.h"
#include "repo.h"
#include "service.h"
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include <limits.h>
#include "validare.h"

#define SIZE 15

void ui_adauga_cheltuiala(vectorDinamic* vect) {
    int numar_apartament, suma, citit;
    char tip[SIZE], erori[305] = "", numar_apartament_str[SIZE], suma_str[SIZE];
    printf("Numar apartament: ");
    citit = (fgets(numar_apartament_str, SIZE, stdin) != NULL);
    printf("Suma: ");
    citit = citit && (fgets(suma_str, SIZE, stdin) != NULL);
    printf("Tipul(apa, canal, incalzire, gaz): ");
    citit = citit && (fgets(tip, SIZE, stdin) != NULL);

    if (citit) {
        numar_apartament = strtoint(numar_apartament_str);
        suma = strtoint(suma_str);
        tip[strlen(tip) - 1] = '\0';    //elimin \n de la final

        if (numar_apartament != INT_MAX && suma != INT_MAX) {
            srv_adauga_cheltuiala(numar_apartament, suma, tip, vect, erori);
            if (strlen(erori) == 0)
                printf("Cheltuiala adaugata cu succes.\n");
            else
                printf("%s", erori);
        }
        else
            printf("Datele introduse sunt invalide.\n");
    }
}


void ui_modifica_cheltuiala(vectorDinamic* vect) {
    int numar_apartament, suma, new_suma, citit;
    char tip[SIZE], erori[305] = "", new_tip[SIZE], numar_apartament_str[SIZE], suma_str[SIZE],
        new_suma_str[SIZE];
    cheltuiala* elem;


    printf("Numar apartament: ");
    citit = (fgets(numar_apartament_str, SIZE, stdin) != NULL);
    printf("Suma: ");
    citit = citit && (fgets(suma_str, SIZE, stdin) != NULL);
    printf("Tipul(apa, canal, incalzire, gaz): ");
    citit = citit && (fgets(tip, SIZE, stdin) != NULL);

    printf("Introduceti noi date pentru cheltuiala dorita\n");
    printf("Suma noua: ");
    citit = citit && (fgets(new_suma_str, SIZE, stdin) != NULL);
    printf("Tipul(apa, canal, incalzire, gaz) nou: ");
    citit = citit && (fgets(new_tip, SIZE, stdin) != NULL);

    if (citit) {
        numar_apartament = strtoint(numar_apartament_str);
        suma = strtoint(suma_str);
        tip[strlen(tip) - 1] = '\0';    //elimin \n de la final
        new_suma = strtoint(new_suma_str);
        new_tip[strlen(new_tip) - 1] = '\0';    //elimin \n de la final

        if (numar_apartament != INT_MAX && suma != INT_MAX && new_suma != INT_MAX) {
            srv_exista_cheltuiala(numar_apartament, suma, tip, vect, erori, &elem);
            if (elem != NULL) {
                srv_modifica_cheltuiala(numar_apartament, new_suma, new_tip, erori, elem);
                if (strlen(erori) == 0)
                    printf("Cheltuiala modificata cu succes.\n");
                else {
                    printf("Erori pentru noile date introduse: \n");
                    printf("%s", erori);
                }
            }
            else
                printf("%s", erori);
        }
        else
            printf("Datele introduse sunt invalide.\n");
    }
}


void ui_stergere_cheltuiala(vectorDinamic* vect) {
    int numar_apartament, suma, citit;
    char tip[SIZE], erori[303], numar_apartament_str[SIZE], suma_str[SIZE];

    printf("Numar apartament: ");
    citit = (fgets(numar_apartament_str, SIZE, stdin) != NULL);
    printf("Suma: ");
    citit = citit && (fgets(suma_str, SIZE, stdin) != NULL);
    printf("Tipul(apa, canal, incalzire, gaz): ");
    citit = citit && (fgets(tip, SIZE, stdin) != NULL);

    if (citit) {
        numar_apartament = strtoint(numar_apartament_str);
        suma = strtoint(suma_str);
        tip[strlen(tip) - 1] = '\0';    //elimin \n de la final

        if (numar_apartament != INT_MAX && suma != INT_MAX) {
            srv_sterge_cheltuiala(numar_apartament, suma, tip, vect, erori);
            if (strlen(erori) == 0)
                printf("Cheltuiala stearsa cu succes.\n");
            else
                printf("%s\n", erori);
        }
        else
            printf("Datele introduse sunt invalide.\n");
    }
}


void afisareVector(vectorDinamic* vect) {
    int i;
    printf("Elementele vectorului:\n");
    for (i = 0; i < vect->nr; i++)
        printf("%d - %d, %d, %s\n", i + 1, vect->elem[i]->numar_apartament, vect->elem[i]->suma, vect->elem[i]->tip);
}


void afisareCheltuiala(cheltuiala* pay) {
    printf("Ap: %d, Suma: %d, Apartament: %s\n", pay->numar_apartament, pay->suma, pay->tip);
}


void ui_filtrare(vectorDinamic* vect) {
    printf("1.Suma\n2.Tip\n3.Apartament\nDupa ce criteriu vrei sa filtrezi lista de cheltuieli(1,2,3): ");
    int cmd, suma, numar_apartament;
    char tip[SIZE], erori[300], cmd_str[SIZE], suma_str[SIZE], numar_apartament_str[SIZE];

    if (fgets(cmd_str, SIZE, stdin) != NULL) {
        cmd = strtoint(cmd_str);
        if (cmd == 1) {
            printf("Suma: ");
            if (fgets(suma_str, SIZE, stdin) != NULL) {
                suma = strtoint(suma_str);
                if (suma != INT_MAX) {
                    valideaza_suma(suma, erori);
                    if (!(strlen(erori) > 0)) {
                        int i = 0;
                        for (; i < vect->nr; i++)
                            if (vect->elem[i]->suma == suma)
                                afisareCheltuiala(vect->elem[i]);
                    }
                    else if (strlen(erori) > 0)
                        printf("%s", erori);
                }
            }
        }
        else if (cmd == 2) {
            printf("Tipul(apa, canal, incalzire, gaz): ");
            if (fgets(tip, SIZE, stdin) != NULL) {
                tip[strlen(tip) - 1] = '\0';    // elimin \n de la final
                valideaza_tip(tip, erori);
                if (!(strlen(erori) > 0)) {
                    int i = 0;
                    for (; i < vect->nr; i++)
                        if (!strcmp(vect->elem[i]->tip, tip))
                            afisareCheltuiala(vect->elem[i]);
                }
                else if (strlen(erori) > 0)
                    printf("%s", erori);
            }
        }
        else if (cmd == 3) {
            printf("Numar apartament: ");
            if (fgets(numar_apartament_str, SIZE, stdin) != NULL) {
                numar_apartament = strtoint(numar_apartament_str);
                if (numar_apartament != INT_MAX) {
                    valideaza_ap(numar_apartament, erori);
                    if (!(strlen(erori) > 0)) {
                        int i = 0;
                        for (; i < vect->nr; i++)
                            if (vect->elem[i]->numar_apartament == numar_apartament)
                                afisareCheltuiala(vect->elem[i]);
                    }
                    else if (strlen(erori) > 0)
                        printf("%s", erori);
                }
            }
        }
        else
            printf("Comanda introdusa este invalida.\n");
    }
    else {
        printf("Eroare la citire");
    }
}


void ui_showSortedList(vectorDinamic* vect) {
    printf("1.Suma\n2.Tip\nDupa ce criteriu vrei sa sortezi lista de cheltuieli(1,2): ");
    int cmd, cmd2;
    char cmd_str[SIZE], cmd2_str[SIZE];
    if (fgets(cmd_str, SIZE, stdin) != NULL) {
        cmd = strtoint(cmd_str);
        if (cmd == 1) {
            printf("1.Crescator\n2.Descrescator\nDupa ce criteriu vrei sa sortezi lista de cheltuieli(1,2): ");
            if (fgets(cmd2_str, SIZE, stdin) != NULL) {
                cmd2 = strtoint(cmd2_str);
                if (cmd2 != INT_MAX) {
                    if (cmd2 == 1) {
                        vectorDinamic* vect_copy = creeaza_vector();
                        srv_copy(vect_copy, vect);
                        srv_sort(vect_copy, comparaSumaCresc);
                        int i = 0;
                        for (; i < vect_copy->nr; i++)
                            afisareCheltuiala(vect_copy->elem[i]);
                        destructor_vector(vect_copy);
                    }
                    else if (cmd2 == 2) {
                        vectorDinamic* vect_copy = creeaza_vector();
                        srv_copy(vect_copy, vect);
                        srv_sort(vect_copy, comparaSumaDescresc);
                        int i = 0;
                        for (; i < vect_copy->nr; i++)
                            afisareCheltuiala(vect_copy->elem[i]);
                        destructor_vector(vect_copy);
                    }
                    else
                        printf("Comanda introdusa este invalida.\n");
                }
            }
        }
        else if (cmd == 2) {
            printf("1.Crescator\n2.Descrescator\nDupa ce criteriu vrei sa sortezi lista de cheltuieli(1,2): ");
            if (fgets(cmd2_str, SIZE, stdin) != NULL) {
                cmd2 = strtoint(cmd2_str);
                if (cmd2 != INT_MAX) {
                    if (cmd2 == 1) {
                        vectorDinamic* vect_copy = creeaza_vector();
                        srv_copy(vect_copy, vect);
                        srv_sort(vect_copy, comparaTipCresc);
                        int i = 0;
                        for (; i < vect_copy->nr; i++)
                            afisareCheltuiala(vect_copy->elem[i]);
                        destructor_vector(vect_copy);
                    }
                    else if (cmd2 == 2) {
                        vectorDinamic* vect_copy = creeaza_vector();
                        srv_copy(vect_copy, vect);
                        srv_sort(vect_copy, comparaTipDescresc);
                        int i = 0;
                        for (; i < vect_copy->nr; i++)
                            afisareCheltuiala(vect_copy->elem[i]);
                        destructor_vector(vect_copy);
                    }
                    else
                        printf("Comanda introdusa este invalida.\n");
                }
            }
        }
        else
            printf("Comanda introdusa este invalida.\n");
    }
    else {
        printf("Eroare la citire");
    }
}


void meniu() {
    vectorDinamic* vect = creeaza_vector();
    int cmd = 0, run = 1;
    char cmd_str[100];
    while (run) {
        system("CLS");
        printf("1. Adaugarea de cheltuieli pentru un apartament\n2. Modificarea unei cheltuieli existente (tipul, suma)\n3. Stergere cheltuiala\n4. Vizualizare lista de cheltuieli filtrat dupa o proprietate (suma, tipul,apartament)\n5. Vizualizare lista de cheltuieli ordonat dupa suma sau tip (crescator/descrescator)\n");
        afisareVector(vect);
        if (cmd == 0)
            printf("Comanda este(1-5): ");
        if (fgets(cmd_str, 100, stdin) != NULL) {
            cmd = strtoint(cmd_str);
            if (cmd != INT_MAX) {
                switch (cmd) {
                case 1:
                    ui_adauga_cheltuiala(vect);
                    cmd = 0;
                    break;
                case 2:
                    ui_modifica_cheltuiala(vect);
                    cmd = 0;
                    break;
                case 3:
                    ui_stergere_cheltuiala(vect);
                    cmd = 0;
                    break;
                case 4:
                    ui_filtrare(vect);
                    cmd = 0;
                    break;
                case 5:
                    ui_showSortedList(vect);
                    cmd = 0;
                    break;
                case 0:
                    run = 0;
                    break;
                default:
                    printf("Comanda introdusa este invalida.\n");
                    cmd = 0;
                    break;
                }
            }
            else
                printf("Comanda introdusa este invalida.\n"), cmd = 0;
            if (run == 1) {
                int read = 1;
                char stay[100];
                while (read) {
                    printf("Vrei sa continui(y/n): ");
                    if (fgets(stay, 100, stdin) != NULL && (!strcmp(stay, "n\n") || !strcmp(stay, "N\n") ||
                        !strcmp(stay, "y\n") || !strcmp(stay, "Y\n"))) {
                        if (!strcmp(stay, "n\n") || !strcmp(stay, "N\n"))
                            run = 0;
                        else if (!strcmp(stay, "y\n") || !strcmp(stay, "Y\n"))
                            run = 1;
                        read = 0;
                    }
                    else
                        printf("Comanda introdusa este invalida.\n");
                }
            }
        }
        else
            printf("Eroare la citire.\n");
    }
    srv_destructor_vector(vect);
}