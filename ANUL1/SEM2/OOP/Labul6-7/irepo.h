#pragma once
#include "Film.h"
#include <vector>
using std::vector;

class irepo
{
public:
	
	virtual void adauga(const Film& f) = 0;

	virtual void sterge(const Film& f) = 0;

	virtual void modifica(Film& f1, const Film& f2) = 0;

	virtual bool cauta(const Film& f) = 0;

	virtual const vector<Film>& getAll() = 0;

	virtual ~irepo() {}
};
