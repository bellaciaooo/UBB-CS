#include "repoFisier.h"
#include <fstream>

using std::ifstream;
using std::ofstream;

void repoFisier::WriteToFile()
{
	ofstream g(fileName);
	for (const auto& f : all)
		g << f.getTitlu() << ' ' << f.getGen() << ' ' << f.getAnAparitie() << ' ' << f.getActorPrincipal() << '\n';
	g.close();
}

void repoFisier::ReadFromFile()
{
	ifstream f(fileName);
	all.clear();
	string titlu;
	string gen;
	int anul_aparitiei;
	string actor_principal;

	while (f >> titlu >> gen >> anul_aparitiei >> actor_principal)
		all.push_back(Film(titlu, gen, anul_aparitiei, actor_principal));
	f.close();
}

repoFisier::repoFisier(const string& fileName) : fileName(fileName)
{
	ReadFromFile();
}

void repoFisier::adauga(const Film& f)
{
	repo::adauga(f);
	WriteToFile();
}

void repoFisier::sterge(const Film& f)
{
	repo::sterge(f);
	WriteToFile();
}

void repoFisier::modifica(Film& f1, const Film& f2)
{
	repo::modifica(f1, f2);
	WriteToFile();
}

