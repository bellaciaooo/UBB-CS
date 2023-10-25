#pragma once

#include<iostream>

class Errors {
public:

	std::string FilmNotFound = "Nu este niciun film cu acest titlu";
	std::string NrDuplicat = "Este deja un film cu acest titlu";
	std::string IndexOut = "Indexul specificat este mai mic decat 0 sau mare decat marimea vectorului";

};