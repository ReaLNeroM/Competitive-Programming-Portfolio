#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 5;
ll val[maxn];
std::map<ll, ll> app;

int pow2[maxn];
int head[maxn];
int place[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll v;
	std::cin >> v;

	for(int i = 0; i < v; i++){
		dist[i][i] = 0;
		for(int j = i + 1; j < n; j++){
			std::cin >> dist[i][j];
			dist[j][i] = dist[i][j];
		}
	}
}