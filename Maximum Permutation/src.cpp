#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 29996224275833LL;
const ll base = 31;

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int i = 0; i < t; i++){
		std::string w, s;
		std::cin >> w >> s;

		int w_chartable[26];
		std::fill(w_chartable, w_chartable + 26, 0);

		for(auto i : w){
			w_chartable[i - 'a']++;
		}

		int s_chartable[26];

		ll rolling_hash = 0;
		ll influence = 1;

		for(int i = 0; i < w.size() - 1; i++){
			s_chartable[s[i] - 'a']++;
			rolling_hash *= base;
			rolling_hash += (s[i] - 'a') + 1;
			rolling_hash %= mod;

			influence *= base;
			influnce %= mod;
		}

		for(int i = w.size() - 1; i < s.size(); i++){
			rolling_hash *= base;
			rolling_hash += (s[i] - 'a') + 1;
			rolling_hash %= mod;
			s_chartable[s[i] - 'a']++;

			bool equal = true;
			for(int j = 0; j < 26; j++){
				if(s_chartable[j] != w_chartable[j]){
					equal = false;
				}
			}

			if(equal){
				m[rolling_hash]++;
			}

			rolling_hash -= (s[i - (w.size() - 1)] + 1) * influence;
			rolling_hash %= mod;
		}
	}
}