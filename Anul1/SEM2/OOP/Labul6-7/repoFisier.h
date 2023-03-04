#pragma once
#include "repo.h"
#include <fstream>

class repoFisier : public repo
{
private:
	string fileName;
	void WriteToFile();
	void ReadFromFile();
public:
	//constructorul
	repoFisier(const string& fileName);
	void adauga(const Film& f) override;
	void sterge(const Film& f) override;
	void modifica(Film& f1, const Film& f2) override;
};
