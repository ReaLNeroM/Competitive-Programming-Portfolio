/*
ID: vlade.m1
PROG: calfflac
LANG: C++
*/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5;
int start[maxn];
int len[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);

	string full;
	string inp;
	while(getline(cin, full)){
		inp += full + '\n';
	}

	string gen = "";
	for(int i = 0; i < inp.size(); i++){
		if('a' <= inp[i] and inp[i] <= 'z'){
			start[gen.size()] = i;
			gen += inp[i];
		} else if('A' <= inp[i] and inp[i] <= 'Z'){
			start[gen.size()] = i;
			gen += inp[i] - 'A' + 'a';
		}
	}
	int best_start = 0, best_end = 0;
	int biggest = 1;
	int l = 0, r = 0;
	len[0] = 1;

	for(int i = 1; i < gen.size(); i++){
		if(i > r){
			l = i;
			r = i;
			len[i] = 1;
		} else {
			len[i] = min(len[l + r - i], r - i);
		}

		while(i - len[i] >= 0 and r + len[i] < gen.size() and gen[i - len[i]] == gen[i + len[i]]){
			len[i]++;
		}

		if(i + len[i] - 1 >= r){
			l = i - len[i] + 1;
			r = i + len[i] - 1;
		}

		if(len[i] * 2 - 1 > biggest){
			best_start = start[i - len[i] + 1];
			best_end = start[i + len[i] - 1];
			biggest = len[i] * 2 - 1;
		}
	}
	for(int i = 0; i < maxn; i++){
		len[i] = 0;
	}

	l = 0, r = -1;
	len[0] = 0;
	for(int i = 1; i < gen.size(); i++){
		if(i > r){
			r = -1;
			l = -1;
			len[i] = 0;
		} else {
			len[i] = min(len[l + r - i + 1], r - i - 1);
		}
		while(i - len[i] - 1 >= 0 and i + len[i] < gen.size() and gen[i - len[i] - 1] == gen[i + len[i]]){
			len[i]++;
		}

		if(i + len[i] - 1 >= r){
			l = i - len[i];
			r = i + len[i] - 1;
		}
		if(len[i] * 2 > biggest){
			best_start = start[i - len[i]];
			best_end = start[i + len[i] - 1];
			biggest = len[i] * 2;
		}
	}

	cout << biggest << endl;
	cout << inp.substr(best_start, best_end - best_start + 1) << endl;
}

