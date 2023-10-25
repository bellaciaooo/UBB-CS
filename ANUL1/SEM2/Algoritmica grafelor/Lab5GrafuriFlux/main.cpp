#include <iostream>
#include <fstream>
#include <limits.h>
#include <queue>
#include <string.h>
#define INF 100000007
using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

int V, E, x, y, w;
int G[101][101];
queue<int> coada;

bool BFS(int G[][101], int s, int t, int T[])
{
    bool Viz[101];
    memset(Viz, 0, sizeof(Viz));
    coada.push(s);
    Viz[s] = true;
    T[s] = -1;
    while (!coada.empty())
    {
        int u = coada.front();
        coada.pop();
        for (int vf = 0; vf < V; vf++)
        {
            if (Viz[vf] == false && G[u][vf] > 0)
            {
                if (vf == t)
                {
                    T[vf] = u;
                    return true;
                }
                coada.push(vf);
                T[vf] = u;
                Viz[vf] = true;
            }
        }
    }
    return false;
}

int FordFulkerson(int G[][101], int s, int t)
{
    int i, vf, T[101], flux_maxim = 0;
    while (BFS(G, s, t, T))
    {
        int dr_flux = INF;
        for (vf = t; vf != s; vf = T[vf])
        {
            i = T[vf];
            dr_flux = min(dr_flux, G[i][vf]);
        }
        for (vf = t; vf != s; vf = T[vf])
        {
            i = T[vf];
            G[i][vf] -= dr_flux;
            G[vf][i] += dr_flux;
        }
        flux_maxim += dr_flux;
    }
    return flux_maxim;
}


int main(int argc, char** argv)
{
    fin >> V >> E;
    for (int i = 1; i <= E; i++)
    {
        fin >> x >> y >> w;
        G[x][y] = w;
    }
    fout << FordFulkerson(G, 0, V - 1);
    return 0;
}
