#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
const ll max_pieces_size = 100;
const ll mod = 38461538461538383LL; //biggest prime smaller than (10^18)/26
map<ll, ll> m[max_pieces_size];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	string s;
	cin >> s;

	int pieces;
	cin >> pieces;
	for(int i = 0; i < pieces; i++){
		string small_s;
		cin >> small_s;

		ll hash = 1;
		for(int j = 0; j < small_s.size(); j++){
			hash *= (small_s[j] - 'A');
			hash %= mod;
		}

		m[small_s.size()][hash] = true;
	}

	string gen = "";
	for(int i = 0; i < s.size(); i++){
		gen += s[i];
		
		ll hash = 1;
		for(int j = 0; j < max_pieces_size; j++){
			hash = (hash * (s[i - j] - 'A')) % mod;

			if(m[j + 1].find(hash) != m.end()){
				
			}
		}
	}

	cout << gen;
}
