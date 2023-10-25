#pragma once
#include "ActiuneUndo.h"
#include "Repo.h"
#include "Film.h"

class UndoModifica : public ActiuneUndo
{
private:
	Film film1,film2;
	irepo& rep;
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="film">str Filmul filmul inainte de a fi modificat</param>
	/// <param name="rep">repo. Repository-ul in care a fost adaugat</param>
	UndoModifica(Film film1, Film film2, irepo& rep) noexcept;
	void DoUndo() override;
};
