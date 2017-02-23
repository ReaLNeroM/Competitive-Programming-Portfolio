/*
ID: vlade.m1
PROG: nocows
LANG: C++
*/
typedef long long ll;
using namespace std;

//#define owncomputer true

#ifdef owncomputer
	#include <iostream>
	#define fin cin
	#define fout cout
#else
	#include <fstream>
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
#endif

ll dp[201][201][2];

ll find(ll l, ll left, bool hastoreach){
	if(dp[l][left][hastoreach] == -1){
		if(l == 0 and left == 0){
			dp[l][left][hastoreach] = hastoreach;
		} else if(l == 0){
			dp[l][left][hastoreach] = 0;
		} else if(left == 0){
			dp[l][left][hastoreach] = !hastoreach;
		} else {
			dp[l][left][hastoreach] = 0;
			if(left % 2 != 0){
				for(int i = 1; i <= left; i++){
					dp[l][left][hastoreach] += find(l - 1, i - 1, hastoreach) * find(l - 1, left - i, hastoreach);
					if(hastoreach){
						dp[l][left][hastoreach] += find(l - 1, i - 1, true) * find(l - 1, left - i, false);
						dp[l][left][hastoreach] += find(l - 1, i - 1, false) * find(l - 1, left - i, true);
					}
				}
				dp[l][left][hastoreach] %= 9901;
			}
		}
	}

	return dp[l][left][hastoreach];
}
int main() {
	ios::sync_with_stdio(false);

	ll n, k;
	fin >> n >> k;

	for(ll i = 0; i <= 200; i++){
		for(ll j = 0; j <= 200; j++){
			for(int l = 0; l < 2; l++){
				dp[i][j][l] = -1;
			}
		}
	}

	fout << find(k, n, 1) << endl;
	return 0;
}
