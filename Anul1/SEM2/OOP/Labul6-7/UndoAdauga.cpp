#include "UndoAdauga.h"

UndoAdauga::UndoAdauga(Film film, irepo& rep) noexcept : film(film), rep(rep) { }

void UndoAdauga::DoUndo()
{
	rep.sterge(film);
}
