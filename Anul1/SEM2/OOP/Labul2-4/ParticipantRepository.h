#pragma once
#include "Participant.h"
#include "Vector.h"

typedef struct
{
	VectorDinamic* participanti;
}ParticipantRepo;

ParticipantRepo* createRepo();
void destroyRepo(ParticipantRepo* v);

int getLen(ParticipantRepo* v);

/// <summary>
/// Functie pentru adaugare a unui participant in repository.
/// </summary>
/// <param name="v"></param>
/// <param name="p"></param>
/// <returns></returns>
int add(ParticipantRepo* v, Participant* p);

/// <summary>
/// Functie care returneaza un participant de pe o anumita pozitie din repository.
/// </summary>
/// <param name="v"></param>
/// <param name="pos"></param>
/// <returns></returns>
Participant* getParticipantOnPos(ParticipantRepo* v, int pos);

/// <summary>
/// Functie care sterge un participant de pe o anumita pozitie din repository.
/// </summary>
/// <param name="v"></param>
/// <param name="nr"></param>
/// <returns></returns>
int del(ParticipantRepo* v, int nr);

/// <summary>
/// Functie care modifica un participant de pe o anumita pozitie din repository.
/// </summary>
/// <param name="v"></param>
/// <param name="nr"></param>
/// <param name="scor_nou"></param>
/// <returns></returns>
int update(ParticipantRepo* v, int nr, int scor_nou);

int crescator(Participant* p1, Participant* p2);
int descrescator(Participant* p1, Participant* p2);
/// <summary>
/// Functie de sortare a participantilor din repository in functie de metoda de comparare introdusa.
/// </summary>
/// <param name="v"></param>
/// <param name="cmp"></param>
/// <returns></returns>
ParticipantRepo* sortarePartRepo(ParticipantRepo* v, int (*cmp)(Participant* p1, Participant* p2));

/// <summary>
/// Functie care selecteaza participantii in functie de valoarea scorului introdusa (cu scor mai mic).
/// </summary>
/// <param name="v"></param>
/// <param name="valoare"></param>
/// <returns></returns>
ParticipantRepo* filterbyscorRepo(ParticipantRepo* v, int valoare);

/// <summary>
/// Functie care selecteaza participantii in functie de litera cu care le incepe numele.
/// </summary>
/// <param name="v"></param>
/// <param name="litera"></param>
/// <returns></returns>
ParticipantRepo* filterbyliteraRepo(ParticipantRepo* v, char litera);

void initParticipantRepoForTests(ParticipantRepo* v);
void testsRepo();
