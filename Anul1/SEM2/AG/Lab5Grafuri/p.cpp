#include<iostream>
#include<fstream>
#include<vector>

/* Problema 3 - Ciclu Eulerian */

using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");

#define nrn 100005
#define nrm 500005
int n, m;
int nod1[nrm], nod2[nrm];
vector<int>graf[nrn];
int viz[nrm];
vector<int>rez;

void dfs(int k)
{
    while (!graf[k].empty())
    {
        int muchie = graf[k].back();
        graf[k].pop_back();
        if (viz[muchie] == 0)
        {
            viz[muchie] = 1;
            int urm;
            if (nod1[muchie] != k)
            {
                urm = nod1[muchie];
            }
            else
            {
                urm = nod2[muchie];
            }
            dfs(urm);
        }
    }
    rez.push_back(k);
}

int main()
{
    //citim datele din fisier
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        fin >> x >> y;
        nod1[i] = x;
        nod2[i] = y;
        graf[x].push_back(i);
        graf[y].push_back(i);
    }
    for (int i = 0; i < nrn; i++)
    {
        //verificam gradul fiecarui nod (daca are grad impar=> nu exista ciclu eulerian)
        if (graf[i].size() % 2 == 1)
        {
            fout << "Graful nu are ciclu Eulerian.";
            fin.close();
            fout.close();
            return 0;
        }
    }
    dfs(0);
    for (int i = 0; i < rez.size() - 1; i++)
    {
        fout << rez[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
