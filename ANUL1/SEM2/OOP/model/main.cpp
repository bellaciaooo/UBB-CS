#include"console.h"
#include"service.h"
#include"repo.h"
#include <iostream>
#include <fstream>
#include <string>
using std::ofstream;
using std::string;

void addApt(string fileName){
	ofstream g(fileName);
	g << "Hasdeu 50 10000\n";
	g << "Florilor 20 91000\n";
	g << "Eroilor 12 2390\n";
	g << "Grigorescu 15 1299\n";
	g << "Antonescu 28 18000\n";
	g.close();
}

void startUI() {
	addApt("test.txt");
	repo rep("test.txt");
	service srv{ rep };

	consola ui{ srv };

	ui.start();
}

int main()
{
	startUI();
	
	return 0;
}