#include "repoProbabilitati.h"
#include <time.h>

void repoProb::AruncaExceptie(string mesaj) const
{
	const float x = ((float)rand()) / RAND_MAX;
	if (x < p)
		throw randomException(mesaj); }

repoProb::repoProb(float p) : p(p)
{
	srand((unsigned int)time(nullptr));
}

void repoProb::adauga(const Film& f)
{
	AruncaExceptie("adaugare");
	if(all.find(f.getTitlu()) != all.end())
		throw repoException("Filmul exista deja!");
	all[f.getTitlu()] = f;
}

void repoProb::sterge(const Film& f)
{
	AruncaExceptie("stergere");
	auto it = all.find(f.getTitlu());
	if (it == all.end())
		throw repoException("Filmul nu exista\n");
	all.erase(it);
}

void repoProb::modifica(Film& f1, const Film& f2)
{
	AruncaExceptie("modificare");
	auto it = all.find(f1.getTitlu());
	if (it == all.end())
		throw repoException("Filmul nu exista!\n");
	(it->second).setTitlu(f2.getTitlu());
}

bool repoProb::cauta(const Film& f)
{
	AruncaExceptie("cautare");
	auto it = all.find(f.getTitlu());
	if (it == all.end())
		return false;
	return true;
}

const vector<Film>& repoProb::getAll() 
{
	AruncaExceptie("get all films");
	replica.clear();
	for (const auto& x : all)
		replica.push_back(x.second);
	return replica;
}
