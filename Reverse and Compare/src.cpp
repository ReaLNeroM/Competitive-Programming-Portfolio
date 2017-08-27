#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 200005;
ll found[26];
ll res = 0;

int main(){
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int n = s.size();

	res = (ll) n * ((ll) n + 1) / 2;

	for(char i : s){
		found[i - 'a']++;
	}

	for(int i = 0; i < 26; i++){
		res -= found[i] * (found[i] + 1) / 2;
	}

	cout << res + 1 << '\n';
}