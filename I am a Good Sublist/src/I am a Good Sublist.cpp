#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
const ll mod = 1e9 + 7;
ll ways[maxn];
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int n, t;
	cin >> n >> t;

	for(int i = 0; i < n; i++){
		cin >> val[i];
	}

	ways[0] = 1;
	for(int j = 1; j <= t; j++){
		for(int i = 0; i < n; i++){
			if(j >= val[i]){
				ways[j] += ways[j - val[i]];
				ways[j] %= mod;
			}
		}
	}

	cout << ways[t];
}
