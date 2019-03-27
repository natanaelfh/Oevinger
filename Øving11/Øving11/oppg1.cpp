#include "oppg1.h"

void replace(vector<string>& thestring, string old, string replacement) {
	for (vector<string>::iterator i = thestring.begin(); i != thestring.end(); i++) {
		if (*i == old) {
			*i = replacement;
		}
	}
}


void replaceset(set<string>& thestring, string old, string replacement) {
	if (thestring.find(old) != thestring.end()) {
		thestring.erase(old);
		thestring.insert(replacement);
	}
}
