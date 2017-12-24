#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int type[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	for(int i = 0; i < k; i++){
		int pos;
		std::cin >> pos;
		type[pos] = 1;
	}
	for(int i = 0; i < k; i++){
		int pos;
		std::cin >> pos;
		type[pos] = 2;
	}

	int res = 2 * k;

	if(type[0]){
		res--;
	}

	type[0] = type[n];

	int start = -1;
	for(int i = 0; i < n - 1; i++){
		if(!type[i] or !type[i + 1] or type[i] == type[i + 1]){
			start = i + 1;
			break;
		}
	}

	if(start == -1){
		res = k;
	} else {
		for(int i = start; i < start + n - 1; i++){
			if(type[i % n] and type[(i + 1) % n] and type[i % n] != type[(i + 1) % n]){
				i++;
				res--;
			}
		}
	}

	std::cout << res << '\n';
}