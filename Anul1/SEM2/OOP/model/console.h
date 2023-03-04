#pragma once

#include "service.h"
#include "Apartament.h"

class consola {
	service& srv;

	void tipareste(const vector<Apartament>& apartamente);

	void adaugaUI();

	void stergeUI();

	void modificaUI();

	void filterPretUI();

public:
	consola(service& srv) noexcept: srv{srv}{}

	//nu permitem copierea obiectelor
	consola(const consola& ot) noexcept = delete;

	void start();
};