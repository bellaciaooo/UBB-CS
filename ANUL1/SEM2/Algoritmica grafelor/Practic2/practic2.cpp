#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt"); 

bool inca_parinte(int parent, int frunza, int nr_frunze, vector<int>& parinte)
{
	for (int i = 0; i < nr_frunze; i++)
	{	if (i != frunza && parinte[i] == parent)
			return true;
	}
	return false;
}

int main()
{
	int n, x, i;
	vector<int> parinte;
	vector<bool>eparinte;
	f >> n;
	g << n - 1 << endl;
	for (i = 0; i < n; i++)
	{
		f >> x;
		parinte.push_back(x);
		eparinte.push_back(false);
	}
	for (i = 0; i < n; i++)
	{
		if (parinte[i] != -1)
			eparinte[parinte[i]] = true;
	}

	for (i = 0; i < n; i++)
		if (!eparinte[i] && parinte[i] != -1)
		{
			g << parinte[i] << " ";
			if (!inca_parinte(parinte[i], i, n, parinte))
				eparinte[parinte[i]] = false;
			parinte[i] = -1;
			i = -1;
		}

	f.close();
	g.close();
	return 0;
}