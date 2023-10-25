#pragma once
#include <iostream>
#include <string>

using namespace std;

class Elev {
private:
	int cod_matricol;
	string nume;
	string prenume;
	int clasa;
	float media;

public:
	//constructor
	Elev(int co, string n, string p, int cl, float m) :cod_matricol{ co }, nume{ n }, prenume{ p }, clasa{ cl }, media{ m }{}

	//copy-constructor
	Elev(const Elev& ot): cod_matricol{ot.cod_matricol},nume{ot.nume},prenume{ot.prenume},clasa{ot.clasa},media{ot.media}{}

	//operatorul de assignment
	Elev& operator=(const Elev& e);

	bool operator==(const Elev& e) {
		return this->cod_matricol == e.cod_matricol;
	}

	//get-eri
	int getCodMatricol()const;

	string getNume()const;

	string getPrenume()const;

	int getClasa()const;

	float getMedia()const;

};