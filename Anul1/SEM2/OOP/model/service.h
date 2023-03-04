#pragma once

#include"Apartament.h"
#include"repo.h"
#include<string>
#include<vector>
#include<functional>

using std::vector;
using std::function;

class service {
	repo& rep;

	vector<Apartament> filterApt(function<bool(const Apartament&)> fct);

public:
	service(repo& rep) noexcept: rep{rep} {}

	service(const service& ot)noexcept = delete;

	const vector<Apartament>& getAll() noexcept {
		return rep.getAll();
	}

	void deleteApt(string strada);

	void addApt(string strada, int suprafata, int pret);

	void modifyApt(string strada1, string strada2);


	vector<Apartament> filterPret(int p1, int p2);
};