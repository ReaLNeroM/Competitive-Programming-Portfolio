#include <bits/stdc++.h>

typedef long long ll;

const int max_ingredients = 55;
const int max_equals = 55;
const int max_samples = 1000005;

int needed[max_ingredients];
std::deque<int> val[max_ingredients];

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int test = 0; test < t; test++){
		int ingredients, equals;
		std::cin >> ingredients >> equals;

		for(int i = 0; i < ingredients; i++){
			std::cin >> needed[i];
		}

		for(int i = 0; i < ingredients; i++){
			val[i].resize(equals);
			for(int j = 0; j < equals; j++){
				std::cin >> val[i][j];
			}
			std::sort(val[i].begin(), val[i].end());
		}

		int made = 0;

		for(int samples = 1; samples <= max_samples; samples++){
			bool good = true;

			for(int i = 0; i < ingredients; i++){
				while(!val[i].empty() and (val[i][0] * 10) / samples < needed[i] * 9){
					val[i].pop_front();
				}

				if(val[i].empty() or (val[i][0] * 10) / samples > needed[i] * 11){
					good = false;
					break;
				}
			}

			if(good){
				made++;
				samples--;
				for(int i = 0; i < ingredients; i++){
					val[i].pop_front();
				}
			}
		}

		std::cout << "Case #" << test + 1 << ": " << made << '\n';

	}
}
