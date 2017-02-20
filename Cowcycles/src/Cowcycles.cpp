/*
ID: vlade.m1
PROG: cowcycle
LANG: C++
*/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e3;
int val[maxn];
int f, r;
int f1, f2, r1, r2;
vector<int> fl, rl;
vector<int> fb, rb;
double v[maxn];
double best_standard = 1e9;

void check(){
	for(int i = 0; i < fl.size(); i++){
		for(int j = 0; j < rl.size(); j++){
			v[i * rl.size() + j] = ((double) fl[i]) / ((double) rl[j]);
		}
	}
	sort(v, v + fl.size() * rl.size());
	if(v[fl.size() * rl.size() - 1] < 3.0 * v[0]){
		return;
	}
	double mean = 0;
	for(int i = 1; i < fl.size() * rl.size(); i++){
		v[i - 1] = abs(v[i] - v[i - 1]);
		mean += v[i - 1];
	}
	mean /= (double) (fl.size() * rl.size() - 1.0);
	double check_standard = 0.0;
	for(int i = 0; i < fl.size() * rl.size() - 1; i++){
		check_standard += (mean - v[i]) * (mean - v[i]);
	}
	if(check_standard < best_standard){
		best_standard = check_standard;
		fb = fl, rb = rl;
	}
}

void dfs(int pos, int last, int eend){
	if(pos == 0){
		last = f1;
		eend = f2;
	} else if(pos == f){
		last = r1;
		eend = r2;
	} else if(pos == f + r){
		check();
		return;
	}
	for(; last <= eend; last++){
		if(pos < f){
			fl[pos] = last;
			dfs(pos + 1, last + 1, eend);
		} else {
			rl[pos - f] = last;
			dfs(pos + 1, last + 1, eend);
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//	freopen("cowcycle.in", "r", stdin);
//	freopen("cowcycle.out", "w", stdout);
	cin >> f >> r;
	cin >> f1 >> f2 >> r1 >> r2;

	fl.resize(f);
	rl.resize(r);
	dfs(0, f1, f2);

	for(int i = 0; i < fb.size(); i++){
		cout << fb[i];
		if(i != fb.size() - 1){
			cout << ' ';
		} else {
			cout << endl;
		}
	}
	for(int i = 0; i < rb.size(); i++){
		cout << rb[i];
		if(i != rb.size() - 1){
			cout << ' ';
		} else {
			cout << endl;
		}
	}
}

