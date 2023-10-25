#include "repo.h"
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::find_if;

void repo::WriteToFile()
{
	ofstream g(fileName);
	for (const auto& a : all)
		g << a.getStrada() << ' ' << a.getSuprafata() << ' ' << a.getPret()<<'\n';
	g.close();
}

void repo::ReadFromFile()
{
	ifstream f(fileName);
	all.clear();
	string strada;
	int suprafata;
	int pret;

	while (f >> strada >> suprafata >> pret)
		all.push_back(Apartament(strada, suprafata, pret));

	f.close();
}

repo::repo(const string& fileName) : fileName(fileName)
{
	ReadFromFile();
}

void repo::sterge(const Apartament& a)
{
	auto it = find_if(all.begin(), all.end(),
		[a](const Apartament& apt) noexcept {return a.getStrada() == apt.getStrada(); });

	if (it != all.end())
		all.erase(it);
	
	WriteToFile();
}

void repo::adauga(const Apartament& a)
{
	auto it = find_if(all.begin(), all.end(),
		[a](const Apartament& apt) noexcept {return a.getStrada() == apt.getStrada(); });

	if (it == all.end())
		all.push_back(a);

	WriteToFile();
}

void repo::modifica(const Apartament& a1, const Apartament& a2)
{
	auto it = find_if(all.begin(), all.end(),
		[a1](const Apartament& apt) noexcept {return apt.getStrada() == a1.getStrada(); });

	if (it != all.end())
		(*it).setStrada(a2.getStrada());

	WriteToFile();
}

const vector<Apartament>& repo::getAll()
{
	return all;
}
