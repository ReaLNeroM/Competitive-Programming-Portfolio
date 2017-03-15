#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;
int ss[maxn];
int r[maxn];
int tr[maxn];

void sort_manually(int size){
	vector<int> v;
	for(int i = 0; i < s.size(); i++){
		v.push_back({r[i], ss[i]});
	}
	stable_sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++){
		ss[i] = v[i].second;
	}
}

void generate(string s){
	for(int i = 0; i < s.size(); i++){
		r[i] = s[i];
	}
	for(int i = 0; i < s.size(); i++){
		ss[i] = i;
	}

	for(int i = 1; i < s.size(); i *= 2){
		sort_manually(i);

		for(int j = 0; j < s.size(); j++){
			tr[j] = r[j];
		}
		for(int j = 0; j < s.size(); j++){

		}
		for(int j = 0; j < s.size(); j++){
			r[j] = tr[j];
		}
	}
}

int main(){
	string s;
	cin >> s;

	s += '$';

	generate(s);

	for(int i = 0; i < s.size(); i++){
		cout << s.substr(s[i], s.size());
	}
}