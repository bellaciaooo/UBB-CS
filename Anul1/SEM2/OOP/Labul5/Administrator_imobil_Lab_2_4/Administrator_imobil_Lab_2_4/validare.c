#include "validare.h"
#include <string.h>

void valideaza_cheltuiala(int numar_apartament, int suma, char* tip, char* erori) {
    strcpy(erori, "");
    if (numar_apartament <= 0)
        strcat(erori, "Numarul de apartament trebuie sa fie pozitiv.\n");
    if (suma <= 0)
        strcat(erori, "Suma trebuie sa fie pozitiva.\n");
    if (strcmp(tip, "apa") && strcmp(tip, "incalzire") && strcmp(tip, "canal") && strcmp(tip, "gaz"))
        strcat(erori, "Tipul trebuie sa fie apa/canal/incalzire/gaz.\n");
}

void valideaza_suma(int suma, char* erori) {
    strcpy(erori, "");
    if (suma <= 0)
        strcat(erori, "Suma trebuie sa fie pozitiva.\n");
}

void valideaza_ap(int numar_apartament, char* erori) {
    strcpy(erori, "");
    if (numar_apartament <= 0)
        strcat(erori, "Numarul de apartament trebuie sa fie pozitiv.\n");
}

void valideaza_tip(char* tip, char* erori) {
    strcpy(erori, "");
    if (strcmp(tip, "apa") && strcmp(tip, "incalzire") && strcmp(tip, "canal") && strcmp(tip, "gaz"))
        strcat(erori, "Tipul trebuie sa fie apa/canal/incalzire/gaz.\n");
}