#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 30005;
int loc[maxn];
int jmp[maxn];
int dist[maxn];
std::set<int> used[maxn];
std::map<int, int> distmap[maxn];
std::vector<int> building[maxn];

bool less_in_map(int a, int b){
	if(b == 0){
		return true;
	}

	return a < b;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, dogs;
	std::cin >> n >> dogs;

	for(int i = 0; i < dogs; i++){
		std::cin >> loc[i] >> jmp[i];
		building[loc[i]].push_back(jmp[i]);
	}

	std::fill(dist, dist + maxn, 1e9);
	dist[loc[0]] = 0;
	
	std::priority_queue<std::vector<int> > pq;

	distmap[loc[0]][jmp[0]] = dist[loc[0]];
	pq.push({-dist[loc[0]], loc[0], jmp[0]});

	while(!pq.empty()){
		int frdist = -pq.top()[0];
		int ind = pq.top()[1];
		int leap = pq.top()[2];
		pq.pop();

		if(used[ind].empty()){
			dist[ind] = frdist;
			for(int i = 0; i < building[ind].size(); i++){
				if(less_in_map(frdist + 1, distmap[ind][building[ind][i]])){
					distmap[ind][building[ind][i]] = frdist + 1;
					pq.push({-dist[ind], ind, building[ind][i]});
				}
			}
		} else if(used[ind].find(leap) != used[ind].end()){
			continue;
		}
		if(ind == loc[1]){
			break;
		}

		used[ind].insert(leap);

		if(ind - leap >= 0 and less_in_map(frdist + 1, distmap[ind - leap][leap])){
			distmap[ind - leap][leap] = frdist + 1;
			pq.push({-(frdist + 1), ind - leap, leap});
		}		
		if(ind + leap < n and less_in_map(frdist + 1, distmap[ind + leap][leap])){
			distmap[ind + leap][leap] = frdist + 1;
			pq.push({-(frdist + 1), ind + leap, leap});
		}
	}

	if(dist[loc[1]] == 1e9){
		std::cout << -1 << std::endl;
	} else {
		std::cout << dist[loc[1]] << std::endl;
	}
}