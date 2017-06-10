#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
bool comp[maxn];
bool my_board[maxn];
std::vector<int> prime;

int main(){
	std::ios::sync_with_stdio(false);

	for(int i = 2; i < 100000; i++){
		if(!comp[i]){
			prime.push_back(i);

			if(i < 10000){
				for(int j = i * i; j < 100000; j += i){
					comp[j] = true;
				}
			}
		}
	}

	int t;
	std::cin >> t;

	for(int x = 0; x < t; x++){
		int l, r;
		std::cin >> l >> r;
		l = std::max(l, 2);

		for(int i = 0; l + i <= r; i++){
			my_board[i] = 1;
		}

		for(int i = 0; i < prime.size(); i++){
			int least = (prime[i] - l % prime[i]) % prime[i];

			if(least + l == prime[i]){
				least += prime[i];
			}
			for(int j = least; l + j <= r; j += prime[i]){
				my_board[j] = 0;
			}
		}

		int res = 0;
		for(int i = 0; l + i <= r; i++){
			if(my_board[i]){
				std::cout << l + i << '\n';
			}
		}

		std::cout << '\n';
	}
}