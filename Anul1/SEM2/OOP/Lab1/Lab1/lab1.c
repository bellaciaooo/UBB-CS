
/*  10. Tipareste un numar precizat de sume partiale din dezvoltarea
sin(x) = x - x ^ 3 / 3!+ x ^ 5 / 5!- x ^ 7 / 7!+ ...
    12. Determina valoarea x^n (x este un numar real dat, n este un numar natural
	 dat), utilizand operatii de inmultire si de ridicare la patrat.
*/

#include <stdio.h>

int factorial(int n)
{
    /* Functie care calculeaza factorialul unui numar intreg n dat.
    * param: n (tip integer)
    * return: factorialul lui n (tip integer), pentru n >= 1 
    *         1, in caz contrar
    */
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

float nr_la_putere(float n, int p)
{
    /* Functie care calculeaza valoarea n la puterea p.
    * param: n (tip float)
    * param: p (tip integer)
    * return: n^p (tip float)
    */
    if (p == 0) return 1;
    return n * nr_la_putere(n, p - 1);
}

void ex10()
{
    /* Functie pentru exercitiul 10.
    */
    int i, nr, p = 1;
    float x, s = 0, semn = 1;
    printf("Introduceti numarul x: ");
    scanf_s("%f", &x);
    printf("Introduceti numarul de sume partiale: ");
    scanf_s("%d", &nr);
    for (i = 1; i <= nr; i++)
    {
        s = s + (semn * nr_la_putere(x, p)) / factorial(p);
        semn = semn * (-1);
        p = p + 2;
        printf("Suma este: %f\n", s);
    }
}

void ex12()
{
    /* Functie pentru exercitiul 12.
    */
    int n;
    float x, val;
    printf("Introduceti numarul real x: ");
    scanf_s("%f", &x);
    printf("Introduceti numarul natural n: ");
    scanf_s("%d", &n);
    val = nr_la_putere(x, n);
    printf("Valoarea lui x^n este: %f\n", val);
}

void menu()
{
    /* Functie care afiseaza optiunile programului.
    */
    printf("--------------------------------------------------------------------------\n");
    printf("0. Iesirea din aplicatie.\n");
    printf("1. Calculeaza sin(x) = x - x ^ 3 / 3!+ x ^ 5 / 5!- x ^ 7 / 7!+ ... .\n");
    printf("2. Calculeaza x^n.\n");
    printf("--------------------------------------------------------------------------\n");
}

int main()
{
    /* Mic meniu pentru a gestiona exercitiile.
    */
    int comanda;
    while (1)
    {
        menu();
        printf("Introduceti comanda dorita: ");
        scanf_s("%d", &comanda);
        if (comanda == 0) 
            return 0;
        else if (comanda == 1) 
            ex10();
        else if (comanda == 2) 
            ex12();
        else
            printf("Comanda introdusa nu exista!\n");

    }
}

