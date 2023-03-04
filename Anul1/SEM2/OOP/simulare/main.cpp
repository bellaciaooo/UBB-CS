#include "ui.h"
#include "repo.h"
#include "service.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::ofstream;

void addJucatoriFisier(string fileName)
{
	ofstream g(fileName);
	//adaugam 10 inregistrari prestabilite la lansarea aplicatiei
	g << "Paul Romania 130 2\n";
	g << "Iulian Romania 75 5\n";
	g << "Miguel Spania 100 3\n";
	g << "Radu Romania 210 1\n";
	g << "Andres Spania 90 4\n";
	g << "Federico Italia 70 6\n";
	g << "Catalin Romania 49 9\n";
	g << "Sara Italia 65 7\n";
	g << "Cezar Brazilia 58 8\n";
	g << "Flavius Romania 35 10\n";
	g << "Cristian Moldova 20 11\n";
	g.close();
}

void startUI()
{
	addJucatoriFisier("jucator.txt");
	repo rep("jucator.txt");
	service srv{ rep };

	ui crt{ srv };
	crt.start();
}

int main()
{
	startUI();

	return 0;
}
