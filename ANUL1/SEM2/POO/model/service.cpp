#include "service.h"
#include <functional>
#include <algorithm>

using namespace std;

vector<Apartament> service::filterApt(function<bool(const Apartament&)> fct)
{
	vector<Apartament> rez;
	vector<Apartament> all{ rep.getAll() };

	copy_if(all.begin(), all.end(), back_inserter(rez), fct);

	return rez;
}

void service::deleteApt(string strada)
{
	Apartament a{ "",1,1 };
	const auto& apartamente = rep.getAll();

	for (const auto& apt : apartamente)
		if (apt.getStrada() == strada)
			a = apt;
	
	rep.sterge(a);
}

void service::addApt(string strada, int suprafata, int pret)
{
	Apartament a{ strada,suprafata,pret };
	rep.adauga(a);
}

void service::modifyApt(string strada1, string strada2)
{
	Apartament apt1{ strada1,1,1 };
	Apartament apt2{ strada2,1,1 };

	for (const auto& a : rep.getAll())
		if (a.getStrada() == apt1.getStrada())
			apt1 = a;

	rep.modifica(apt1, apt2);

}

vector<Apartament> service::filterPret(int p1, int p2)
{
	return filterApt([p1, p2](const Apartament& apt) {
		return apt.getPret() >= p1 && apt.getPret() <= p2;
		});
}
