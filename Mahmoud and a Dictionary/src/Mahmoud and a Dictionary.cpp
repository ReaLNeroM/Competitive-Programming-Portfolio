#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<string, int> assigned;

struct dsu {
	int ind;
	dsu* par = this;
	dsu* oppo = NULL;
	int size = 0;

	dsu* head(){
		if(par != par->par){
			par = par->head();
			if(par->oppo == NULL){
				par->oppo = oppo;
			}
		}

		return par;
	}
	void merge(dsu* second){
		dsu* first = head();
		second = second->head();

		if(first->oppo != NULL){
			second->oppo = first->oppo;
		} else if(second->oppo != NULL){
			first->oppo = second->oppo;
		}
		if(first->size > second->size){
			second->par = first;
		} else if(first->size < second->size){
			first->par = second;
		} else {
			first->par = second;
			second->size++;
		}
	}
};

const int maxn = 1e6;
dsu v[maxn];

int main(){
	int words, edges, questions;
	cin >> words >> edges >> questions;

	int curr = 0;
	for(int i = 0; i < words; i++){
		string s;
		cin >> s;
		assigned[s] = curr;
		curr++;
		v[i].ind = i;
	}

	for(int i = 0; i < edges; i++){
		int type;
		string a, b;
		cin >> type >> a >> b;

		int ind_a = v[assigned[a]].head()->ind;
		int ind_b = v[assigned[b]].head()->ind;

		if(type == 1){
			if((v[ind_b].oppo != NULL and v[ind_a].head() == v[ind_b].oppo->head()) or
					(v[ind_a].oppo != NULL and v[ind_b].head() == v[ind_a].oppo->head())){
				cout << "NO" << '\n';
			} else {
				v[ind_a].merge(&v[ind_b]);
				cout << "YES" << '\n';
			}
		} else {
			if(v[ind_a].head() == v[ind_b].head()){
				cout << "NO" << '\n';
			} else {
				if(v[ind_a].oppo == NULL){
					v[ind_a].oppo = &v[ind_b];
				} else {
					v[ind_a].oppo->merge(&v[ind_b]);
				}
				if(v[ind_b].oppo == NULL){
					v[ind_b].oppo = &v[ind_a];
				} else {
					v[ind_b].oppo->merge(&v[ind_a]);
				}
				cout << "YES" << '\n';
			}
		}
	}

	for(int i = 0; i < questions; i++){
		string a, b;
		cin >> a >> b;

		int ind_a = v[assigned[a]].head()->ind;
		int ind_b = v[assigned[b]].head()->ind;

		if(v[ind_a].head() == v[ind_b].head()){
			cout << "1\n";
		} else if((v[ind_a].oppo != NULL and v[ind_a].oppo->head() == v[ind_b].head()) or (v[ind_b].oppo != NULL and v[ind_b].oppo->head() == v[ind_a].head())){
			cout << "2\n";
		} else {
			cout << "3\n";
		}
	}
}
