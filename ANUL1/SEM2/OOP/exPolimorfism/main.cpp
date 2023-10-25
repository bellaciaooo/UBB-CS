#include "domain.h"
#include <vector>
using std::vector;

void printAll(vector<Employee*>& all) {
	for (auto& emp : all)
	{
		emp->toString();
		cout << "\n";
	}
}

int main()
{
	vector<Employee*> angajati;
	angajati.push_back(new Employee("Maria"));
	angajati.push_back(new Manager("Ion", 123));
	angajati.push_back(new Manager("Cosmina", 423));
	angajati.push_back(new Employee("Constantin"));
	printAll(angajati);
	for (auto angajat : angajati)
		delete angajat;
	return 0;
}