#pragma once
#include <iostream>

using namespace std;

class Smoothy {
private:
	int pret;

public:
	//constructor
	Smoothy(int pret) : pret{ pret } {}

	virtual int getPret() {
		return this->pret;
	}

	virtual string descriere() = 0;

	//destructor
	~Smoothy() = default;
};

class DecoratorSmoothy : public Smoothy {
private:
	Smoothy& s;

public:


};