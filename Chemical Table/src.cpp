#include <bits/stdc++.h>

typedef long long ll;

std::vector<int> score = {0, 0, 0, 0};
std::vector<int> key1 = {0, 0, 0, 0};
std::vector<int> key2 = {0, 0, 0, 0};

int main(){
	std::ios::sync_with_stdio(false);
	int n, m, q;
	std::cin >> n >> m >> q;

	key1[2] = key1[3] = n - 1;
	key2[1] = key2[3] = m - 1;

	score[0] = score[1] = score[2] = score[3] = n + m - 1;

	for(int i = 0; i < q; i++){
		int a, b;
		std::cin >> a >> b;
		a--, b--;

		for(int j = 0; j < 4; j++){
			if(key1[j] == a or key2[j] == b){
				score[j]--;
			}
		}
	}

	std::cout << *std::min_element(score.begin(), score.end()) << '\n';
}