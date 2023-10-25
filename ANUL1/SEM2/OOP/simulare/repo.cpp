#include "repo.h"
#include "Jucator.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
//using std::find_if;

void repo::WriteToFile()
{
	ofstream g(fileName);
	for (const auto& j : all)
		g << j.getNume() << ' ' << j.getTara() << ' ' << j.getPunctaj() << ' ' << j.getRanking() << '\n';
	g.close();
}

void repo::ReadFromFile()
{
	ifstream f(fileName);
	all.clear();
	string nume, tara;
	int punctaj, ranking;
	
	while (f >> nume >> tara >> punctaj >> ranking)
		all.push_back(Jucator(nume, tara, punctaj, ranking));

	f.close();
}

repo::repo(const string& fileName) : fileName(fileName)
{
	ReadFromFile();
}

const vector<Jucator>& repo::getAll() noexcept
{
	return all;
}

void repo::deleteJucator(int m)
{
	if(all.size() > m)
		while (m > 0)
		{
			all.erase(all.begin());
			m--;
		}
}
