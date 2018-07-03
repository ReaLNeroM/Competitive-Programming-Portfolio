#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
const int adjust = 500;
int val[maxn];
std::vector<int> adj[maxn];
int l[maxn];
int r[maxn];
int in[maxn];
int out[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int h, n;
	std::cin >> h >> n;

	for(int i = 0; i < n; i++){
		int l_gap, l_height, r_gap, r_height;
		std::cin >> l_height >> r_height >> l_gap >> r_gap;

		if(l_gap == 0){
			l[i] = adjust + l_height;
		} else {
			l[i] = adjust - l_gap;
		}
		if(r_gap == 0){
			r[i] = adjust + r_height;
		} else {
			r[i] = adjust - r_gap;
		}
		adj[l[i]].push_back(r[i]);
		in[l[i]]++;
		out[r[i]]++;
	}

	int odd_found = 0;
	for(int i = 1; i < maxn; i++){
		if(in[i] != out[i]){
			odd_found++;
		}
	}

	if(odd_found <= 2){
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}