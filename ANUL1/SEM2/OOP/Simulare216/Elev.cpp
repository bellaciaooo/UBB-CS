#include "Elev.h"

Elev& Elev::operator=(const Elev& e)
{
	if (this == &e) { return *this; }
	this->cod_matricol = e.cod_matricol;
	this->nume = e.nume;
	this->prenume = e.prenume;
	this->clasa = e.clasa;
	this->media = e.media;
}

int Elev::getCodMatricol() const
{
	return cod_matricol;
}

string Elev::getNume() const
{
	return nume;
}

string Elev::getPrenume() const
{
	return prenume;
}

int Elev::getClasa() const
{
	return clasa;
}

float Elev::getMedia() const
{
	return media;
}
