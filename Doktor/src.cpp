#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int n;
int start = 0;
int pref[maxn];
std::vector<int> events[maxn];

std::vector<int> compute(){
	int res = start;
	int best_vali = 0, best_valj = 0;

	for(int i = 0; i < n; i++){
		int curr = start;
		for(int diff = 1; i - diff >= 0 and i + diff < n; diff++){
			if(val[i - diff] == i + diff){
				curr++;
			} else if(val[i - diff] == i - diff){
				curr--;
			}
			if(val[i + diff] == i - diff){
				curr++;
			} else if(val[i + diff] == i + diff){
				curr--;
			}

			if(res < curr){
				res = curr;
				best_vali = val[i - diff];
				best_valj = val[i + diff];
			}
		}

		curr = start;
		for(int diff = 0; i - diff >= 0 and i + diff + 1 < n; diff++){
			if(val[i - diff] == i + diff + 1){
				curr++;
			} else if(val[i - diff] == i - diff){
				curr--;
			}
			if(val[i + diff + 1] == i - diff){
				curr++;
			} else if(val[i + diff + 1] == i + diff + 1){
				curr--;
			}

			if(res < curr){
				res = curr;
				best_vali = val[i - diff];
				best_valj = val[i + diff + 1];
			}
		}
	}

	return {best_vali + 1, best_valj + 1};
}

std::vector<int> other_compute(){
	int res = start;
	int best_vali = 0, best_valj = 0;

	//odd middle
	for(int i = 0; i < n; i++){
		if(val[i] != i and (i + val[i]) % 2 == 0){
			events[(i + val[i]) / 2].push_back(std::abs(i - (i + val[i]) / 2));
		}
	}
	for(int i = 0; i < n; i++){
		std::sort(events[i].begin(), events[i].end());
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < events[i].size(); j++){
			int curr = j + 1;
			curr += pref[n] - (pref[i + events[i][j] + 1] - pref[i - events[i][j]]);

			if(res < curr){
				res = curr;
				best_vali = val[i - events[i][j]];
				best_valj = val[i + events[i][j]];
			}
		}
	}

	for(int i = 0; i < n; i++){
		events[i].clear();
	}

	//even middle
	for(int i = 0; i < n; i++){
		if(val[i] != i and (i + val[i]) % 2 == 1){
			if(i < (i + val[i]) / 2){
				events[(i + val[i]) / 2].push_back(std::abs((i + val[i]) / 2 - i));
				// std::cout << (i + val[i]) / 2 << ' ' << std::abs((i + val[i]) / 2 - i) << '\n';
			} else {
				events[(i + val[i]) / 2].push_back(std::abs(i - 1 - (i + val[i]) / 2));
				// std::cout << (i + val[i]) / 2 << ' ' << std::abs(i - 1 - (i + val[i]) / 2) << '\n';
			}
		}
	}
	for(int i = 0; i < n; i++){
		std::sort(events[i].begin(), events[i].end());
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < events[i].size(); j++){
			int curr = j + 1;
			curr += pref[n] - (pref[i + events[i][j] + 2] - pref[i - events[i][j]]);

			if(res < curr){
				res = curr;
				best_vali = val[i - events[i][j]];
				best_valj = val[i + events[i][j] + 1];
			}
		}
	}

	return {best_vali + 1, best_valj + 1};
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		val[i]--;

		if(val[i] == i){
			start++;
		}
		pref[i + 1] = start;
	}

	auto get = other_compute();
	std::cout << get[0] << ' ' << get[1] << '\n';
	return 0;

	if(compute() != other_compute()){
		return 0;
		std::cout << compute()[0] << ' ' << compute()[1] << '\n';
		std::cout << "NOOO\n";
		return 0;
	}
}