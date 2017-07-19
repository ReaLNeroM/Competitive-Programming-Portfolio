#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int py[maxn], px[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	
	int t;
	std::cin >> t;
	
	for(int test = 0; test < t; test++){
		int n;
		std::cin >> n;
		
		for(int i = 0; i < n; i++){
			std::cin >> py[i] >> px[i];
			sweep[i] = 0;
		}
	}
}