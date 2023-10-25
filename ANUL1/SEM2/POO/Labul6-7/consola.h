#pragma once

#include"service.h"
#include"Film.h"

class consola {
	service& crt;

	void adaugaUI();

	void stergeUI();

	void modificaUI();

	bool cautaUI();

	void tipareste(const vector<Film>& filme);

	void filterUI();

	void sortUI();

	void countUI();

	void adaugaCosUI();

	void golesteCosUI();

	void genereazaCosUI();

	void exportCosUI();

	void undoUI();

public:
	consola(service& crt)noexcept : crt{ crt } {
	}
	//nu permitem copierea obiectelor
	consola(const consola& ot) noexcept = delete;

	void start();
};