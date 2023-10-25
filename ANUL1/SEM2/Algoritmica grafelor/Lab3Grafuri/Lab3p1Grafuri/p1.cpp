/*
   1. Avand dat un graf orientat ponderat si un varf sursa, calculati costul minim de la varful sursa pana 
 la fiecare varf accesibil din graf. Implementarea trebuie sa fie eficienta din punctul de vedere al memoriei
 folosite si al timpului de executtie. (Implementatti un algoritm de drum minim în graf: Bellman- Ford,
 Dijkstra.) 
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <limits.h>
#include <vector>

using namespace std;

//DJKSTRA Algorithm with priority queue

int main(int arc, char* argv[])
{
	//fisier date intrare 
	ifstream f("citire.txt");

	int noduri, arce, S;
	f >> noduri >> arce >> S;
	
	vector <pair <int, int >> v[10000];
	priority_queue <pair <int, int>, vector< pair <int, int>>, greater<pair <int, int>>> q;

	int x, y, p;

	while (f >> x >> y >> p)
	{
		v[x].push_back(make_pair(y, p));
	}
	int distanta[10000];
	for (int i = 0; i < noduri; i++)
	{
		distanta[i] = INT_MAX;
	}
	distanta[S] = 0;
	q.push(make_pair(0, S));
	int i;
	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		for (i = 0; i < v[u].size(); i++)
		{
			int nod = v[u][i].first;
			int pondere = v[u][i].second;
			if (distanta[nod] > distanta[u] + pondere)
			{
				distanta[nod] = distanta[u] + pondere;
				q.push(make_pair(distanta[nod], nod));
			}
		}
	}
	for (i = 0; i < noduri; i++)
	{
		if (distanta[i] == INT_MAX)
			cout << "INF ";
		else
			cout << distanta[i] << " ";

	}

	f.close();
	return 0;
}
