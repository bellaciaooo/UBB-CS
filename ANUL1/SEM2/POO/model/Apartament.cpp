#include "Apartament.h"

Apartament& Apartament::operator=(const Apartament& a)
{
	if (this == &a)
	{
		return *this;
	}
	this->strada = a.strada;
	this->suprafata = a.suprafata;
	this->pret = a.pret;
	return *this;
}

string Apartament::getStrada() const {
	return strada;
}

int Apartament::getSuprafata() const noexcept {
	return suprafata;
}

int Apartament::getPret() const noexcept {
	return pret;
}

void Apartament::setStrada(string strada) {
	this->strada = strada;
}