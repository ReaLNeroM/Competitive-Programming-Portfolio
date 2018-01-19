#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6;
int val[maxn];
int seg[maxn];
int laz[maxn];
int n;

void build(int ind = 0, int l = 1, int r = n){
	if(l == r){
		seg[ind] = -l;
		return;
	}

	int mid = (l + r) / 2;
	build(2 * ind + 1, l, mid);
	build(2 * ind + 2, mid + 1, r);

	seg[ind] = std::max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void update(int q, int ind = 0, int cl = 1, int cr = n){
	if(q <= cl){
		seg[ind]++;
		laz[ind]++;
		return;
	}
	if(cr < q){
		return;
	}

	seg[2 * ind + 1] += laz[ind];
	laz[2 * ind + 1] += laz[ind];
	seg[2 * ind + 2] += laz[ind];
	laz[2 * ind + 2] += laz[ind];
	laz[ind] = 0;

	int mid = (cl + cr) / 2;
	update(q, 2 * ind + 1, cl, mid);
	update(q, 2 * ind + 2, mid + 1, cr);

	seg[ind] = std::max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main(){
	std::ios::sync_with_stdio(false);

	std::ifstream fin("greedy.in");
	std::ofstream fout("greedy.out");
	fin >> n;

	for(int i = 0; i < n; i++){
		fin >> val[i];
		val[i] = n - val[i];
	}
	build();

	for(int i = 0; i < n; i++){
		update(val[i]);

		if(seg[0] >= 0){
			fout << n - i - 1 << '\n';
			return 0;
		}
	}
}