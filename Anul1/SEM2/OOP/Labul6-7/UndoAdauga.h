#pragma once
#include "ActiuneUndo.h"
#include "repo.h"
#include "Film.h"
#include "irepo.h"

class UndoAdauga : public ActiuneUndo
{
private:
	Film film;
    irepo& rep;
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="film">str Filmul care a fost adaugat</param>
	/// <param name="rep">repo. Repository-ul in care a fost adaugat</param>
	UndoAdauga(Film film, irepo& rep) noexcept;
	void DoUndo() override;
};