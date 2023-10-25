#pragma once
#include "repo.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include<functional>

using namespace std;

class service {
private:
	repo& rep;

	//functie generala de sortare
	vector<Elev> generalSort(function<bool(const Elev&, const Elev&)> fct);

public:
	//constructor
	service(repo& rep) :rep{ rep }{}

	//nu permitem copierea de obiecte
	service(const service& ot) = delete;

	//lista de elevi
	const vector<Elev>& getAll() {
		return rep.getAll();
	}

	void deleteElev(const Elev& e);

	vector<Elev> sortByMedie();

	vector<Elev> sortByClasa();

	vector<Elev> sortByNume();

	//destructor
	~service() = default;
};