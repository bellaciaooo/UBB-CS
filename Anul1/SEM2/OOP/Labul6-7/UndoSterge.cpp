#include "UndoSterge.h"

UndoSterge::UndoSterge(Film film, irepo& rep) noexcept : film(film), rep(rep) {}

void UndoSterge::DoUndo()
{
	rep.adauga(film);
}
