#include "teste.h"
#include <vector>

void test_operator() {
	Film m1{ "aaaaaa","aaa",3213,"a" };
	Film m2{ "","",1200,"" };
	m2 = m1;
	m1 = m1;
	assert(m1.getTitlu() == m2.getTitlu());
}

void test_creeaza_film() {
	Film m{ "Val","com",1234,"Ion" };
	assert(m.getTitlu() == "Val");
	assert(m.getGen() == "com");
	assert(m.getAnAparitie() == 1234);
	assert(m.getActorPrincipal() == "Ion");
	m.setTitlu("Boc");
	assert(m.getTitlu() == "Boc");
}

void test_repo_adauga_film() {
	repo rep;
	Film m{ "a","c",2000,"d" };
	rep.adauga(m);
	const auto& filme = rep.getAll();
	assert(filme.size() == 1);
	try {
		rep.adauga(m);
	//	assert(false);
	}
	catch (const repoException& re) {
		assert(re.getMesaj() == "Filmul exista deja!");
	}
}
void test_repo_sterge_film() {
	repo rep;
	Film m{ "Spiderman", "actiune", 2018, "Peter" };
	Film m1{ "Emilia", "romantic", 2021, "Ema" };
	rep.adauga(m);
	rep.adauga(m1);
	const auto& filme = rep.getAll();
	assert(filme.size() == 2);
	rep.sterge(m);
	const auto& filme1 = rep.getAll();
	assert(filme1.size() == 1);
	try {
		rep.sterge(m);

	}
	catch (const repoException& re) {
		assert(re.getMesaj() == "Filmul nu exista!\n");
	}
}

void test_repo_modifica_film() {
	repo rep;
	Film m1{ "Spiderman", "actiune", 2018, "Peter" };
	Film m2{ "Emilia", "romantic", 2021, "Ema" };
	rep.adauga(m1);
	assert(rep.cauta(m1) == true);
	rep.modifica(m1, m2);
	assert(rep.cauta(m1) == false);
	try {
		rep.modifica(m1, m2);

	}
	catch (const repoException& re) {
		assert(re.getMesaj() == "Filmul nu exista!\n");
	}
	assert(rep.cauta(m2) == true);

}

void test_validare_film() {

	FilmValidator valid;
	Film m1{ "", "romantic", 2021, "Ema" };
	try {
		valid.validate(m1);
	
	}
	catch (const ValidateException& ve) {
		std::stringstream s;
		s << ve;
		assert(s.str() == "Titlul este vid! ");
	}
	Film m2{ "fsfd", "", 2021, "Ema" };
	try {
		valid.validate(m2);
	
	}
	catch (const ValidateException& ve) {
		std::stringstream s;
		s << ve;
		assert(s.str() == "Genul este vid! ");
	}
	Film m3{ "fsfd", "dsfs", 12, "Ema" };
	try {
		valid.validate(m3);
	
	}
	catch (const ValidateException& ve) {
		std::stringstream s;
		s << ve;
		assert(s.str() == "Anul aparitiei nu este valid! ");
	}
	Film m4{ "fsfd", "dsfs", 1212, "" };
	try {
		valid.validate(m4);
	
	}
	catch (const ValidateException& ve) {
		std::stringstream s;
		s << ve;
		assert(s.str() == "Actorul principal este vid! ");
	}
}

void test_srv_adauga_film() {
	repo rep;
	FilmValidator val;
	service srv{ rep,val };
	srv.addFilm("Spiderman", "actiune", 2018, "Peter");
	const auto& filme = srv.getAll();
	assert(filme.size() == 1);
}

void test_srv_sterge_film() {
	repo rep;
	FilmValidator val;
	service srv{ rep,val };
	srv.addFilm("Spiderman", "actiune", 2018, "Peter");
	const auto& filme = srv.getAll();
	assert(filme.size() == 1);
	srv.deleteFilm("Spiderman");
	const auto& filme2 = srv.getAll();
	assert(filme2.size() == 0);
}

void test_srv_modifica_film() {
	repo rep;
	FilmValidator val;
	service srv{ rep,val };
	srv.addFilm("Spiderman", "actiune", 2018, "Peter");
	assert(srv.cautaFilm("Spiderman") == true);
	srv.modifyFilm("Spiderman", "bbbbbbb");
	assert(srv.cautaFilm("Spiderman") == false);
}

void test_filtrari_sortari() {
	repo rep;
	FilmValidator val;
	service srv{ rep,val };
	srv.addFilm("Spiderman", "actiune", 2018, "Peter");
	srv.addFilm("Emilia", "romantic", 2021, "Ema");
	srv.addFilm("Scooby-Doo", "animatie", 1998, "Fred");
	srv.addFilm("Rose", "animatie", 2021, "Carla");
	srv.addFilm("Turistul", "comedie", 2020, "Jack");
	assert(srv.FilterAnAparitie(2021).size() == 2);
	assert(srv.FilterTitlu("Emilia").size() == 1);
	srv.sortByActorPrincipal();
	srv.sortByTitlu();
	srv.sortByAnGen();
}

/*
  Functie folosit in teste
  primeste vector prin valoare -> copy constructor
  returneaza prin valoare -> copy constructor sau move constructor
*/
template <typename MyVector>
MyVector testCopyIterate(MyVector v) {
	int totalAn = 0;
	for (auto el : v) {
		totalAn += el.getAnAparitie();
	}
	Film f{ "total","tt",totalAn, "tt"};
	v.push_back(f);
	return v;
}

template <typename MyVector>
void addFilms(MyVector& v, int cate) {
	for (int i = 0; i < cate; i++) {
		Film f{ std::to_string(i) + "_titlu",std::to_string(i) + "_gen", i + 1000 , std::to_string(i) + "_actor" };
		v.push_back(f);
	}
}

/*
Testare constructori / assignment
E template pentru a refolosi la diferite variante de VectorDinamic din proiect
*/
template <typename MyVector>
void testCreateCopyAssign() {
	MyVector v;//default constructor
	addFilms(v, 100);
	assert(v.size() == 100);
	assert(v[50].getTitlu() == "50_titlu");

	MyVector v2{ v };//constructor de copiere
	assert(v2.size() == 100);
	assert(v2[50].getGen() == "50_gen");

	MyVector v3;//default constructor
	v3 = v;//operator=   assignment
	assert(v3.size() == 100);
	assert(v3[50].getTitlu() == "50_titlu");

	auto v4 = testCopyIterate(v3);
	assert(v4.size() == 101);
	assert(v4[50].getTitlu() == "50_titlu");
}

/*
  Test pentru move constructor si move assgnment
*/
template <typename MyVector>
void testMoveConstrAssgnment() {
	std::vector<MyVector> v;
	//adaugam un vector care este o variabila temporara
	//se v-a apela move constructor
	v.push_back(MyVector{});

	//inseram, la fel se apeleaza move costructor de la vectorul nostru
	v.insert(v.begin(), MyVector{});

	assert(v.size() == 2);

	MyVector v2;
	addFilms(v2, 50);

	v2 = MyVector{};//move assignment

	assert(v2.size() == 0);

}
template <typename MyVector>
void testAll() {
	testCreateCopyAssign<MyVector>();
	testMoveConstrAssgnment<MyVector>();
}


void run_all_tests() {
	test_operator();
	test_creeaza_film();
	test_repo_adauga_film();
	test_repo_sterge_film();
	test_repo_modifica_film();
	test_validare_film();
	test_srv_adauga_film();
	test_srv_sterge_film();
	test_srv_modifica_film();
	test_filtrari_sortari();
	testAll<vector<Film>>();
}