#pragma once
#include "service.h"
#include "repo.h"
#include "Jucator.h"
#include <iostream>
#include <string>

using std::string;

class ui {
	service& srv;

	//afisare
	void tipareste(vector<Jucator> jucatori);

	//stergere
	void deleteUI();

public:
	//constructorul
	ui(service& srv) : srv{ srv } {}

	//nu permitem copierea de obiecte
	ui(const ui& ot) noexcept = delete;

	//functia de lansare
	void start();
};
