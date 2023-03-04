#include "ElevGUI.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <string>
#include <qmessagebox.h>

void ElevGUI::initGUI()
{
	//main layout
	QHBoxLayout* layMain = new QHBoxLayout;
	this->setLayout(layMain);

	//cream partea stanga a ferestrei
	QWidget* left = new QWidget;
	QVBoxLayout* layLeft = new QVBoxLayout;
	left->setLayout(layLeft);

	//adaugam lista
	listElevi = new QListWidget;
	layLeft->addWidget(listElevi);

	//cream partea dreapta a ferestrei
	QWidget* right = new QWidget;
	QFormLayout* layRight = new QFormLayout;
	right->setLayout(layRight);

	//pt detalii
	layRight->addRow(lblDetalii, editDetalii);
	//pt sort
	layRight->addWidget(btnClasa);
	layRight->addWidget(btnMedie);
	layRight->addWidget(btnNume);
	layRight->addWidget(btnNesort);

	//adaugam partea stanga si dreapta la main
	layMain->addWidget(left);
	layMain->addWidget(right);
}

void ElevGUI::connectSignalsSlots()
{
	QObject::connect(listElevi, &QListWidget::itemClicked, this, &ElevGUI::infoGUI);

	QObject::connect(btnMedie, &QPushButton::clicked, this, &ElevGUI::sortMedie);
	QObject::connect(btnClasa, &QPushButton::clicked, this, &ElevGUI::sortClasa);
	QObject::connect(btnNume, &QPushButton::clicked, this, &ElevGUI::sortNume);
	QObject::connect(btnNesort, &QPushButton::clicked, this, &ElevGUI::unSort);

}

void ElevGUI::reloadListElevi(vector<Elev> elevi)
{
	//curatam ce o fost inainte
	listElevi->clear();

	for (auto& elev : elevi)
	{
		//pt butoanele de delete
		auto widget_buton = new QWidget;
		auto lay_buton = new QHBoxLayout;
		auto buton = new QPushButton("Delete");
		widget_buton->setLayout(lay_buton);
		lay_buton->setAlignment(Qt::AlignRight);
		lay_buton->addWidget(buton);

		QObject::connect(buton, &QPushButton::clicked, this, [=](){
		
			auto reply = QMessageBox::question(this, "Confirmare stergere", "Sunteti sigur ca doriti sa stergeti elevul?",
				QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel);//ultimul e buton default
			if (reply == QMessageBox::Ok) {
				srv.deleteElev(elev);
				reloadListElevi(srv.getAll());
				editDetalii->clear();
			}
			});

		//alegem culoarea
		Qt::GlobalColor color;
		if (elev.getMedia() <= 5)
			color = Qt::red;
		else if (elev.getMedia() >= 9)
			color = Qt::green;
		else color = Qt::yellow;

		//cream item-ul
		string elev_string = to_string(elev.getCodMatricol()) + string(" ") + string(elev.getNume()) + string(" ") + string(elev.getPrenume());
		auto item = new QListWidgetItem(QString::fromStdString(elev_string));
		
		//colorare
		item->setBackground(color);

		//setam informatia invizibila
		string info = string(elev.getNume()) + string(" ") + string(elev.getPrenume()) + string(" ") + to_string(elev.getClasa()) + string(" ") + to_string(elev.getMedia());
		item->setData(Qt::UserRole, QString::fromStdString(info));
		
		//setam marimi
		item->setSizeHint(buton->sizeHint()*2);
		buton->setMaximumSize(item->sizeHint() / 2);
		
		//adaugam item-ul
		listElevi->addItem(item);

		//setam butonul de delete la item
		listElevi->setItemWidget(item, widget_buton);

	}

}

void ElevGUI::infoGUI()
{
	auto selection = listElevi->selectedItems();
	auto selectedItem = selection[0];
	auto info = selectedItem->data(Qt::UserRole).toString();

	editDetalii->setText(info);
}

void ElevGUI::sortMedie()
{
	auto sort_list = srv.sortByMedie();
	reloadListElevi(sort_list);
	editDetalii->clear();
}

void ElevGUI::sortClasa()
{
	auto sort_list = srv.sortByClasa();
	reloadListElevi(sort_list);
	editDetalii->clear();
}

void ElevGUI::sortNume()
{
	auto sort_list = srv.sortByNume();
	reloadListElevi(sort_list);
	editDetalii->clear();
}

void ElevGUI::unSort()
{
	reloadListElevi(srv.getAll());
	editDetalii->clear();
}
