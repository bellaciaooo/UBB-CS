#include "consola.h"

#include"Film.h"
#include<iostream>
#include<string>

using std::cout;
using std::cin;

void consola::tipareste(const vector<Film>& filme)
{
	if (filme.size() == 0)
	{
		cout << "Nu sunt filme de afisat!\n";
		return;
	}
	cout << "Filmele sunt:\n";
	for (const auto& film : filme) {
		cout << " Titlu: " << film.getTitlu() << "; Gen: " << film.getGen() << "; An aparitie: " << film.getAnAparitie() << "; Actor principal: " << film.getActorPrincipal() << '\n';
	}
	cout << "***Sfarsit lista filme***\n";
}

void consola::adaugaUI() 
{
	string t, g, c;
	int a;

	cout << "Introduceti titlul filmului: ";
	cin >> t;
	cout << "Introduceti genul filmului: ";
	cin >> g;
	cout << "Introduceti anul aparitiei filmului: ";
	cin >> a;
	cout << "Introduceti actorul principal al filmului: ";
	cin >> c;
	crt.addFilm(t, g, a, c);
	cout << "**Film adaugat cu succes!**\n";
}

void consola::stergeUI() 
{
	string t;
	cout << "Introduceti titlul filmului: ";
	cin >> t;
	crt.deleteFilm(t);
	cout << "**Film sters cu succes!**\n";
}

void consola::modificaUI() 
{
	string t1,t2;

	cout << "Introduceti ACTUALUL titlul filmului: ";
	cin >> t1;
	cout << "Introduceti NOUL titlu al filmului: ";
	cin >> t2;

	crt.modifyFilm(t1,t2);
	cout << "**Filmul a fost modificat cu succes!**\n";
}

bool consola::cautaUI() 
{
	string t;
	cout << "Introduceti titlul filmului: ";
	cin >> t;
	const bool v = crt.cautaFilm(t);
	if (v == true) {
		cout << "Filmul cu titlul : " << t << " se afla in inchirieri.\n";
	}
	else {
		cout << "Filmul cu titlul : " << t << " NU se afla in inchirieri!!!\n";
	}
	return 0;
}

void consola::filterUI() 
{
	cout << " 1 - dupa titlu\n";
	cout << " 2 - dupa anul aparitiei\n";
	cout << "**Introduceti modul de filtrare: ";
	int option;
	cin >> option;
	if (option == 1)
	{
		string t;
		cout << "Introduceti titlul filmului: ";
		cin >> t;
		if (t == "")
			cout << "Titlul este vid!\n";
		else
			tipareste(crt.FilterTitlu(t));
	}
	else if (option == 2)
	{
		int a;
		cout << "Introduceti anul aparitiei filmului: ";
		cin >> a;
		if (a < 1000)
			cout << "Anul este invalid!\n";
		else
			tipareste(crt.FilterAnAparitie(a));
	}
	else
		cout << "Optiune de filtare invalida!\n";
}

void consola::sortUI()
{
	cout << " 1 - dupa titlu\n";
	cout << " 2 - dupa actor principal\n";
	cout << " 3 - dupa anul aparitiei + gen\n";
	cout << "**Introduceti modul de sortare: ";
	int option;
	cin >> option;
	if (option == 1)
	{
		tipareste(crt.sortByTitlu());
	}
	else if (option == 2)
	{
		tipareste(crt.sortByActorPrincipal());
	}
	else if (option == 3)
	{
		tipareste(crt.sortByAnGen());
	}
	else
		cout << "Optiune de sortare invalida!\n";
}

void consola::countUI()
{
	string g;
	cout << "Introduceti genul filmului: ";
	cin >> g;
	if (crt.countFilm(g) == 0)
		cout << "Nu sunt filme care sa aiba genul introdus!\n";
	else
		cout << "Filmele de genul: " << g << " sunt in numar de " << crt.countFilm(g)<<".\n";
}

void consola::adaugaCosUI()
{
	string titlu;
	cout << "Introduceti titlul filmului: ";
	cin >> titlu;
	crt.adaugaInCos(titlu);
	cout << "**Film adaugat in COS cu succes!**\n";
	cout << "Sunt "<<crt.getCos().size()<<" filme in cos.\n";
}

void consola::golesteCosUI()
{
	crt.golesteCos();
	cout << "**Cosul a fost golit cu succes!**\n";
	cout << "Sunt " << crt.getCos().size() << " filme in cos.\n";
}

void consola::genereazaCosUI()
{
	int nr;
	cout << "Introduceti numarul total de filme de generat: ";
	cin >> nr;
	if (cin.fail())
		cout << "Introduceti un numar!\n";
	else
	{
		crt.genereazaCos(nr);
		cout << "**Cosul a fost generat cu succes!**\n";
	}
	cout << "Sunt " << crt.getCos().size() << " filme in cos.\n";
}

void consola::exportCosUI()
{
	string file;
	cout << "Introduceti numele fisierului: ";
	cin >> file;
	crt.exportCos(file.c_str());
	cout << "**Exportul a fost efectuat cu succes!**\n";
	cout << "Sunt " << crt.getCos().size() << " filme in cos.\n";
}

void consola::undoUI()
{
	crt.undo();
	cout << "**Undo-ul a fost efectuat cu succes!**\n";
}

void print_menu()
{
	std::cout << "\nMENIU:\n";
	std::cout << "0. Iesirea din aplicatie\n";
	std::cout << "1. Adauga film\n";
	std::cout << "2. Tipareste lista filme\n";
	std::cout << "3. Sterge film\n";
	std::cout << "4. Modifica film\n";
	std::cout << "5. Cauta film\n";
	std::cout << "6. Filtrare\n";
	std::cout << "7. Sortare\n";
	std::cout << "8. Numarul de filme care au un anumit gen\n";
	std::cout << "9. Adauga film in cos\n";
	std::cout << "10. Goleste cosul de filme\n";
	std::cout << "11. Tipareste cos de filme\n";
	std::cout << "12. Genereaza cos de filme\n";
	std::cout << "13. Export cos de filme in fisier\n";
	std::cout << "14. Undo\n";
	std::cout << "--Introduceti optiunea dorita : ";	
}

int readInteger()
{
	int number = -1;
	
	std::cin >> number;

	while (std::cin.fail())
	{
		std::cout << "Introduceti un numar!\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		system("CLS");
		print_menu();
		std::cin >> number;

	}

	return number;
}


void consola::start() 
{
	while (true) {
		system("CLS");
		print_menu();
		const int cmd = readInteger();
		try {
			switch (cmd) {
			case 0:
				return;
			case 1:
				adaugaUI();
				break;
			case 2:
				tipareste(crt.getAll());
				break;
			case 3:
				stergeUI();
				break;
			case 4:
				modificaUI();
				break;
			case 5:
				cautaUI();
				break;
			case 6:
				filterUI();
				break;
			case 7:
				sortUI();
				break;
			case 8:
				countUI();
				break;
			case 9:
				adaugaCosUI();
				break;
			case 10:
				golesteCosUI();
				break;
			case 11:
				tipareste(crt.getCos());
				break;
			case 12:
				genereazaCosUI();
				break;
			case 13:
				exportCosUI();
				break;
			case 14:
				undoUI();
				break;
			default:
				cout << "Comanda invalida\n";

			}
		}
		catch (const repoException& ex) {
			cout << ex.getMesaj() << '\n';
		}
		catch (const ValidateException& ex) {
			cout << ex << '\n';
		}
		catch (const randomException& ex) {
			cout << ex.getMesaj() << '\n';
		}
		system("PAUSE");
	}
}