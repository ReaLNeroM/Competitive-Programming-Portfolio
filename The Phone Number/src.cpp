#include <bits/stdc++.h>

typedef long long ll;


int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	int sqrtn = std::sqrt(n);

	for(int i = sqrtn; i - sqrtn <= n; i += sqrtn){
		for(int j = i; j + sqrtn > i; j--){
			if(j <= n){
				std::cout << j << ' ';
			}
		}
	}
}
