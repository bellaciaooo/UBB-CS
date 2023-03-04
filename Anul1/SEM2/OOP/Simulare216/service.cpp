#include "service.h"

vector<Elev> service::generalSort(function<bool(const Elev&, const Elev&)> fct)
{
	vector<Elev> all{ rep.getAll() };

	sort(all.begin(), all.end(), fct);

	return all;
}

void service::deleteElev(const Elev& e)
{
	rep.deleteElev(e);
}

vector<Elev> service::sortByMedie()
{
	return generalSort([](const Elev& e1, const Elev& e2) {
		return e1.getMedia() <= e2.getMedia();
		});
}

vector<Elev> service::sortByClasa()
{
	return generalSort([](const Elev& e1, const Elev& e2) {
		return e1.getClasa() < e2.getClasa();
		});
}

vector<Elev> service::sortByNume()
{
	return generalSort([](const Elev& e1, const Elev& e2) {
		return e1.getNume() <= e2.getNume();
		});
}
