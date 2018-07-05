#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int seg[4 * maxn];
int seg2[4 * maxn];

void build(int ind = 0, int l = 0, int r = maxn - 1){
	if(l == r){
		seg[ind] = val[l];
		seg2[ind] = val[l];
		return;
	}

	int mid = (l + r) / 2;

	build(2 * ind + 1, l, mid);
	build(2 * ind + 2, mid + 1, r);

	seg[ind] = combine(2 * ind + 1, 2 * ind + 2, );
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}
}