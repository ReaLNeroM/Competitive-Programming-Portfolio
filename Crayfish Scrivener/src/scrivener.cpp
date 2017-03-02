#include "grader.h"
typedef long long ll;

const int maxn = 1000005;

int size[maxn];
int pos[maxn];
int depends[maxn][22];
char add[maxn];
int act = 1;
int newp = 1;
int c = 0;

void Init(){
	size[0] = 0;
}

void TypeLetter(char cs){
	add[newp] = cs;
	pos[act++] = newp;
	size[newp] = size[c] + 1;
	depends[newp][0] = c;
	for(int i = 1; i < 22; i++){
		depends[newp][i] = depends[depends[newp][i - 1]][i - 1];
	}
	c = newp;
	newp++;
}

void UndoCommands(int d){
	c = pos[act - d - 1];
	pos[act++] = c;
}

char GetLetter(int need){
	need++;

	int ind = c;
	while(size[ind] != need){
		for(int i = 21; i >= 0; i--){
			if(size[depends[ind][i]] >= need){
				ind = depends[ind][i];
				break;
			}
		}
	}
	return add[ind];
}
