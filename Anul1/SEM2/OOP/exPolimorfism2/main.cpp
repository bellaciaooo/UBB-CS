#include "domain.h"
#include <vector>

using std::vector;

//d)
void printAll(vector<B*>& lista)
{
	for (auto& obiect : lista)
	{
		obiect->tiparire();
		cout << "\n";
	}
}

//c)
void construiesteLista() 
{
	vector<B*> lista;
	lista.push_back(new B(8));
	lista.push_back(new D(5, "D5"));
	lista.push_back(new B(-3));
	lista.push_back(new D(9, "D9"));
	printAll(lista);
}

int main()
{
	construiesteLista();
	return 0;
}