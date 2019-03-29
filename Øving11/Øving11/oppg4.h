#include<vector>
#include "time.h"

using namespace std;
template <class T>
T GetMax(T a, T b) {
	T result;
	result = (a > b) ? a : b;
	return (result);


	
}
template <class K>
vector<K> Shuffle(vector<K> list) {
	srand(time(NULL));
	for (int i = 0; i < list.size(); i++) {
		int place = rand() % list.size();
		K temp = list[place];
		list[place] = list[i];
		list[i] = temp;
	}

	return list;
	
}