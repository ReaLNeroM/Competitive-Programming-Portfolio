#include <bits/stdc++.h>
#include "aliens.h"
typedef long long ll;

const int maxn = 5e4 + 1e2;
const int maxk = 1e2 + 1e2;
const int maxm = 1e6 + 1e2;
int dp[maxn][maxk];
int ind[maxn][maxk];
int most[maxm];
int pos[maxn];

ll take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c) {
	for(int i = 0; i < n; i++){
		if(r[i] < c[i]){
			std::swap(r[i], c[i]);
		}
		
		most[r[i]] = r[i] - c[i] + 1;
	}
	
	int currn = 0;
	for(int i = 0; i < m; i++){
		if(most[i] > 0){
			pos[currn] = i;
			currn++;
		}
	}
}

//dp[n][k] = dp[1...lim[n]][k - 1] + (n - j + 1)^2