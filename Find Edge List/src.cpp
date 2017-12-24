#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
std::vector<int> v[maxn];
int curr_ind[maxn];

ll hash(ll a, ll b){
	return a * maxn + b;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::map<ll, int> times;

	int sum = 0;
	for(int i = 0; i < n; i++){
		int k;
		std::cin >> k;
		sum += k;

		for(int j = 0; j < k; j++){
			int ind;
			std::cin >> ind;
			ind--;

			v[i].push_back(ind);
			times[hash(i, ind)]++;
			times[hash(ind, i)]++;

			if(j == 0){
				times[hash(i, ind)]--;
				times[hash(ind, i)]--;
			}
		}
	}

	if(sum % 2 == 1){
		std::cout << -1 << '\n';
		return 0;
	}
	
	sum /= 2;

	std::vector<std::vector<int>> e;

	std::queue<std::vector<int>> q;
	for(int i = 0; i < n; i++){
		if(!v[i].empty() and times[hash(i, v[i][0])] == 0){
			q.push({i, 0});
			times[hash(i, v[i][0])] = -1;
			times[hash(v[i][0], i)] = -1;
		}
	}

	for(int i = 0; i < sum; i++){
		if(q.empty()){
			std::cout << -1 << '\n';
			return 0;
		}

		int frind = q.front()[0];
		int frpos = q.front()[1];
		int other = v[frind][frpos];
		curr_ind[frind] = frpos + 1;
		q.pop();

		times[hash(frind, v[frind][frpos])] = -1;
		times[hash(v[frind][frpos], frind)] = -1;

		e.push_back({frind + 1, v[frind][frpos] + 1});

		if(frpos + 1 != v[frind].size()){
		    curr_ind[frind] = frpos + 1;
		    frpos += 1;
		    
			times[hash(frind, v[frind][frpos])]--;
			times[hash(v[frind][frpos], frind)]--;
			
			if(times[hash(frind, v[frind][frpos])] == 0){
				q.push({frind, frpos});
				
				times[hash(frind, v[frind][frpos])] = -1;
				times[hash(v[frind][frpos], frind)] = -1;
			}
		}
		if(curr_ind[other] + 1 != v[other].size()){
			curr_ind[other]++;
			
			times[hash(other, v[other][curr_ind[other]])]--;
			times[hash(v[other][curr_ind[other]], other)]--;

			if(times[hash(other, v[other][curr_ind[other]])] == 0){
				q.push({other, curr_ind[other]});

				times[hash(other, v[other][curr_ind[other]])] = -1;
				times[hash(v[other][curr_ind[other]], other)] = -1;
			}
		}
	}

	for(auto i : e){
		std::cout << i[0] << ' ' << i[1] << '\n';
	}
}

