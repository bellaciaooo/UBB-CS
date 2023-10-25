#pragma once
#include "Elev.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class repo {
private:
	vector<Elev> all;
	string fileName;

	void WriteToFile();
	void ReadFromFile();

public:
	//constructor
	repo(const string& fileName);

	//nu permitem copierea de obiecte
	repo(const repo& ot) = delete;
	
	//lista de elevi
	const vector<Elev>& getAll() {
		return all;
	}

	//stergere elev
	void deleteElev(const Elev& e);

	//destructor
	~repo() = default;
};