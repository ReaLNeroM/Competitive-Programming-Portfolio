#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 45;
ll val[maxn];
ll board[1LL << 22];
ll boards[1LL << 22];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, limit;
	std::cin >> n >> limit;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	ll a = (n + 1) / 2;

	board[0] = 0;
	for(ll bitset = 1; bitset < (1LL << a); bitset++){
		board[bitset] = 0;
		for(ll i = 0, bit = 1; bit <= bitset; i++, bit *= 2){
			if(bit & bitset){
				board[bitset] += val[i];
			}
		}
	}
	std::sort(board, board + (1LL << a));

	boards[0] = 0;
	for(ll bitset = 1; bitset < (1LL << (n - a)); bitset++){
		boards[bitset] = 0;
		for(ll i = n - 1, bit = 1; bit <= bitset; i--, bit *= 2){
			if(bit & bitset){
				boards[bitset] += val[i];
			}
		}
	}
	std::sort(boards, boards + (1LL << (n - a)));

	ll res = 0;

	ll pos = (1LL << (n - a)) - 1;

	for(ll i = 0; i < (1LL << a); i++){
		if(board[i] <= limit){
			while(board[i] + boards[pos] > limit){
				pos--;
			}

			res += pos + 1LL;
		}
	}

	std::cout << res << std::endl;
}