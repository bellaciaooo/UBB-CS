#pragma once
#include "Jucator.h"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class repo {
	string fileName;
	vector<Jucator> all;
	//functie pentru scriere in fisier
	void WriteToFile();
	//functie pentru citire din fisier
	void ReadFromFile();

public:
	//constructorul
	repo(const string& fileName);

	//nu permitem copierea de obiecte
	repo(const repo& ot) = delete;

	//lista de jucatori
	const vector<Jucator>& getAll() noexcept;

	//stergere jucator
	void deleteJucator(int m);
};
