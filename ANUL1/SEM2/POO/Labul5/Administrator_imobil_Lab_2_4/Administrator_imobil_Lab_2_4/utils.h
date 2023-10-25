/*
    functie care primeste un pointer catre un sir de caractere si returneaza sir convertit intr-un integer, daca se poate,
    in caz contrar se returneaza INT_MAX
    date de intrare: str - pointer catre un sir de caractere
    date de iesire: num - intger
*/
int strtoint(char* str);


/*
    functie care primeste ca parametrii 2 instante de tip cheltuiala si le compara dupa supa, se returneaza 1 daca suma primei cheltuieli
    este mai mare decat a doua, altfel se returneaza 0
    date de intrare: a - instanta de tip cheltuiala
                     b - instanta de tip cheltuiala
    date de iesire: 1 sau 0
*/
int comparaSumaCresc(cheltuiala*, cheltuiala*);

/*
    functie care primeste ca parametrii 2 instante de tip cheltuiala si le compara dupa supa, se returneaza 1 daca suma primei cheltuieli
    este mai mica decat a doua, altfel se returneaza 0
    date de intrare: a - instanta de tip cheltuiala
                     b - instanta de tip cheltuiala
    date de iesire: 1 sau 0
*/
int comparaSumaDescresc(cheltuiala*, cheltuiala*);

/*
    functie care primeste ca parametrii 2 instante de tip cheltuiala si le compara dupa tip, se returneaza 1 daca tipul primei cheltuieli
    este mai mare lexicografic decat tipul celelaltei cheltuieli, altfel se returneaza 0
    date de intrare: a - instanta de tip cheltuiala
                     b - instanta de tip cheltuiala
    date de iesire: 1 sau 0
*/
int comparaTipCresc(cheltuiala*, cheltuiala*);


/*
    functie care primeste ca parametrii 2 instante de tip cheltuiala si le compara dupa tip, se returneaza 1 daca tipul primei cheltuieli
    este mai mic lexicografic decat tipul celelaltei cheltuieli, altfel se returneaza 0
    date de intrare: a - instanta de tip cheltuiala
                     b - instanta de tip cheltuiala
    date de iesire: 1 sau 0
*/
int comparaTipDescresc(cheltuiala*, cheltuiala*);