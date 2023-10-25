#include <iostream>
#include <queue>
#include <fstream>
#include <map>
#include <string>
#include <crtdbg.h>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
struct nod
{
    nod* stang;
    nod* drept;
    char caracter, carcater_min_subarbore;
    int frecventa;
};
struct compara
{
    bool operator()(nod* p1, nod* p2)
    {
        if (p1->frecventa > p2->frecventa)
            return true;
        else
        {
            if (p2->frecventa > p1->frecventa)
                return false;
            else
            {
                //fr sunt egale
                if (p1->carcater_min_subarbore > p2->carcater_min_subarbore)
                    return true;
                else
                    return false;
            }
        }
        return false;

    }
};
nod* formeaza_arbore(priority_queue < nod*, vector<nod*>, compara>& coadaLitere, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        nod* nd = new nod;
        nd->stang = coadaLitere.top();
        coadaLitere.pop();
        nd->drept = coadaLitere.top();
        coadaLitere.pop();
        nd->frecventa = nd->stang->frecventa + nd->drept->frecventa;
        nd->caracter = NULL;
        if (nd->stang->carcater_min_subarbore < nd->drept->carcater_min_subarbore)
            nd->carcater_min_subarbore = nd->stang->carcater_min_subarbore;
        else
            nd->carcater_min_subarbore = nd->drept->carcater_min_subarbore;
        coadaLitere.emplace(nd);
    }
    nod* radacina = coadaLitere.top();
    coadaLitere.pop();
    return radacina;
}

void elibereazaMemorie(nod* radacina)
{
    if (radacina != nullptr)
    {
        elibereazaMemorie(radacina->stang);
        elibereazaMemorie(radacina->drept);
        delete radacina;
    }
}
int formeazaCod(nod* radacina, char caracter, string& cod)
{
    if (radacina == nullptr)
        return 0;
    else if (radacina->caracter == caracter)
        return 1;
    else
    {
        int nr;
        cod.append("0");
        nr = formeazaCod(radacina->stang, caracter, cod);
        if (nr == 0) {
            int nr2;
            cod.pop_back();
            cod.append("1");
            nr2 = formeazaCod(radacina->drept, caracter, cod);
            if (nr2 == 0)
                cod.pop_back();
            return nr2;
        }
        return nr;
    }
}
void afisare_codare(nod* radacina, char sir[], const map<char, int>& alfabet)
{
    map<char, string> coduri;
    auto it = alfabet.begin();
    string cod;
    while (it != alfabet.end())
    {
        formeazaCod(radacina, (*it).first, cod);
        coduri[(*it).first] = cod;
        cod.clear();
        ++it;
    }
    for (int i = 0; i < strlen(sir); i++)
    {
        out << coduri[sir[i]];
    }
}

int main()
{
    {
        char sir[10001];
        in.getline(sir, 10001);//citim sirul de caractere
        map<char, int> frecventaCaractere;
        int n = 0;
        for (int i = 0; i < strlen(sir); i++)
        {
            frecventaCaractere[sir[i]]++;
            if (frecventaCaractere[sir[i]] == 1)
                n++;
        }
        out << n << endl;
        priority_queue < nod*, vector<nod*>, compara> coadaLitere;
        auto it = frecventaCaractere.begin();
        char caracter;
        int frecventa;
        while (it != frecventaCaractere.end())
        {
            caracter = (*it).first;
            frecventa = (*it).second;
            nod* p = new nod;
            p->caracter = caracter;
            p->carcater_min_subarbore = caracter;
            p->drept = nullptr;
            p->stang = nullptr;
            p->frecventa = frecventa;
            coadaLitere.emplace(p);
            out << it.operator*().first << " " << it.operator*().second << endl;
            ++it;
        }

        nod* radacina = formeaza_arbore(coadaLitere, n);
        afisare_codare(radacina, sir, frecventaCaractere);
        elibereazaMemorie(radacina);
    }

    return 0;
}

