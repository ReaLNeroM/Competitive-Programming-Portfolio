#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int ind[maxn];
int ind_location[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		freopen("sort.in", "r", stdin);
		freopen("sort.out", "w", stdout);
	#endif

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		ind[i] = i;
	}

	std::sort(ind, ind + n, [](int const &a, int const &b) { return val[a] < val[b]; });
	
	for(int i = 0; i < n; i++){
		ind_location[ind[i]] = i;
	}

	int below_fix_ste
	for(int i = 0; i < n; i++){

	}
}