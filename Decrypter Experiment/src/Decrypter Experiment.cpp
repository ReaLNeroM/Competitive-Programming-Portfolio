#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];

string common = "etiaonsrhldcumfpywgbvkxjqz";

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ifstream fin("text.out");
	ifstream finx("sec.out");
	ofstream fout("res.out");
	int v[256];
	for(int i = 0; i < 256; i++){
		v[i] = 0;
	}

	string s;
	while(getline(fin, s)){
		for(int i = 0; i < s.size(); i++){
			if('a' <= s[i] and s[i] <= 'z'){
				v[s[i] - (97 - 65)]++;
			} else {
				v[s[i]]++;
			}
		}
	}

	vector<pair<int, char>> vv;
	for(int i = 65; i < 65 + 26; i++){
		vv.push_back({-v[i], i});
	}

	sort(vv.begin(), vv.end());

	char identity[256];
	for(int i = 0; i < 256; i++){
		identity[i] = i;
	}

	for(int i = 0; i < vv.size(); i++){
		cout << vv[i].second << endl;
		identity[vv[i].second] = common[i];
	}

	while(getline(finx, s)){
		for(int i = 0; i < s.size(); i++){
			if('a' <= s[i] and s[i] <= 'z'){
				fout << identity[s[i] - (97 - 65)];
			} else if('A' <= s[i] and s[i] <= 'Z'){
				fout << identity[s[i]];
			} else {
				fout << s[i];
			}
		}
		fout << endl;
	}
}

