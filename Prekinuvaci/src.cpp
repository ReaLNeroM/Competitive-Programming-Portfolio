#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 16;
const int maxbit = (1 << maxn);
int val[maxn];
int dist[maxbit][maxn];
bool used[maxbit][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		val[i]--;
	}

	memset(dist, -1, sizeof(dist));
	std::priority_queue<std::vector<int>> pq;

	dist[1][0] = 0;
	pq.push({-dist[1][0], 0, 1});

	while(!pq.empty()){
		int frcost = -pq.top()[0];
		int fr = pq.top()[1];
		int frbit = pq.top()[2];
		pq.pop();
		if(used[frbit][fr]){
			continue;
		}
		used[frbit][fr] = true;

		int next = frbit ^ (1 << val[fr]);
		if(dist[next][fr] == -1 or dist[next][fr] > frcost){
			dist[next][fr] = frcost;
			pq.push({-frcost, fr, next});
		}
		for(int i = 0, bit = 1; i < n; i++, bit *= 2){
			if(bit & frbit){
				if(dist[frbit][i] == -1 or dist[frbit][i] > frcost + 1){
					dist[frbit][i] = frcost + 1;
					pq.push({-dist[frbit][i], i, frbit});
				}
			}
		}
	}

	int final = (1 << (n - 1));
	if(dist[final][n - 1] == -1){
		std::cout << "NE\n";
	} else {
		std::cout << dist[final][n - 1] << '\n';
	}
}
