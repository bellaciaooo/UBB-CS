#include "Jucator.h"
#include <string>

using std::string;

string Jucator::getNume() const
{
	return nume;
}

string Jucator::getTara() const
{
	return tara;
}

int Jucator::getPunctaj() const noexcept
{
	return punctaj;
}

int Jucator::getRanking() const noexcept
{
	return ranking;
}


