#include <iostream>
#include <string>

using std::string;
using std::cout;

class Employee {
private:
	string name;

public:
	//constructorul
	Employee(string name): name{name} {}

	virtual void toString() {
		cout << name;
	}

	//destructorul 
	virtual ~Employee() {

	}
};

class Manager : public Employee {
private:
	double bonus;

public:
	//constructor
	Manager(string name, double bonus) : Employee{ name }, bonus{ bonus } {}

	void toString() {
		cout << "Manager:";
		Employee::toString();
	}
};