#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;
ifstream fin("in.txt");
unordered_map<char, int> fv;
struct nod
{
    char c;
    int fr;
    nod* st;
    nod* dr;
};
struct cmp
{
    bool operator()(nod* n1, nod* n2) const
    {
        if (n1->fr == n2->fr)
            return n1->c < n2->c;
        return n1->fr < n2->fr;
    };
};
unordered_map<string, char> decodat;
void citire();
void decodare_huffman();
nod* huffman();
void dfs(nod* n, const string& s);

int main() {

    citire();
    decodare_huffman();
    fin.close();
    return 0;
}

void citire() {
    int n, fr;
    char c;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> c >> fr;
        fv[c] = fr;
    }
}

nod* huffman() {
    int n = fv.size();
    multiset<nod*, cmp> set;
    for (auto el : fv)
    {
        nod* p = new nod;
        p->fr = el.second;
        p->c = el.first;
        p->st = p->dr = nullptr;
        set.insert(p);
    }

    for (int i = 1; i < n; i++)
    {
        nod* n = (*set.begin());
        set.erase(set.begin());

        nod* q = (*set.begin());
        set.erase(set.begin());

        nod* p = new nod;
        p->fr = n->fr + q->fr;
        p->c = min(n->c, q->c);
        p->st = n;
        p->dr = q;
        set.insert(p);
    }
    nod* nn = (*set.begin());
    return nn;
}


void decodare_huffman()
{
    auto n = huffman();
    string s;
    dfs(n, s);
    int line = 0;
    char str[10][100000];
    while (fin.getline(str[line], 100000)) {
        int len = strlen(str[line]);
        string p = str[line];
        int start = 0;
        for (int end = 0; end < len; end++) {
            string subs = p.substr(start, end - start + 1);
            if (decodat.find(subs) != decodat.end()) {
                start = end + 1;
                cout << decodat[subs];
            }
        }
        line++;
    }
}

void dfs(nod* n, const string& s)
{
    if (n->st != nullptr)
        dfs(n->st, s + "0");
    if (n->dr != nullptr)
        dfs(n->dr, s + "1");
    if (n->st == nullptr && n->dr == nullptr)
        decodat[s] = n->c;
    free(n);
}

