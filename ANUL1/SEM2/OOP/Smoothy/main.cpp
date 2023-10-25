#include <iostream>
#include <vector>
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;
class Smoothy {
private:
	int pret;
public:
	Smoothy(int p) : pret{ p } {};
	virtual int getPret() {
		return this->pret;
	}
	virtual string descriere() = 0;
	virtual ~Smoothy() = default;
};

class BasicSmoothy : public Smoothy {
private:
	string nume;
public:
	BasicSmoothy(int pret, string n) : Smoothy(pret), nume{ n }{}
	string descriere() override {
		return nume;
	}
};

class DecoratorSmoothy : public Smoothy {
private:
	Smoothy* s;
public:
	DecoratorSmoothy(Smoothy* s0) : Smoothy(s0->getPret()), s{ s0 } {}
	virtual string descriere() override {
		return s->descriere();
	};
	virtual int getPret() override {
		return s->getPret();
	}
	virtual ~DecoratorSmoothy() {
		delete s;
	}
};

class SmoothyCuFrisca : public DecoratorSmoothy {
public:
	SmoothyCuFrisca(Smoothy* s) : DecoratorSmoothy(s) {};
	string descriere() override {
		return DecoratorSmoothy::descriere() + " cu frisca";
	};
	int getPret() override {
		return DecoratorSmoothy::getPret() + 2;
	}
};

class SmoothyCuUmbreluta : public DecoratorSmoothy {
public:
	SmoothyCuUmbreluta(Smoothy* s) : DecoratorSmoothy(s) {};
	string descriere() override {
		return DecoratorSmoothy::descriere() + " cu umbreluta";
	};
	int getPret() override {
		return DecoratorSmoothy::getPret() + 3;
	}
};

vector<Smoothy*> functie2() {
	vector<Smoothy*> rez;
	rez.push_back(new SmoothyCuUmbreluta(new SmoothyCuFrisca(new BasicSmoothy{ 1, "kivi" })));
	rez.push_back(new SmoothyCuFrisca(new BasicSmoothy{ 1, "capsuni" }));
	rez.push_back(new BasicSmoothy{ 1, "kivi" });
	return rez;
}
int main() {
	{
		vector<Smoothy*> rez = functie2();
		for (int i = 0; i < rez.size() - 1; i++)
			for (int j = i + 1; j < rez.size(); j++)
				if (rez[i]->descriere() > rez[j]->descriere())
					swap(rez[i], rez[j]);
		for (auto s : rez) {
			cout << s->descriere() << " " << s->getPret() << '\n';
			delete s;
		}
	}
	_CrtDumpMemoryLeaks();
	return 0;
}