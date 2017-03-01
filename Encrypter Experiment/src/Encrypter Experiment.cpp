#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	char v[256];
	for(int i = 0; i < 256; i++){
		v[i] = i;
	}

	random_shuffle(v + 65, v + 65 + 26);
	for(int i = 97; i < 97 + 26; i++){
		v[i] = v[i - 97 + 65] + (97 - 65);
	}

	ofstream fout("text.out");

	string s;
	while(getline(cin, s)){
		for(int i = 0; i < s.size(); i++){
			s[i] = v[s[i]];
		}
		fout << s << endl;
	}
}

