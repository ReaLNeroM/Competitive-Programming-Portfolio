#include <bits/stdc++.h>

//#define fin std::cin
//#define fout std::cout

std::ifstream fin("cbarn.in");
std::ofstream fout("cbarn.out");

using namespace std;
typedef long long ll;

ll dp[1001][8];
deque<ll> val;
ll n;

ll find(ll last, ll doors){
	if(dp[last][doors] == -1){
		if(last == n){
			dp[last][doors] = 0;
		} else if (doors == 0){
			dp[last][doors] = 2000000000;
		} else {
			ll res = 0, best = 2000000000;

			for(ll j = last; j < n; j++){
				res += val[j] * (j - last);
				best = min(best, res + find(j + 1, doors - 1));
			}

			dp[last][doors] = best;
		}
	}

	return dp[last][doors];
}

int main() {
	ll d;
	fin >> n >> d;

	for(ll i = 0; i < n; i++){
		ll inp;
		fin >> inp;
		val.push_back(inp);
	}

	ll minres = 2000000000;
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j <= n; j++){
			for(ll k = 0; k <= d; k++){
				dp[j][k] = -1;
			}
		}
		minres = min(minres, find(0, d));
		val.push_back(val[0]);
		val.pop_front();
	}

	fout << minres << endl;
	return 0;
}
