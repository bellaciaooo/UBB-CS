#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int a[10000][10000],n,dist[10000],parinte[10000],i,j, inf = (1<<31)-1,x,y,L,u[10000],k,vizitat[10000];

struct comparare {
	bool operator()(int x,int y)
	{
		return dist[x] > dist[y];
	}
};

priority_queue<int,vector<int>,comparare> coada;

void Moore(int nod_sursa, int n)
{
	dist[nod_sursa] = 0;
	coada.push(nod_sursa);
	vizitat[nod_sursa] = 1;
	while (!coada.empty()) //cattimp coada nu este goala
	{
		int nod = coada.top();
		coada.pop();
		vizitat[nod] = 0;
		//cautam vecinii nodului curent
		for(int i = 1;i<= n;i++)
			if (a[nod][i] != 0)// => exista muchie => e vecin
			{
				int vecin = i;
				int cost = a[nod][i];
				if (dist[vecin] > dist[nod] + cost)
				{
					dist[vecin] = dist[nod] + cost;
					parinte[vecin] = nod;
					if (vizitat[vecin] == 0)
					{
						coada.push(vecin);
						vizitat[vecin] = 1;
					}
				}
			}
	}
}

int main()
{
	int nod_start, nod_final;
	ifstream f("graf.txt");
	f >> n;
	while (f >> x >> y >> L)
	{
		a[x][y] = L;
		a[y][x] = L;
	}
	for (i = 1; i <= n; i++)
		dist[i] = inf;
	cout << "Introduceti nodul de start: ";
	cin >> nod_start;
	cout << "Introduceti nodul final: ";
	cin >> nod_final;
	Moore(nod_start, n);
	k = dist[nod_final];
	u[k] = nod_final;
	while (k > 0)
	{
		u[k - 1] = parinte[u[k]];
		k--;
	}
	cout << "Solutia este: ";
	for (i = 1; i <= dist[nod_final]; i++)
		cout <<u[k]<<' ';
	return 0;
}