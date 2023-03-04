#include "Participant.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


Participant* createParticipant(char* nume, char* prenume, int scor)
{
	Participant* p = malloc(sizeof(Participant));
	if (p == NULL)
		return NULL;
	p->nume = malloc(sizeof(char) * (strlen(nume) + 1));
	if (p->nume != NULL)
		strcpy(p->nume, nume);
	p->prenume = malloc(sizeof(char) * (strlen(prenume) + 1));
	if (p->prenume != NULL)
		strcpy(p->prenume, prenume);
	
	p->scor = scor;

	return p;
}

void destroyParticipant(Participant* p)
{
	if (p == NULL)
		return;

	//dealocam memoria alocata pentru pentru field-urile participantului.
	free(p->nume);
	free(p->prenume);
	
	//dealocam memoria alocata pentru structura participantului.
	free(p);
}

Participant* copyParticipant(Participant* p)
{
	return createParticipant(getNume(p), getPrenume(p), getScor(p));
}

char* getNume(Participant* p)
{
	if (p == NULL)
		return NULL;
	return p->nume;
}

char* getPrenume(Participant* p)
{
	if (p == NULL)
		return NULL;
	return p->prenume;
}

int getScor(Participant* p)
{
	if (p == NULL)
		return 0;
	return p->scor;
}

int setScor(Participant* p, int scor_nou)
{
	if (p == NULL)
		return 0;

	p->scor = scor_nou;
	return 1;
}
void toString(Participant* p, char str[])
{
	if (p == NULL)
		return;
	sprintf(str, "Participantul cu numele: %s , prenumele: %s , scorul: %d. ", getNume(p), getPrenume(p), getScor(p));
}

//--------------------TESTS---------------------
void testP()
{
	Participant* p = createParticipant("Salcedo", "Bella", 100);
	assert(strcmp(getNume(p), "Salcedo") == 0);
	assert(strcmp(getPrenume(p), "Bella") == 0);
	assert(getScor(p) == 100);
	assert(setScor(p, 200) == 1);
	assert(strcmp(getNume(p), "Ceva") != 0);
	assert(strcmp(getPrenume(p), "Ceva") != 0);
	assert(getScor(p) !=100);
	assert(getScor(p) == 200);
	assert(setScor(p, 100) == 1);
	assert(strcmp(getPrenume(p), "Bella") == 0);
	destroyParticipant(p);
	destroyParticipant(NULL);

	p = NULL;
	toString(p, "ceva");
	assert(setScor(p, 100) == 0);
	assert(getNume(p) == NULL);
	assert(getPrenume(p) == NULL);
	assert(getScor(p) == 0);
	
}
