/*
	2. Implementati algoritmul lui Moore pentru un graf orientat neponderat (algoritm bazat pe 
	Breath-first search, vezi cursul 2). Datele sunt citite din fisierul graf.txt. Primul rand din
	graf.txt contine numarul varfurilor, iar urmatoarele randuri contin muchiile grafului. Programul
	trebuie sa afiseze lantul cel mai scurt dintr-un varf (varful sursa poate fi citit de la 
	tastatura).

	1. Sa se determine inchiderea transitiva a unui graf orientat. (Inchiderea tranzitiva poate fi
	reprezentata ca matricea care descrie, pentru fiecare varf in parte, care sunt varfurile 
	accesibile din acest varf. Matricea inchiderii tranzitive arata unde se poate ajunge din fiecare
	varf.)

    4. Pentru un graf dat sa se afiseze pe ecran varfurile descoperite de algoritmul BFS si distanta 
	fata de varful sursa (arborele descoperit).

    3. Pentru un graf dat sa se afiseze pe ecran varfurile descoperite de apelul recursiv al procedurii
	DFS_VISIT(G, u) (apadurea descoperita de DFS).
*/
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n, a[100][100], i, j, k, t[100][100], vizitat[100], distanta[100];
queue <int>coada;

void dfs(int nod, int n)
{
	cout << nod << " ";
	vizitat[nod] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[nod][i] == 1 && vizitat[i] == 0)
		{
			dfs(i, n);
		}
	}
}

void bfs(int nod_sursa, int n)
{
	int nod_vecin = 0;
	coada.push(nod_sursa);
	while (!coada.empty())
	{
		int nod_coada = coada.front();
		cout << nod_coada << ' ';
		coada.pop();
		for (int i = 1; i <= n; i++)
		{
			if (a[nod_coada][i] == 1)
			{
				nod_vecin = i;
			}
			if (distanta[nod_vecin] == -1)
			{
				coada.push(nod_vecin);
				distanta[nod_vecin] = distanta[nod_coada] + 1;
			}
		}
	}
}

int main()
{
	ifstream f("graf.txt");
	f >> n;
	while (f >> i >> j)
	{
		a[i][j] = 1;
		t[i][j] = 1;
	}
	// 1 - matricea inchiderii tranzitive
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (t[i][j] == 0)
					t[i][j] = (t[i][k] && t[k][j]);
	
	cout << "1. Matricea inchiderii tranzitive este:\n";
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << t[i][j] << ' ';
		cout << endl;
	}

	// 2 - identificare drum minim intre 2 varfuri citite de la tastatura (Algoritmul lui Moore) 
	int nod_sursa, nod_final;
	cout << "2. Introduceti nodul sursa: ";
	cin >> nod_sursa;
	cout << "   Introduceti nodul final: ";
	cin >> nod_final;

	queue <int>coada;
	int lung[100], parinte[100], inf = (1<<31)-1, x, k, u[99];
	
	for (i = 1; i <= n; i++)
		lung[i] = inf;
	lung[nod_sursa] = 0;

	coada.push(nod_sursa);
	
	while (coada.empty() == 0)
	{
		x = coada.front();
		coada.pop();
		for (i = 1;i <= n;i++)
			if( a[x][i] == 1) // verificam daca este vecin al lui x
				if (lung[i] == inf)
				{
					parinte[i] = x;
					lung[i] = lung[x] + 1;
					coada.push(i);
				}
	}

	if (lung[nod_final] != inf)
	{
		cout << " - Lungimea drumului minim intre cele doua varfuri este: " << lung[nod_final]<<"\n";
		cout << " - Drumul minim este: ";
		k = lung[nod_final];
		u[k] = nod_final;
		while (k != 0)
		{
			u[k-1] = parinte[u[k]];
			k--;
		}
		for (i = 0; i <= lung[nod_final]; i++)
			cout << u[i] << ' ';
		cout << '\n';
	}
	else cout << " - Nu exista drum intre cele doua varfuri! \n";

	// 3 - DFS
	int nod;
	cout << "3. Introduceti un nod pentru DFS: ";
	cin >> nod;
	dfs(nod, n);
	cout << '\n';

	// 4 - BFS 
	cout << "4. Introduceti un nod pentru BFS: ";
	cin >> nod;
	for (i = 1; i <= n; i++)
		distanta[i] = -1;
	distanta[nod] = 0;
	bfs(nod, n);
	cout << '\n';

	f.close();
	return 0;
}