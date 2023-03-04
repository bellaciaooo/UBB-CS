#pragma once
#include"Apartament.h"
#include<vector>
#include<string>
#include<ostream>

using std::vector;
using std::string;
using std::ostream;

class repo {
	string fileName;
	vector<Apartament> all;
	void WriteToFile();
	void ReadFromFile();
public:
	repo(const string& fileName);

	//nu permitem copierea de obiecte
	repo(const repo& ot) = delete;

	void sterge(const Apartament& a);

	void adauga(const Apartament& a);

	void modifica(const Apartament& a1, const Apartament& a2);

	const vector<Apartament>& getAll();
};