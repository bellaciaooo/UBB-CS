#include "validator.h"
//#include<assert.h>
#include<sstream>
#include<string>

void FilmValidator::validate(const Film& f) {
	vector<string>msgs;
	if (f.getTitlu().size() == 0)msgs.push_back("Titlul este vid!");
	if (f.getAnAparitie() < 1000)msgs.push_back("Anul aparitiei nu este valid!");
	if (f.getGen().size() == 0)msgs.push_back("Genul este vid!");;
	if (f.getActorPrincipal().size() == 0)msgs.push_back("Actorul principal este vid!");
	if (msgs.size() > 0) {
		throw ValidateException(msgs);
	}
}

ostream& operator<<(ostream& out, ValidateException ex) {
	for (const auto& msg : ex.msgs) {
		out << msg << " ";
	}
	return out;
}
