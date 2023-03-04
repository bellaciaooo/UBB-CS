#include "teste.h"
#include <time.h>

void test_operator() {
	Film m1{ "aaaaaa","aaa",3213,"a" };
	Film m2{ "","",1200,"" };
	m2 = m1;
	assert(m1 == m2);
	Film m3{ "aaaaaa","ret",1113,"fgt" };
	assert(m1 == m3);
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

void test_contor_film() {
	repo rep;
	FilmValidator val;
	service srv{ rep,val };
	srv.addFilm("Spiderman", "animatie", 2018, "Peter");
	srv.addFilm("Emilia", "romantic", 2021, "Ema");
	srv.addFilm("Scooby-Doo", "animatie", 1998, "Fred");
	srv.addFilm("Rose", "animatie", 2021, "Carla");
	srv.addFilm("Turistul", "comedie", 2020, "Jack");
	assert(srv.countFilm("animatie") == 3);
	assert(srv.countFilm("comedie") == 1);
	assert(srv.countFilm("aevre") == 0);
	assert(srv.countFilm("romantic") == 1);
}

void teste_operatii_cos() {
	repo rep;
	FilmValidator val;
	service srv{ rep,val };
	srv.addFilm("Spiderman", "actiune", 2018, "Peter");
	srv.addFilm("Emilia", "romantic", 2021, "Ema");
	srv.addFilm("Scooby-Doo", "animatie", 1998, "Fred");
	srv.addFilm("Rose", "animatie", 2021, "Carla");
	srv.addFilm("Turistul", "comedie", 2020, "Jack");
	srv.adaugaInCos("Rose");
	const auto& cos = srv.getCos();
	assert(cos.size() == 1);
	try {
		srv.adaugaInCos("Rose");
	}
	catch (const repoException& re) {
		assert(re.getMesaj() == "Filmul este deja adaugat in cos!\n");
	}
	try {
		srv.adaugaInCos("sadjsabhdbasbhj");
	}
	catch (const repoException& re) {
		assert(re.getMesaj() == "Filmul nu exista in lista de filme!\n");
	}
	srv.golesteCos();
	assert(cos.size() == 0);
	srv.genereazaCos(3);
	assert(cos.size() == 3);
	srv.golesteCos();
	assert(cos.size() == 0);
	srv.genereazaCos(5);
	assert(cos.size() == 5);
	try {
		srv.genereazaCos(3);
	}
	catch (const repoException& re) {
		assert(re.getMesaj() == "Nu s-au putut adauga toate filmele!\n");
	}
	try {
		srv.genereazaCos(-3);
	}
	catch (const repoException& re) {
		assert(re.getMesaj() == "Numarul trebuie sa fie pozitiv!\n");
	}
	srv.exportCos("banane.txt");
}

void test_undo() {
	repo rep;
	FilmValidator val;
	service srv{ rep,val };
	srv.addFilm("Spiderman", "actiune", 2018, "Peter");
	srv.addFilm("Emilia", "romantic", 2021, "Ema");
	srv.addFilm("Scooby-Doo", "animatie", 1998, "Fred");
	srv.addFilm("Rose", "animatie", 2021, "Carla");
	assert(rep.getAll().size() == 4);
	srv.undo();
	assert(rep.getAll().size() == 3);
	srv.deleteFilm("Spiderman");
	assert(rep.getAll().size() == 2);
	srv.undo();
	assert(rep.getAll().size() == 3);
	srv.modifyFilm("Spiderman", "Coco");
	assert(srv.cautaFilm("Spiderman") == false);
	srv.undo();
	assert(srv.cautaFilm("Spiderman") == true);
	srv.undo();
	srv.undo();
	srv.undo();
	try {
		srv.undo();
	}
	catch (const repoException& re) {
		assert(re.getMesaj() == "Nu se mai poate face undo!\n");
	}
}

void test_repo_fisier() {
	repoFisier rep("test.txt");
	FilmValidator val;
	service srv{ rep,val };
	try {
		srv.addFilm("Spiderman", "actiune", 2018, "Peter");
		srv.addFilm("Emilia", "romantic", 2021, "Ema");
	}
	catch (const repoException& re) {
		assert(re.getMesaj() == "Filmul exista deja!");
	}
	assert(rep.getAll().size() == 2);
	srv.modifyFilm("Spiderman", "Romana");
	srv.deleteFilm("Romana");
	assert(rep.getAll().size() == 1);
}

void test_repo_probabilitati() {
	repoProb rep(1);
	Film m1{ "Spiderman", "actiune", 2018, "Peter" };
	Film m2{ "Emilia", "romantic", 2021, "Ema" };
	try
	{
		rep.adauga(m1);
	}
	catch (const randomException&) {}
	try
	{
		rep.sterge(m1);
	}
	catch (const randomException&) {}
	try
	{
		rep.modifica(m1,m2);
	}
	catch (const randomException&) {}
	try
	{
		rep.cauta(m1);
	}
	catch (const randomException&) {}
	repoProb rep2(0);
	rep2.adauga(m1);
	try
	{
		rep2.adauga(m1);
	}
	catch (const repoException&) {}
	assert(rep2.getAll().size() == 1); 
	assert(rep2.cauta(m1) == true);
	assert(rep2.cauta(m2) == false);
	rep2.modifica(m1, m2);
	rep2.sterge(m1);
	try
	{
		rep2.sterge(m1);
	}
	catch (const repoException&) {}
	try
	{
		rep2.modifica(m1,m2);
	}
	catch (const repoException&) {}
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
	test_contor_film();
	teste_operatii_cos();
	test_undo();
	test_repo_fisier();
	test_repo_probabilitati();
}