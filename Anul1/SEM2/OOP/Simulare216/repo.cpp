#include "repo.h"
#include <algorithm>

using namespace std;

void repo::WriteToFile()
{
	ofstream g(fileName);

	for (auto& elev : all)
		g << elev.getCodMatricol() << ' ' << elev.getNume() << ' ' << elev.getPrenume() << ' ' << elev.getClasa() << ' ' << elev.getMedia() << '\n';

	g.close();
}

void repo::ReadFromFile()
{
	ifstream f(fileName);

	int cod;
	string nume;
	string prenume;
	int clasa;
	float media;

	all.clear();
	while (f >> cod >> nume >> prenume >> clasa >> media)
		all.push_back(Elev(cod,nume,prenume,clasa,media));

	f.close();
}

repo::repo(const string& fileName): fileName{fileName}
{
	ReadFromFile();
}

void repo::deleteElev(const Elev& e)
{
	all.erase(std::find(all.begin(),all.end(),e));

	WriteToFile();
}
