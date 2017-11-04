#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 305;
int val[maxn][maxn];
int curr[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::priority_queue<std::vector<int>> pq;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> val[i][j];

			if(i < j){
				pq.push({-val[i][j], i, j});
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			curr[i][j] = 1e9 + 1;
		}
		curr[i][i] = 0;
	}

	while(!pq.empty()){
		int frval = -pq.top()[0];
		int frind1 = pq.top()[1];
		int frind2 = pq.top()[2];

		if(curr[frind1][frind2] < frval){
			std::cout << -1 << std::endl;
			return 0;
		} else if(curr[frind1][frind2] == frval){

		} else {
			curr[frind1][frind2] = frval;
		}
	}
}