/*

  5. Sa se scrie un program care gaseste o solutie pentru unul din urmatoarele labirinturi:
  labirint_1.txt, labirint_2.txt, labirint_cuvinte.txt. Pentru labirintul 1 si 2 punctul de pornire este
  indicat de litera S si punctul de oprire este indicat de litera F, spre deosebire de labirintul 1 si 2,
  labirintul 3 nu are o solutie unica.

*/

#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<limits.h>
using namespace std;

ifstream f("labirint_1.txt");
int matrice[2000][2000];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void Lee(int i_start, int j_start, int n, int m)
{
    queue<pair<int, int>> coada;
    coada.push(make_pair(i_start, j_start));
    matrice[i_start][j_start] = 1;
    while (!coada.empty())
    {
        int i, j;
        i = coada.front().first;
        j = coada.front().second;
        for (int k = 0; k < 4; k++)
        {
            int vecin_i, vecin_j;
            vecin_i = i + dx[k];
            vecin_j = j + dy[k];
            if (vecin_i >= 0 && vecin_i < n && vecin_j >= 0 && vecin_j < m && matrice[vecin_i][vecin_j] == 0)
            {

                matrice[vecin_i][vecin_j] = matrice[i][j] + 1;
                coada.push(make_pair(vecin_i, vecin_j));
            }
        }
        coada.pop();
    }
}

void solutie_labirint(int i, int j, int n, int m)
{
    for (int k = 0; k < 4; k++) 
    {
        int vecin_i, vecin_j;
        vecin_i = i + dx[k];
        vecin_j = j + dy[k];
        if (vecin_i >= 0 && vecin_i < n && vecin_j >= 0 && vecin_j < m && matrice[vecin_i][vecin_j] == matrice[i][j] - 1)
        {
            matrice[i][j] = INT_MAX;
            solutie_labirint(vecin_i, vecin_j, n, m);
        }
    }
}

int main()
{
    int n = 0, m = 0, i, j, i_start, j_start, i_final, j_final;
    string linie;

    while (getline(f, linie)) 
    {
        if (m == 0) 
            m = linie.size();

        for ( i = 0; i < linie.size(); i++) 
        {
            switch (linie[i]) 
            {
            case '1':
                matrice[n][i] = -1;
                break;
            case ' ':
                matrice[n][i] = 0;
                break;
            case 'S':
                i_start = n;
                j_start = i;
                break;
            case 'F':
                i_final = n;
                j_final = i;
                break;
            }
        }
        n++;
    }

    Lee(i_start, j_start, n, m);
    solutie_labirint(i_final, j_final, n, m);

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++)
            if (matrice[i][j] == INT_MAX)
                cout << '*';
            else
                cout << ' ';
        cout << endl;
    }

    f.close();
    return 0;
}