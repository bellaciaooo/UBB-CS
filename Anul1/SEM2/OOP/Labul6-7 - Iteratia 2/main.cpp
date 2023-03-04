#include"consola.h"
#include"service.h"
#include"repo.h"
#include"validator.h"
#include"teste.h"

void adaugaFilmePrestabilite(service& crt) {
	crt.addFilm("Spiderman", "actiune", 2018, "Peter");
	crt.addFilm("Emilia", "romantic", 2021, "Ema");
	crt.addFilm("Scooby-Doo", "animatie", 1998, "Fred");
	crt.addFilm("Rose", "animatie", 2021, "Carla");
	crt.addFilm("Turistul", "comedie", 2020, "Jack");
}


int main() {
	//rulam toate testele
	run_all_tests();
	
	repo rep;
	FilmValidator val;
	service crt{ rep,val };
	adaugaFilmePrestabilite(crt);
	consola ui{ crt };
	ui.start();

}