/*
  1. Fie un fisier ce contine un graf neorientat reprezentat sub forma: prima linie contine numarul nodurilor
iar urmatoarele randuri muchiile grafului. Sa se scrie un program in C/C++ care sa citeasca fisierul si sa 
reprezinte/stocheze un graf folosind matricea de adiacenta, lista de adiacenta si matricea de incidenta. 
Sa se converteasca un graf dintr-o forma de reprezentare in alta.

2. Fie un graf reprezentat sub o anumita forma (graful este citit dintr-un fisier). Sa se rezolve:
a. sa se determine nodurile izolate dintr-un graf.
b. sa se determine daca graful este regular.
c. pentru un graf reprezentat cu matricea de adiacenta sa se determine matricea distantelor.
d. pentru un graf reprezentat cu o matrice de adiacenta sa se determine daca este conex.

*/

#include <iostream>
#include <fstream>
using namespace std;
int n, m , a[100][100] = { 0 }, i, j, in[100][100] = { 0 }, viz[100], x ;

void dfs(int x)
{
	int i;
	viz[x] = 1;
	for (i = 1; i <= n; i++)
		if (a[x][i] == 1 && viz[i] == 0)
			dfs(i);
}

void royfloyd(int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][k] != 0 && a[k][j] != 0)
				{
					if (a[i][j] > a[i][k] + a[k][j] || (a[i][j] == 0 && i != j))
					{
						a[i][j] = a[i][k] + a[k][j];
					}
				}
			}
		}
	}
}

int main()
{
	ifstream f("in.txt");
	m = 0;
	f >> n;
	while (f >> i >> j)
	{
		a[i][j] = 1;
		a[j][i] = 1;
		m++;
		in[i][m] = 1;
		in[j][m] = 1;
	}

	//1.1 - matricea de adiacenta
	cout << " 1.1) Matricea de adiacenta este:\n";
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	} 

	//1.2 - matricea de incidenta
	cout << " 1.2) Matricea de incidenta este:\n";
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			cout << in[i][j] << ' ';
		cout << endl;
	}

	//2.1 - nr noduri izolate
	int nr_vf_iz = 0, ok;
	for (i = 1; i <= n; i++)
	{
		ok = 1;
		for (j = 1; j <= n; j++)
			if (a[i][j] != 0)
				ok = 0;
		if (ok == 1)
			nr_vf_iz++;
	}
	cout << " 2.1) Nr de noduri izolate este: " << nr_vf_iz << "\n";

	//2.2 - graf regular
	int grad_actual, grad_comun = 0;
	ok = 1;
	for (j = 1; j <= m; j++)
		if (in[1][j] != 0)
			grad_comun++;
	for (i = 2; i <= n && ok == 1; i++)
	{
		grad_actual = 0;
		for (j = 1; j <= m; j++)
			if (in[i][j] != 0)
				grad_actual++;
		if (grad_actual != grad_comun)
			ok = 0;
	}
	if (ok == 1)
		cout << " 2.2) Graful este regular!\n ";
	else
		cout << " 2.2) Graful NU este regular!\n ";
	
	//2.3 - graf conex
	ok = 1;
	dfs(1);
	for (i = 1; i <= n && ok == 1; i++)
			if (viz[i] == 0)
			{
				cout << "2.3) Graful NU este conex!\n";
				ok = 0;
			}
	if (ok == 1)
		cout << "2.3) Graful este conex!\n";

	//2.4 - matricea distantelor
	royfloyd(n);
	cout << " 2.4) Matricea distantelor este:\n";
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	f.close();
	return 0;
}