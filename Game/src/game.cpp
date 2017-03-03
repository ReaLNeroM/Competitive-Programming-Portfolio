#include "grader.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1505;

int mat[maxn][maxn];
int size = 0;

struct dsu {
	dsu* par = this;
	int ind;
	int bound = 0;

	dsu* head(){
		if(par != par->par){
			par = par->head();
		}

		return par;
	}
	void add(int pos){
		for(int i = 0; i < size; i++){
			mat[ind][i] += mat[pos][i];
			mat[i][ind] = mat[ind][i];
		}
	}
	void merge(dsu* second){
		dsu* first = this;

		if(first->bound > second->bound){
			second->par = first;
			first->add(second->ind);
		} else if(first->bound < second->bound){
			first->par = second;
			second->add(first->ind);
		} else {
			second->par = first;
			first->add(second->ind);
			first->bound++;
		}
	}
};

dsu d[maxn];

void initialize(int n) {
	for(int i = 0; i < maxn; i++){
		d[i].ind = i;
	}
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			mat[i][j] = 1;
		}
		mat[i][i] = 0;
	}
	size = n;
}

int hasEdge(int u, int v) {
	u = d[u].head()->ind;
	v = d[v].head()->ind;

	if(mat[u][v] == 1 and u != v){
		mat[u][v]--;
		mat[v][u]--;
		d[u].merge(&d[v]);
		return 1;
	} else {
		mat[u][v]--;
		mat[v][u]--;
		return 0;
	}
}
