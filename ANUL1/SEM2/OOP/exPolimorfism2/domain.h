#include <iostream>
#include <string>
using std::string;
using std::cout;

//a)
class B {
private:
	int b;

public:
	//constructorul
	B(int b):b{b} {}

	virtual void tiparire() {
		cout << b << ' ';
	}

	//destructorul
	virtual ~B() {
	}
};

//b)
class D : public B {
private:
	string d;

public:
	//constructorul
	D(int b, string d) : B{ b }, d{ d }{}

	void tiparire()
	{
		B::tiparire();
		cout << d;
	}

};