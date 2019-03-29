#include "oppg1.h"

void replace(std::vector<std::string>& thestring, std::string old, std::string replacement) {
	for (std::vector<std::string>::iterator i = thestring.begin(); i != thestring.end(); i++) {
		if (*i == old) {
			*i = replacement;
		}
	}
}


void replaceset(std::set<std::string>& thestring, std::string old, std::string replacement) {
	if (thestring.find(old) != thestring.end()) {
		thestring.erase(old);
		thestring.insert(replacement);
	}
}
