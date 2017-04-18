#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	val[0] = n;
	int curr = 1;

	for(int i = 2; i < n; i++){
		while(curr < k and val[0] % i == 0 and val[0] > i){
			val[0] /= i;
			val[curr] = i;
			curr++;
		}
	}

	if(curr < k){
		std::cout << -1 << std::endl;
		return 0;
	}

	for(int i = 0; i < curr; i++){
		std::cout << val[i] << ' ';
	}
}