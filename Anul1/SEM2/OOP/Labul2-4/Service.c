#include "Service.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Service* createService(ParticipantRepo* r)
{
	Service* s = malloc(sizeof(Service));
	if (s == NULL)
		return NULL;
	s->repo = r;

	return s;
}

void destroyService(Service* s)
{
	if (s == NULL)
		return;

	//prima data distrugem repository-ul
	destroyRepo(s->repo);
	//eliberam memoria
	free(s);
}

int addParticipant(Service* s, char* nume, char* prenume, int scor)
{
	Participant* p = createParticipant(nume, prenume, scor);
	
	int result = add(s->repo, p);
	
	if (result == 0)
		destroyParticipant(p);

	return result;
}

int deleteParticipant(Service* s, int nr)
{
	int result = del(s->repo, nr);

	return result;
}

int getLength(Service* s)
{
	return getLen(s->repo);
}

int updateParticipant(Service* s, int nr, int scor_nou)
{
	int result = update(s->repo, nr, scor_nou);

	return result;
}

ParticipantRepo* sortarePart(Service* s, int mod)
{
	if (s == NULL)
		return NULL;
	if (mod == 1)
		return sortarePartRepo(s->repo, crescator);
	else
		return sortarePartRepo(s->repo, descrescator);
}

ParticipantRepo* filterbyscor(Service* s, int valoare)
{
	if (s == NULL)
		return NULL;
	return filterbyscorRepo(s->repo, valoare);
}

ParticipantRepo* filterbylitera(Service* s, char litera)
{
	if (s == NULL)
		return NULL;
	return filterbyliteraRepo(s->repo, litera);
}
ParticipantRepo* getRepo(Service* s)
{
	return s->repo;
}
#pragma region TEST
//-------------------TESTS-----------------

//functie pentru rularea testelor din service
void testsServ()
{
	ParticipantRepo* repo = createRepo();
	Service* serv = createService(repo);
	initParticipantRepoForTests(repo); 
	//testam functia de adaugare a participantilor
	assert(addParticipant(serv, "Malone", "Post", 323) == 1);
	//testam functia de modificare a participantilor
	assert(updateParticipant(serv, 0, 100) == 1);
	//testam functia de stergere a participantilor
	assert(deleteParticipant(serv, 1) == 1);

	//distrugem service-ul, care mai apoi distruge repository-ul
	destroyService(serv);

	Service* serv1 = createService(NULL);
	assert(addParticipant(serv1, "Malone", "Post", 323) == 0);
	destroyService(serv1);

	assert(filterbylitera(NULL, 'a') == NULL);
	assert(filterbyscor(NULL, 10) == NULL);
	assert(sortarePart(NULL, 1) == NULL);

	ParticipantRepo* r1 = createRepo();
	Service* s1 = createService(r1);
	addParticipant(s1, "Putin", "Vladimir", 100);
	addParticipant(s1, "Malone", "Post", 323);
	addParticipant(s1, "John", "Wick", 100);

	ParticipantRepo* repof = filterbylitera(s1, 'm');
	assert(repof != NULL);
	destroyRepo(repof);

	ParticipantRepo* repos = filterbyscor(s1, 200);
	assert(repos != NULL);
	destroyRepo(repos);
	
	ParticipantRepo* reposo = sortarePart(s1, 1);
	assert(reposo != NULL);
	destroyRepo(reposo);

	ParticipantRepo* reposo2 = sortarePart(s1, 2);
	assert(reposo2 != NULL);
	destroyRepo(reposo2);
	
	assert(getLength(s1) == 3);
	assert(getRepo(s1) == r1);
	destroyService(s1);
}

#pragma endregion TEST