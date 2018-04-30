#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int ingre[maxn][2];
int stock[maxn];
int need[maxn];

bool make_one(int pos, int step = 0){
	if(step >= 200 or pos == ingre[pos][0] or pos == ingre[pos][1]){
		return false;
	}

	int a = stock[ingre[pos][0]];
	int b = stock[ingre[pos][1]];

	need[ingre[pos][0]]++;
	need[ingre[pos][1]]++;

	if(a < need[ingre[pos][0]] and !make_one(ingre[pos][0], step + 1)){
		return false;
	}
	if(b < need[ingre[pos][1]] and !make_one(ingre[pos][1], step + 1)){
		return false;
	}

	a = stock[ingre[pos][0]];
	b = stock[ingre[pos][1]];

	if(a > 0 and b > 0 and a >= need[ingre[pos][0]] and b >= need[ingre[pos][1]]){
		stock[ingre[pos][0]]--;
		stock[ingre[pos][1]]--;
		need[ingre[pos][0]]--;
		need[ingre[pos][1]]--;
		stock[pos]++;
		return true;
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	int tests;
	std::cin >> tests;

	for(int test = 1; test <= tests; test++){
		int metals;
		std::cin >> metals;

		for(int i = 0; i < metals; i++){
			std::cin >> ingre[i][0] >> ingre[i][1];
			ingre[i][0]--, ingre[i][1]--;
		}

		for(int i = 0; i < metals; i++){
			std::cin >> stock[i];
		}

		for(int i = 0; i <= 10000; i++){
			std::fill(need, need + metals, 0);
			need[0] = maxn;
			make_one(0);
		}

		std::cout << "Case #" << test << ": " << stock[0] << '\n';
	}
}
