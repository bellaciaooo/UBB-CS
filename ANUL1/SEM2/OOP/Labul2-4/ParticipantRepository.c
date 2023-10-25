#include "ParticipantRepository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

ParticipantRepo* createRepo()
{
	ParticipantRepo* v = (ParticipantRepo*)malloc(sizeof(ParticipantRepo));
	if (v == NULL)
		return NULL;

	v->participanti = createVectorDinamic(CAPACITY, destroyParticipant);
		
	return v;
}

void destroyRepo(ParticipantRepo* v)
{
	if (v != NULL)
	{
		destroyVector(v->participanti);
		free(v);
	}
}

int getLen(ParticipantRepo* v)
{
	return getVectorLen(v->participanti);
}

int add(ParticipantRepo* v, Participant* p)
{
	if (v == NULL || p == NULL)
		return 0;
	addTElem(v->participanti, p);

	return 1;
}

Participant* getParticipantOnPos(ParticipantRepo* v, int pos)
{
	if (v == NULL)
		return NULL;
	if (pos < 0 || pos >= getVectorLen(v->participanti))
		return NULL;
	return get(v->participanti, pos);
}

int del(ParticipantRepo* v, int nr)
{
	if (nr < 0 || nr >= getVectorLen(v->participanti))
		return 0;

	deleteTElem(v->participanti, nr);
	return 1;
}

int update(ParticipantRepo* v, int nr, int scor_nou)
{
	if (nr < 0 || nr >= getVectorLen(v->participanti))
		return 0;

	setScor(get(v->participanti, nr), scor_nou);
	return 1;
}

int crescator(Participant* p1, Participant* p2)
{
	if (getScor(p1) > getScor(p2))
		return 0;
	return 1;
}

int descrescator(Participant* p1, Participant* p2)
{
	if (getScor(p1) < getScor(p2))
		return 0;
	return 1;
}

ParticipantRepo* sortarePartRepo(ParticipantRepo* v, int (*cmp)(Participant* p1, Participant* p2))
{
	ParticipantRepo* repo_nou = createRepo();
	int len = getLen(v);

	for (int i = 0; i < len; i++)
		add(repo_nou, copyParticipant(get(v->participanti, i)));

	int ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (int i = 0; i < len - 1; i++)
		{
			Participant* p1 = get(repo_nou->participanti, i);
			Participant* p2 = get(repo_nou->participanti, i + 1);
			if (cmp(p1,p2) == 0)
				{
					swapTElemets(repo_nou->participanti, i, i + 1);
					ok = 0;
				}
			
		}
	}

	return repo_nou;
}

ParticipantRepo* filterbyscorRepo(ParticipantRepo* v, int valoare)
{
	ParticipantRepo* repo_nou = createRepo();
	int len = getLen(v);

	for (int i = 0; i < len; i++)
	{
		Participant* participant = get(v->participanti, i);
		if (getScor(participant) < valoare)
		{
			add(repo_nou, copyParticipant(participant));
		}
	}
	return repo_nou;
}

ParticipantRepo* filterbyliteraRepo(ParticipantRepo* v, char litera)
{
	ParticipantRepo* repo_nou = createRepo();
	int len = getLen(v);

	for (int i = 0; i < len; i++)
	{
		Participant* participant = get(v->participanti, i);
		if (getNume(participant)[0] == litera || getNume(participant)[0] == litera+32 || getNume(participant)[0] == litera-32)
		{
			add(repo_nou, copyParticipant(participant));
		}
	}
	return repo_nou;
}
//-------------------TESTS----------------------

//functie de intializare repository pentru teste
void initParticipantRepoForTests(ParticipantRepo* v)
{
	Participant* p = createParticipant("Pop", "Maria", 18);
	add(v, p);
}

void testAdd()
{
	ParticipantRepo* v = createRepo();
	initParticipantRepoForTests(v);
	assert(getLen(v) == 1);

	Participant* p = createParticipant("Haiduc", "Vasile", 32);
	assert(add(v, p) == 1);
	assert(getLen(v) == 2);

	//distrugem repository-ul de test
	destroyRepo(v);

	destroyRepo(NULL);
}

void testDelete()
{
	ParticipantRepo* v = createRepo();
	initParticipantRepoForTests(v);
	assert(getLen(v) == 1);

	Participant* p = createParticipant("Haiduc", "Vasile", 32);
	add(v, p);
	assert(getLen(v) == 2);

	//verificam daca s-a efectuat cu succes stergerea
	assert(del(v, 1) == 1);

	//incercam sa stergem un participant cu un numar de ordine inexistent => se va returna valoarea 0.
	assert(del(v, 4) == 0);

	//distrugem repository-ul de test
	destroyRepo(v);
}

void testUpdate()
{
	ParticipantRepo* v = createRepo();
	initParticipantRepoForTests(v);
	assert(getLen(v) == 1);

	Participant* p = createParticipant("Haiduc", "Vasile", 32);
	add(v, p);
	assert(getLen(v) == 2);

	//verificam validitatea valorii scorului participantului
	update(v, 1, 541);
	//verificam daca s-a efectuat cu succes modificarea

	//incercam sa modificam un participant cu un numar de ordine inexistent => se va returna valoarea 0.
	assert(update(v, 4, 1321) == 0);

	//distrugem repository-ul de test
	destroyRepo(v);
}

//test pentru getParticipantOnPos()
void testGetPart()
{
	ParticipantRepo* v = createRepo();
	Participant* p2 ;
	
	assert(getParticipantOnPos(v, 0) == NULL);
	
	initParticipantRepoForTests(v);
	assert(getParticipantOnPos(v, 11) == NULL);
	Participant* p = createParticipant("Haiduc", "Vasile", 32);
	add(v, p);
	
	p2 = getParticipantOnPos(v, 1);
	assert(p2 != NULL);
	
	assert(getParticipantOnPos(NULL, 21) == NULL);
	//distrugem repository-ul de test
	
	destroyRepo(v);
}


//functie unde rulam toate testele
void testsRepo()
{
	testAdd();
	testDelete();
	testUpdate();
	testGetPart();
}