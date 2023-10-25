#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

int fr[100005], P[100005];
vector < int > T, K;
int n, m;

void frecv_act() {
	for (int i = 0; i <= n; i++) {
		fr[i] = 0;
	}
}

void decodare_prufer() {
	int x, y;
	for (int k = 1; k <= n; k++) {
		x = K[0];
		for (auto i : K) {
			fr[i] = 1;
		}
		for (int i = 0; i <= n; i++) {
			if (fr[i] == 0) {
				y = i;
				break;
			}
		}
		P[y] = x;
		K.push_back(y);
		K.erase(K.begin());
		frecv_act();
	}
}

int main() {
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> m;
		K.push_back(m);
	}
	for (int i = 0; i <= n; i++) {
		P[i] = 1000;
	}
	decodare_prufer();
	fout << n + 1 << '\n';
	for (int i = 0; i <= n; i++) {
		if (P[i] == 1000)
			fout << "-1 ";
		else fout << P[i] << " ";
	}
	return 0;
}
