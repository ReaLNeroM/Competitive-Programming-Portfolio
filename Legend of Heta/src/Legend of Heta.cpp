#include <iostream>
#include <vector>
#include <string>


typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
const ll max_pieces = 110;
const ll mod = 1e9 + 7;
vector<pair<ll, ll>> hashes[max_pieces];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	string s = "";
	cin >> s;

	ll pieces;
	cin >> pieces;

	for(ll i = 0; i < pieces; i++){
		string small_s;
		cin >> small_s;

		ll hash = 0;
		for(ll j = 0; j < small_s.size(); j++){
			hash = (hash * 31LL + (small_s[j] - 'A')) % mod;
		}

		hashes[small_s.size()].push_back({i, hash});
	}

	string gen = "";

	for(ll i = 0; i < s.size(); i++){
		gen += s[i];

		ll deletions = 0;
		ll prior = pieces;

		ll hash = 0;
		ll influence = 1;
		deletions = 0;
		for(ll j = 0; gen.size() >= 1 + j and j < max_pieces; j++){
			hash = ((gen[gen.size() - 1 - j] - 'A') * influence + hash) % mod;

			for(int k = 0; k < hashes[j + 1].size(); k++){
				if(hashes[j + 1][k].second == hash){
					if(hashes[j + 1][k].first < prior){
						prior = hashes[j + 1][k].first;
						deletions = j + 1;
					}
				}
			}

			influence = (influence * 31LL) % mod;
		}

		for(ll j = 0; j < deletions; j++){
			gen.pop_back();
		}
	}

	gen += '\n';
	cout << gen;
}
