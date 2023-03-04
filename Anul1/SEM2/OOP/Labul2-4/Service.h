#pragma once
#include "ParticipantRepository.h"

typedef struct
{
	ParticipantRepo* repo;
}Service;

Service* createService(ParticipantRepo* r);
void destroyService(Service* s);

ParticipantRepo* getRepo(Service* s);

int addParticipant(Service* s, char* nume, char* prenume, int scor);

int deleteParticipant(Service* s, int nr);

int updateParticipant(Service* s, int nr, int scor_nou);
int getLength(Service* s);

ParticipantRepo* sortarePart(Service* s, int mod);
ParticipantRepo* filterbyscor(Service* s,int valoare);
ParticipantRepo* filterbylitera(Service* s, char litera);

void testsServ();