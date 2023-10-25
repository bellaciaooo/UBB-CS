#include"consola.h"
#include"service.h"
#include"repo.h"
#include"validator.h"
#include"teste.h"
#include"repoFisier.h"
#include"repoProbabilitati.h"
#define _CRT_SECURE_NO_WARNINGS

void adaugaFilmePrestabilite(service& crt) {

	crt.addFilm("Spiderman", "actiune", 2018, "Peter");
	crt.addFilm("Emilia", "romantic", 2021, "Ema");
	crt.addFilm("Scooby-Doo", "animatie", 1998, "Fred");
	crt.addFilm("Rose", "animatie", 2021, "Carla");
	crt.addFilm("Turistul", "comedie", 2020, "Jack");
}

void startUI() {
	//repo rep;
    repoFisier rep("date.txt");
    //repoProb rep(0.5f);
	FilmValidator val;
	service crt{ rep,val };
	//adaugaFilmePrestabilite(crt);
	consola ui{ crt };
	ui.start();
}

int main() {

	//rulam toate testele
	run_all_tests();

	startUI();

	_CrtDumpMemoryLeaks();
	return 0;
}