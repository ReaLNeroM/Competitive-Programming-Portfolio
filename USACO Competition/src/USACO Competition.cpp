#include <bits/stdc++.h>

#define fin std::cin
#define fout std::cout

//std::ifstream fin("fortmoo.in");
//std::ofstream fout("fortmoo.out");

using namespace std;
typedef long long ll;

struct unionset {
	unionset* parent = this;
	ll rank = 0;

	unionset* head(){
		if(parent != parent->parent){
			parent = parent->head();
		}

		return parent;
	}
	void unite(unionset* s){
		head();
		s = s->head();

		if(parent->rank > s->rank){
			s->parent = parent;
		} else if(parent->rank < s->rank){
			parent->parent = s;
		} else {
			s->parent = parent;
			rank++;
		}
	}
};

int main() {
	ll x, y;
	fin >> x >> y;

	ll v, h;
	fin >> v >> h;
	ll ver[v], hor[h];
	for(int i = 0; i < v; i++){
		fin >> ver[i];
	}
	for(int i = 0; i < h; i++){
		fin >> hor[i];
	}
	sort(ver, ver + v);
	sort(hor, hor + h);

	ll lx = 0, ly = 0;
	for(int i = 0; i < y; i++){face
		lx = 0;
		for(int j = 0; j < x; j++){

		}
	}
	return 0;
}
