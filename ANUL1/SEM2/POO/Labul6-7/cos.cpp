#include "cos.h"
#include <vector>
#include "service.h"
#include<functional>
#include<algorithm>
#include <random> 
#include <chrono>
#include <fstream>

using std::find_if;

void Cos::adauga(string titlu)
{
	for (const Film& film : filme) 
		if (film.getTitlu() == titlu)
			throw repoException("Filmul este deja adaugat in cos!\n");
	for (const Film& film : rep.getAll())
		if (film.getTitlu() == titlu)
		{
			filme.push_back(film);
			return;
		}
	throw repoException("Filmul nu exista in lista de filme!\n"); }

void Cos::goleste()
{
	filme.clear();
}

void Cos::genereaza(int nr)
{
	if (nr <= 0)
		throw repoException("Numarul trebuie sa fie pozitiv!\n");
	
	const auto& all = rep.getAll();
	vector<size_t> poz(all.size());
	for (size_t i = 0; i < poz.size(); i++)
		poz[i] = i;

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(poz.begin(), poz.end(), std::default_random_engine{ (unsigned int)seed }); //amesteca vectorul poz

	for (const size_t i : poz)
	{
		const auto& f = all[i];
		auto it = find_if(filme.begin(), filme.end(), [&f](const Film& film) noexcept
			{
				return f == film;
			});

		if (it == filme.end())
		{
			nr--;
			filme.push_back(f);
			if (nr == 0)
				break;
		}
	}
	if (nr > 0)
		throw repoException("Nu s-au putut adauga toate filmele!\n");
}

void Cos::exportC(const char* file) const
{
	std::ofstream g(file);

	if (!g) {	throw repoException("Fisier invalid!\n"); }
	g << "Titlu , Gen , Anul aparitiei , Actor principal\n";
	for (const auto& film : filme)
	{
		g << film.getTitlu() << ", " << film.getGen() << ", " << film.getAnAparitie() << ", " << film.getActorPrincipal() << "\n";
	}
	g.close();
}

const vector<Film>& Cos::getAll() const noexcept
{
	return filme;
}


