#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;
int cost[maxn];
std::vector<int> v[maxn];
int bit[maxn];
std::vector<int> pick[4];
int pos[4];
ll best = 1e18;
ll sum = 0;
ll taken = 0;
int n, m, k;

bool remove(){
	ll next = -1;

	if(pos[0] > 0 						  and (next == -1 or pick[0][pos[0] - 1] > pick[next][pos[next] - 1])){
		next = 0;
	}
	if(pos[1] > 0 and pos[3] + pos[1] > k and (next == -1 or pick[1][pos[1] - 1] > pick[next][pos[next] - 1])){
		next = 1;
	}
	if(pos[2] > 0 and pos[3] + pos[2] > k and (next == -1 or pick[2][pos[2] - 1] > pick[next][pos[next] - 1])){
		next = 2;
	}

	if(next == -1){
		return false;
	}
	sum -= pick[next][pos[next] - 1];
	pos[next]--;
	taken--;

	return true;
}

bool add(){
	ll next = -1;

	for(int side = 0; side <= 2; side++){
		if(pos[side] != pick[side].size() and (next == -1 or pick[side][pos[side]] < pick[next][pos[next]])){
			next = side;
		}
	}

	if(next == -1){
		return false;
	}

	sum += pick[next][pos[next]];
	pos[next]++;
	taken++;

	return true;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> m >> k;

	for(int i = 0; i < n; i++){
		std::cin >> cost[i];
	}

	int size[2];

	for(int x = 0; x < 2; x++){
		std::cin >> size[x];

		for(int i = 0; i < size[x]; i++){
			int ind;
			std::cin >> ind;
			ind--;
			bit[ind] |= (1 << x);
		}
	}

	for(int i = 0; i < n; i++){
		pick[bit[i]].push_back(cost[i]);
	}

	for(int i = 0; i < 4; i++){
		std::sort(pick[i].begin(), pick[i].end());
	}

	for(int i = 0; i < 4; i++){
		pos[i] = 0;
	}

	for(int side = 1; side <= 2; side++){
		for(int i = 0; i < k and i < pick[side].size() and taken < m; i++){
			sum += pick[side][i];
			pos[side] = i + 1;
			taken++;
		}
	}

	while(taken < m and add()){
	}

	for(pos[3] = 0; pos[3] <= pick[3].size(); pos[3]++){
		if(pos[3] != 0){
			taken++;
			sum += pick[3][pos[3] - 1];

			while(taken > m){
				if(!remove()){
					break;
				}
			}

			while(true){
				ll prevsum = sum;
				if(remove()){
					add();
					if(sum >= prevsum){
						break;
					}	
				} else {
					break;
				}
			}
		}

		if(taken == m and pos[3] + pos[1] >= k and pos[3] + pos[2] >= k){
			best = std::min(sum, best);
		}
	}

	if(best == 1e18){
		best = -1;
	}

	std::cout << best;
}