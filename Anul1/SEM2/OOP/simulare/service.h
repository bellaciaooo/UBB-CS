#pragma once
#include "repo.h"
#include "Jucator.h"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class service {
	repo& rep;

public:
	service(repo& rep) noexcept: rep{ rep } {}

	//nu permitem copierea de obiecte
	service(const service& ot) noexcept = delete;

	//accesam lista de jucatori
	const vector<Jucator>& getAll() noexcept {
		return rep.getAll();
	}
	
	//stergem m jucatori din lista de jucatori
	void deleteJucator(int m);
};