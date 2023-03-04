#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

UI* createUI(Service* s)
{
	UI* ui = malloc(sizeof(UI));
	if (ui == NULL)
		return NULL;
	ui->serv = s;

	return ui;
}

void destroyUI(UI* ui)
{
	if (ui == NULL)
		return;

	//distrugem service-ul
	destroyService(ui->serv);
	//eliberam memoria
	free(ui);
}

//afisare meniu
void printMenu()
{
	printf("\n-----------------------------------------------------------------------------\n");
	printf(" 0. Iesirea din aplicatie.\n");
	printf(" 1. Adauga participant.\n");
	printf(" 2. Modifica participant existent.\n");
	printf(" 3. Sterge participant.\n");
	printf(" 4. Afisare participanti.\n");
	printf(" 5. Filtrare dupa o proprietate.\n");
	printf(" 6. Sortare participanti dupa scor.\n");
	printf("-----------------------------------------------------------------------------\n");
}

//afisare participanti
void printParticipanti(ParticipantRepo* repo)
{
	//Printare oferte dintr-un repository
	//:param: repo (OfertaRepo*)

	printf("\n");
	int len = getLen(repo);
	if (len == 0)
	{
		printf("Nu exista participanti!\n");
		return;
	}

	for (int i = 0; i < len; i++)
	{
		Participant* participant = getParticipantOnPos(repo, i);

		char ostring[200];
		toString(participant, ostring);
		printf("%d) %s\n", i, ostring);

	}
}

//adaugare participant
int addParticipantUI(UI* ui)
{
	//citim datele din campurile participantului
	char nume[50]={0}, prenume[50]={0};
	int scor = 0;

	printf(" Introduceti numele participantului: ");
	int scanf_result = scanf("%49s", nume);
	printf(" Introduceti prenumele participantului: ");
	scanf_result = scanf("%49s", prenume);
	printf(" Introduceti scorul participantului: ");
	scanf_result = scanf("%d", &scor);
	if (scanf_result == 0)
	{
		printf(" Scorul trebuie sa fie un numar!\n");
		return 0;
	}

	return addParticipant(ui->serv, nume, prenume, scor);
}

//stergere participant
int deleteParticipantUI(UI* ui)
{
	int nr;
	printf(" Introduceti numarul de ordine al participantului: ");
	int scanf_result = scanf("%d", &nr);

	if (nr<0 || nr>getLength(ui->serv))
	{
		printf(" Nu exista oferta cu acest numar de ordine\n");
		return 0;
	}

	if (scanf_result != 0)
		scanf_result = 1;

	return deleteParticipant(ui->serv, nr);
}

//modificare participant
int updateParticipantUI(UI* ui)
{
	int nr, scor_nou;
	printf(" Introduceti numarul de ordine al participantului: ");
	int scanf_result = scanf("%d", &nr);

	if (nr<0 || nr>getLength(ui->serv))
	{
		printf(" Nu exista oferta cu acest numar de ordine\n");
		return 0;
	}
	//citim scorul nou participantului
	printf(" Introduceti scorul nou al participantului: ");
	scanf_result = scanf("%d", &scor_nou);

	return updateParticipant(ui->serv, nr, scor_nou);
}

//ordonare participanti dupa scor
void ordonarePartScorUI(UI* ui)
{
	if (ui == NULL)
		return;
	ParticipantRepo* repo = getRepo(ui->serv);

	if (repo == NULL)
		return;

	if (getLen(repo) == 0)
		printf(" Nu sunt participanti inregistrati!\n");

	printf(" 1. Crescator\n");
	printf(" 2. Descrescator\n");
	printf(" Introduceti modul de sortare: ");
	int mod;
	int scanf_result = scanf("%d", &mod);
	if (scanf_result != 0)
		scanf_result = 1;
	if (mod != 1 && mod != 2)
	{
		printf(" Introduceti un mod valid!");
		return;
	}
	repo = sortarePart(ui->serv, mod);
	printParticipanti(repo);
	destroyRepo(repo);
}

//filtrare dupa proprietate
void proprietateUI(UI* ui)
{
	if (ui == NULL)
		return;
	ParticipantRepo* repo = getRepo(ui->serv);

	if (repo == NULL)
		return;

	if (getLen(repo) == 0)
		printf(" Nu sunt participanti inregistrati!\n");

	printf(" 1. Scor mai mic decat o valoare\n");
	printf(" 2. Nume incepand cu litera data\n");
	printf(" Introduceti o proprietate: ");
	int proprietate;
	int scanf_result = scanf("%d", &proprietate);

	if (proprietate == 1)
	{
		int valoare;
		printf(" Introduceti un numar: ");
		scanf_result = scanf("%d", &valoare);
		if (scanf_result == 0)
		{
			printf(" Nu ati indrodus un numar!");
			return;
		}
		repo = filterbyscor(ui->serv, valoare);

	}
	else if(proprietate == 2)
	{
		char litera;
		printf(" Introduceti o litera: ");
		scanf_result = scanf(" %c", &litera);
		if (scanf_result == 0)
		{
			printf(" Nu ati indrodus o litera!");
			return;
		}
		repo = filterbylitera(ui->serv, litera);
	}
	else
	{
		printf(" Proprietate invalida!");
		return;
	}
	printParticipanti(repo);
	destroyRepo(repo);
}

//functie pentru validare citire numar intreg
int readIntegerNumber(const char* message)
{
	char s[16] = { 0 };
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		int scanf_result = scanf("%15s", s);
		if (scanf_result != 0)
			scanf_result = 1;
		r = sscanf(s, "%d", &res);    
		flag = (r == 1);
		if (flag == 0)
			printf(" Eroare la citirea numarului!\n");
	}
	return res;
}

int validComanda(int comanda)
{
	//verificam daca comanda introdusa este valida
	if (comanda >= 0 && comanda <= 6)
		return 1;
	return 0;
}

//consola aplicatiei
void startUI(UI* ui)
{
	while (1)
	{
		printMenu();
		int comanda = readIntegerNumber(" Introduceti optiunea dorita: ");
		while (validComanda(comanda) == 0)
		{
			printf(" Optiunea introdusa nu exista!\n");
			comanda = readIntegerNumber(" Introduceti optiunea dorita: ");
		}
		if (comanda == 0)
			break;
		switch (comanda)
		{
		case 1:
		{
			int res = addParticipantUI(ui);
			if (res == 1)
				printf(" Participantul a fost adaugat cu succes!\n");
			else
				printf(" Eroare la adaugare!");
			break;
		}
		case 2:
		{
			int res = updateParticipantUI(ui);
			if (res == 1)
				printf(" Participantul a fost modificat cu succes!\n");
			else
				printf(" Eroare la modificare!");
			break;
		}
		case 3:
		{
			int res = deleteParticipantUI(ui);
			if (res == 1)
				printf(" Participantul a fost sters cu succes!\n");
			else
				printf(" Eroare la stergere!");
			break;
		}
		case 4:
		{
			ParticipantRepo* repo = getRepo(ui->serv);
			printParticipanti(repo);
			break;
		}
		case 5:
		{
			proprietateUI(ui);
			break;
		}
		case 6:
		{
			ordonarePartScorUI(ui);
			break;
		}
		}
		
	}
}
