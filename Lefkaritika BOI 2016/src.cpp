#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
std::vector<int> app[maxn];
int py[maxn];
int px[maxn];
int dist[2][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> py[i] >> px[i];
		py[i]--, px[i]--;
		app[py[i]].push_back(px[i]);
	}

	for(int i = 0; i < y; i++){
		std::sort(app[i].rbegin(), app[i].rend());
	}

	int curr = 0, prev = 1;
	ll sum = 0;
	for(int i = y - 1; i >= 0; i--){
		int g = 0;
		if(app[i].empty() and app[i + 1].empty()){
			for(int j = x - 1; j >= 0; j--){
				dist[curr][j] = std::min(dist[prev][j] + 1, dist[prev][j + 1] + 1);
				if(dist[curr][j]){
					sum += dist[curr][j] - 1;
				}				
			}
		} else {
			for(int j = x - 1; j >= 0; j--){
				if(g < app[i].size() and app[i][g] == j){
					dist[curr][j] = 0;
					g++;
				} else {
					dist[curr][j] = std::min(dist[curr][j + 1], std::min(dist[prev][j], dist[prev][j + 1])) + 1;
				}
				if(dist[curr][j]){
					sum += dist[curr][j] - 1;
				}
			}
		}

		curr ^= 1;
		prev ^= 1;
	}

	std::cout << sum << std::endl;
}