#include "ui.h"
#include "service.h"
#include "repo.h"
#pragma once

using std::cout;
using std::cin;

void ui::tipareste(vector<Jucator> jucatori)
{
	if (jucatori.size() == 0)
	{
		cout << "Nu exista jucatori inregistrati!";
		return;
	}

	for (const auto& j : jucatori)
		cout << "Nume: " << j.getNume() << " Tara de origine: " << j.getTara() << " Punctaj: " << j.getPunctaj() << " Ranking: " << j.getRanking()<<"\n";
}

void ui::deleteUI()
{
	int m;
	cout << "Introduceti numarul m de stergeri:";
	cin >> m;
	srv.deleteJucator(m);
}

void print_menu()
{
	cout << "\nMENIU:\n";
	cout << "0. Iesirea din aplicatie\n";
	cout << "1. Stergere jucatori\n";
	cout << "2. Vizualizare jucatori\n";
	cout << "--Introduceti optiunea dorita: ";
}

int readInteger()
{
	int nr = -2;
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

void ui::start()
{
	while (true)
	{
		system("CLS");
		print_menu();
		const int cmd = readInteger();
		switch (cmd)
		{
		case 0:
			return;
		case 1:
			deleteUI();
			break;
		case 2:
			tipareste(srv.getAll());
			break;
		default:
			cout << "Comanda invalida";
		}
		system("PAUSE");
	}
}
