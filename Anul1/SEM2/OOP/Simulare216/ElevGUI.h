#pragma once
#include <QtWidgets/QApplication>
#include "repo.h"
#include "service.h"
#include "Elev.h"
#include <iostream>
#include <QListWidget>
#include <QLineEdit>
#include <QLabel>
#include <qpushbutton.h>

using namespace std;

class ElevGUI : public QWidget {
private:
	service& srv;

	//lista elevi
	QListWidget* listElevi;

	//detalii
	QLabel* lblDetalii = new QLabel{"Detalii:"};
	QLineEdit* editDetalii = new QLineEdit;

	//sortare
	QPushButton* btnMedie = new QPushButton("Sortare medie");
	QPushButton* btnClasa = new QPushButton("Sortare clasa");
	QPushButton* btnNume = new QPushButton("Sortare nume");
	QPushButton* btnNesort = new QPushButton("Nesortat");

	void initGUI();
	void connectSignalsSlots();
	void reloadListElevi(vector<Elev> elevi);

public:
	//constructor
	ElevGUI(service& srv) :srv{ srv } {
		initGUI();
		connectSignalsSlots();
		reloadListElevi(srv.getAll());
	}

	void infoGUI();

	void sortMedie();

	void sortClasa();

	void sortNume();

	void unSort();
};