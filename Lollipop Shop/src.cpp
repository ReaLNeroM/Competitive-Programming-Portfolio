#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 205;

int timesseen[maxn];
int liked[maxn];
bool taken[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int tests;
	std::cin >> tests;

	for(int test = 1; test <= tests; test++){
		int n;
		std::cin >> n;

		if(n == -1){
			std::cerr << "Illegal Print!" << '\n';
			return 0;
		}

		memset(timesseen, 0, sizeof(timesseen));
		memset(taken, 0, sizeof(taken));

		for(int i = 0; i < n; i++){
			int preferences;
			std::cin >> preferences;

			memset(liked, 0, sizeof(liked));

			for(int j = 0; j < preferences; j++){
				int id;
				std::cin >> id;

				liked[id] = true;
				timesseen[id]++;
			}

			int smallest_times = maxn;
			int smallest_id = -1;

			for(int j = 0; j < n; j++){
				if(!taken[j] and liked[j] and (smallest_id == -1 or smallest_times > timesseen[j])){
					smallest_times = timesseen[j];
					smallest_id = j;
				}
			}

			std::cout << smallest_id << '\n';

			if(smallest_id != -1){
				taken[smallest_id] = true;
			}
		}
	}
}
