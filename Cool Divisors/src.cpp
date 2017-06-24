#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 11111111;
int board[maxn];
std::vector<int> primes;

int main(){
	std::ios::sync_with_stdio(false);

	for(int i = 2; i < maxn; i++){
		if(board[i] == 0){
			board[i] = 1;
			for(int j = i + i; j < maxn; j += i){
				board[j]++;
			}
		}
	}

	return 0;
	// int t;
	// std::cin >> t;

	// for(int test = 0; test < t; test++){
	// 	int a, b, n;
	// 	std::cin >> a >> b >> n;

	// 	b = a + b;

	// 	int divisors = b - a + 1; // every number is divivisible by 1

	// 	for(int i = 2; i * i <= b; i++){
	// 		if(a <= i * i and i * i <= b){
	// 			divisors++;
	// 		}

	// 		for(int j = (i + 1) * i; j <= b; j += i){
	// 			if(a <= j){
	// 				divisors += 2;
	// 			}
	// 		}
	// 	}
	// }
}