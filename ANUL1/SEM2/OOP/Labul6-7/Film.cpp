#include "Film.h"

Film& Film::operator=(const Film& f)
{
	if (this == &f) {	return *this; }
	this->titlu = f.titlu;
	this->gen = f.gen;
	this->anul_aparitiei = f.anul_aparitiei;
	this->actor_principal = f.actor_principal;
	return *this;
}

string Film::getTitlu() const {
	return titlu;
}

string Film::getGen() const {
	return gen;
}

int Film::getAnAparitie() const noexcept {
	return anul_aparitiei;
}

string Film::getActorPrincipal() const {
	return actor_principal;
}

void Film::setTitlu(string tit) {
	this->titlu = tit;
}

//gett-eri nefolositi momentan
//void Film::setGen(string gen) {
//	this->gen = gen;
//}
//
//void Film::setAn(int an) {
//	this->anul_aparitiei = an;
//}
//
//void Film::setActor(string actor) {
//	this->actor_principal = actor;
//}