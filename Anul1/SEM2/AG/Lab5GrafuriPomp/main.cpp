#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

typedef struct
{
	int h, e;
}nod;

queue <int> Q;
vector< vector< pair<int, int> > > rezid;
vector < bool > vf;
vector<nod> det_vf;
int n, x, y, c, m, s, t;

void inaltare(int x)
{
	det_vf[x].h++;
}

void descarcare(int x)
{
	while (det_vf[x].e > 0)
	{
		int iter = 0;
		while (iter < rezid[x].size())
		{
			int sw_sters = 0;
			if (det_vf[x].e == 0)
				break;
			if (det_vf[x].h == det_vf[rezid[x][iter].first].h + 1)
			{
				//pompare
				int minim = std::min(rezid[x][iter].second, det_vf[x].e);
				det_vf[rezid[x][iter].first].e += minim;
				if (rezid[x][iter].first != s && rezid[x][iter].first != t && vf[rezid[x][iter].first] == 0) {//nodurile care nu se afla in coada pentru a fi
					//verificate(la final ar avea exces dar cu nu sunt verificate nu se va distribui)
					Q.push(rezid[x][iter].first);
					vf[rezid[x][iter].first] = 1;
				}
				det_vf[x].e -= minim;
				rezid[x][iter].second = rezid[x][iter].second - minim;

				int nr = rezid[x][iter].first;
				if (rezid[x][iter].second == 0) {
					sw_sters = 1;
					rezid[x].erase(rezid[x].begin() + iter);//stergem un arc daca acesta este 0 (flux maxim pe acest arc)
				}

				int ok = 0;
				for (auto& it2 : rezid[nr])
				{
					if (it2.first == x)
					{
						ok = 1;
						it2.second += minim;
					}
				}
				if (ok == 0) {
					rezid[nr].push_back(std::make_pair(x, minim));

				}
			}

			if (sw_sters == 0)
				iter++;
		}
		if (det_vf[x].e > 0)
			inaltare(x);
	}
}

int main()
{
	fin >> n >> m;
	rezid.resize(n);
	det_vf.resize(n);
	vf.resize(n);
	for (int i = 1; i <= m; i++)
	{
		fin >> x >> y >> c;
		rezid[x].push_back(make_pair(y, c));
	}

	//initializam
	for (int i = 1; i < n; i++)
	{
		det_vf[i].e = 0;
		det_vf[i].h = 0;
	}

	s = 0, t = n - 1;
	det_vf[s].h = n;

	for (auto& it : rezid[s])
	{
		det_vf[it.first].e = it.second;//nodurile legate de sursa priesc flux maxim
		det_vf[s].e -= it.second;
		rezid[it.first].push_back(std::make_pair(s, it.second));
	}
	rezid[s].clear();

	for (int i = 1; i < n - 1; i++)
	{
		vf[i] = 1;
		Q.push(i);
	}

	///flux
	while (!Q.empty())
	{
		int varf = Q.front();
		int old_h = det_vf[varf].h;
		descarcare(varf);
		Q.pop();
		vf[varf] = 0;
		if (det_vf[varf].h > old_h)
		{
			Q.push(varf);
			vf[varf] = 1;
		}
	}

	fout << det_vf[t].e;
	return 0;
}
