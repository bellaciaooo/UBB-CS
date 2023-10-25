
/* 12. Determina valoarea x^n (x este un numar real dat, n este un numar natural
	 dat), utilizand operatii de inmultire si de ridicare la patrat.
*/

#include <stdio.h>

int nr_la_p(float x, int n)
{
    /* Functie care calculeaza valoarea x la puterea n.
    * param: x (tip float)
    * param: n (tip integer)
    * return: x^n (tip float)
    */
    if (n == 0) return 1;
    return x * nr_la_putere(x, n - 1);
}

int main2()
{
    int n;
    float x, val;
    printf("Introduceti numarul real x: ");
    scanf_s("%f", &x);
    printf("Introduceti numarul natural n: ");
    scanf_s("%d", &n);
    val = nr_la_p(x, n);
    printf("Valoarea lui x^n este: %f", val);
    return 0;
}