#pragma once

typedef struct
{
	char* nume;
	char* prenume;
	int scor;

}Participant;

/// <summary>
/// Functie care creeaza si returneaza noul participant creat cu campurile introduse.
/// </summary>
/// <param name="nume"></param>
/// <param name="prenume"></param>
/// <param name="scor"></param>
/// <returns></returns>
Participant* createParticipant(char* nume, char* prenume, int scor);

/// <summary>
/// Functie care distruge un participant.
/// </summary>
/// <param name="p"></param>
void destroyParticipant(Participant* p); //eliberam memoria

/// <summary>
/// Functie care returneaza campul 'Nume' al unui participant dat.
/// </summary>
/// <param name="p"></param>
/// <returns></returns>
char* getNume(Participant* p);

/// <summary>
/// Functie care returneaza campul 'Prenume' al unui participant dat.
/// </summary>
/// <param name="p"></param>
/// <returns></returns>
char* getPrenume(Participant* p);

/// <summary>
/// Functie care returneaza campul 'Scor' al unui participant dat.
/// </summary>
/// <param name="p"></param>
/// <returns></returns>
int getScor(Participant* p);

/// <summary>
/// Functie care seteaza campul 'Scor' al unui participant dat.
/// </summary>
/// <param name="p"></param>
/// <param name="scor_nou"></param>
/// <returns></returns>
int setScor(Participant* p, int scor_nou);

/// <summary>
/// Functie care returneaza copia unui participant. 
/// </summary>
/// <param name="p"></param>
/// <returns></returns>
Participant* copyParticipant(Participant* p);

void toString(Participant* p, char str[]);

void testP();

