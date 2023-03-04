#include "UndoModifica.h"

UndoModifica::UndoModifica(Film film1,Film film2, irepo& rep) noexcept : film1(film1), film2(film2), rep(rep) {}


void UndoModifica::DoUndo()
{
	rep.modifica(film2, film1);
}