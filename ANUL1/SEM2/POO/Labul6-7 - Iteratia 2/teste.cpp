#include "teste.h"

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
		assert(re.getMesaj() == "Filmul nu exista\n");
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
}