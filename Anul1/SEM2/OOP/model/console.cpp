#include "console.h"
#include "Apartament.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;

void consola::tipareste(const vector<Apartament>& apartamente)
{
	if (apartamente.size() == 0)
	{
		cout << "Nu sunt apartamente de afisat!\n";
		return;
	}
	cout << "Apartamentele sunt:\n";
	for (const auto& apt : apartamente)
	{
		cout << apt.getStrada() << " (" << apt.getSuprafata() << "m^2) " << apt.getPret() << " euro\n";
	}
}

void consola::adaugaUI()
{
	string strada;
	int suprafata, pret;
	cout << " Strada: ";
	cin >> strada;
	cout << " Suprafata: ";
	cin >> suprafata;
	cout << " Pret: ";
	cin >> pret;
	srv.addApt(strada, suprafata, pret);
}

void consola::stergeUI()
{
	string strada;
	cout << "Introduceti strada apartamentului de sters:";
	cin >> strada;
	srv.deleteApt(strada);
}

void consola::modificaUI()
{
	string s1, s2;
	cout << "Introduceti numele actual al strazii apt-ului: ";
	cin >> s1;
	cout << "Introduceti noul nume al strazii apt-ului: ";
	cin >> s2;
	srv.modifyApt(s1, s2);
}

void consola::filterPretUI()
{
	int p1, p2;
	cout << "Introduceti pretul de inceput al intervalului: ";
	cin >> p1;
	cout << "Introduceti pretul de sfarsit al intervalului: ";
	cin >> p2;
	tipareste(srv.filterPret(p1, p2));
}

void print_menu()
{
	cout << "\nMENIU:\n";
	cout << "0. Iesirea din aplicatie\n";
	cout << "1. Vizualizare toate apartamente\n";
	cout << "2. Sterge apartament\n";
	cout << "3. Adauga apartament\n";
	cout << "4. Modificare apartament\n";
	cout << "5. Filtrare pret\n";
	cout << "--Introduceti optiunea dorita: ";
}

int readInteger()
{
	int nr = -1;
	
	cin >> nr;
	while (cin.fail())
	{
		cout << "Introduceti un numar!\n";
		cin.clear();
		cin.ignore(256, '\n');
		system("CLS");
		print_menu();
		cin >> nr;
	}

	return nr;
}

void consola::start()
{
	while (true) {
		system("CLS");
		print_menu();
		const int cmd = readInteger();
		switch (cmd) {
		case 0:
			return;
		case 1:
			tipareste(srv.getAll());
			break;
		case 2:
			stergeUI();
			break;
		case 3:
			adaugaUI();
			break;
		case 4:
			modificaUI();
			break;
		case 5:
			filterPretUI();
			break;
		default:
			cout << "Comanda invalida\n";

		}
		system("PAUSE");
	}
}
