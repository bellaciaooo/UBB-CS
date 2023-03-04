#include <string.h>
#include <limits.h>
#include "entitati.h"

int strtoint(char* str) {
    if (str[0] == '\n')
        return INT_MAX;
    int num = 0;
    int i = 0;
    int isNegetive = 0;
    if (str[i] == '-') {
        isNegetive = 1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9')) {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] != '\n')
        return INT_MAX;
    if (isNegetive)
        num = -1 * num;
    return num;
}


int comparaSumaCresc(cheltuiala* a, cheltuiala* b) {
    return (a->suma > b->suma);
}


int comparaSumaDescresc(cheltuiala* a, cheltuiala* b) {
    return (a->suma < b->suma);
}


int comparaTipCresc(cheltuiala* a, cheltuiala* b) {
    if (strcmp(a->tip, b->tip) <= 0)
        return 0;
    return 1;
}


int comparaTipDescresc(cheltuiala* a, cheltuiala* b) {
    if (strcmp(a->tip, b->tip) >= 0)
        return 0;
    return 1;
}