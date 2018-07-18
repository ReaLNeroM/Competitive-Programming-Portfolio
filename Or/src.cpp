#include <bits/stdc++.h>

typedef long long ll;

const ll MAXN = 5e2 + 1e2;

int subarray_or[MAXN][MAXN];
int val[MAXN][MAXN];

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		freopen("or.in", "r", stdin);
		freopen("or.out", "w", stdout);
	#endif

	ll x, n;
	std::cin >> x >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			val[i][j] = std::rand() % 20000;
			subarray_or[i][j] = val[i][j];
		}
	}

	for(int size = 1; size <= n; size++){
		for(int i = 0; i + size <= n; i++){
			for(int j = 0; j < n; j++){
				subarray_or[i][j] = subarray_or[i][j] | val[i + size - 1][j];
			}
		}
	}
}