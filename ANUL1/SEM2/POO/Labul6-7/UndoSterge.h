#pragma once
#include "ActiuneUndo.h"
#include "Film.h"
#include "repo.h"

class UndoSterge : public ActiuneUndo
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
	UndoSterge(Film film, irepo& rep) noexcept;
	void DoUndo() override;
};