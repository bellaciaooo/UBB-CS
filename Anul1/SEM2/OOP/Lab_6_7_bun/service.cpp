#include "service.h"
#include<functional>
#include<algorithm>
#include<assert.h>

void service::addFilm(string titlu, string gen, int anul_aparitiei, string actor_principal) {
	Film f{ titlu,gen,anul_aparitiei,actor_principal };
	val.validate(f);
	rep.adauga(f);
}

void service::deleteFilm(string titlu) {
	Film f{ "","",1000,"" };
	auto filme = rep.getAll();
	for (int i = 0; i < filme.size(); i++)
		if (filme[i].getTitlu() == titlu)
			f = filme[i];
	rep.sterge(f);

}

void service::modifyFilm(string titlu1, string titlu2) {
	Film f1{ titlu1,"",1000,"" };
	Film f2{ titlu2,"",1000,"" };
	auto filme = rep.getAll();
	for (const auto& film : filme)
		if (film.getTitlu() == titlu1)
			f1 = film;
	rep.modifica(f1,f2);
}

bool service::cautaFilm(string titlu) {
	Film f{ titlu,"",1000,"" };
	return rep.cauta(f);
}

vector<Film> service::filterFilm(function<bool(const Film&)> fct) {
	vector<Film> rez;
	for (const auto& film: rep.getAll() ) {
		if (fct(film)) {
			rez.push_back(film);
		}
	}
	return rez;
}

vector<Film> service::FilterAnAparitie(int an) {
	return filterFilm([an](const Film& f) {
		return f.getAnAparitie() == an;
		});
}
vector<Film> service::FilterTitlu(string titlu) {
	return filterFilm([titlu](const Film& f) {
		return f.getTitlu() == titlu;
		});
}

vector<Film> service::generalSortFilm(bool(*cmp)(const Film&, const Film&)) {
	vector<Film> v{ rep.getAll() }; //fac o copie	
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (!cmp(v[i], v[j])) {
				//interschimbam daca nu e indeplinita relatia
				Film aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	return v;
}

vector<Film> service::sortByTitlu() {
	return generalSortFilm([](const Film& f1, const Film& f2) {
		return f1.getTitlu() < f2.getTitlu();
		});
}

vector<Film> service::sortByActorPrincipal() {
	return generalSortFilm([](const Film& f1, const Film& f2) {
		return f1.getActorPrincipal() < f2.getActorPrincipal();
		});
}

vector<Film> service::sortByAnGen() {
	return generalSortFilm([](const Film& f1, const Film& f2) {
		if (f1.getAnAparitie() == f2.getAnAparitie()) {
			return f1.getGen() < f2.getGen();
		}
		return f1.getAnAparitie() < f2.getAnAparitie();
		});
}