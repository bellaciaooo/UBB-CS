#include "UI.h"
#include "ParticipantRepository.h"
#include <stdio.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC 

void run()
{
	//cream repository-ul si service-ul.
	ParticipantRepo* repo = createRepo();
	Service* serv = createService(repo);

	UI* ui = createUI(serv);

	addParticipant(serv, "Salcedo", "Bella", 100);
	addParticipant(serv, "Vaida", "Marcel", 50);
	addParticipant(serv, "Muresan", "Andrei", 70);
	addParticipant(serv, "Daniel", "Bota", 40);
	addParticipant(serv, "Oarga", "Paul", 60);
	addParticipant(serv, "Oniga", "Marius", 55);
	startUI(ui);

	destroyUI(ui);
}

int main()
{
	testsRepo(); //rulam testele din repository. 
	testsServ(); //rulam testele din service.
	testP();
	testVectorDinamic();

	run();

	_CrtDumpMemoryLeaks();

	return 0;
}