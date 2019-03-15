#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 10;
int start[maxn];
int goal[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> start[i];
	}
	for(int i = 0; i < n; i++){
		std::cin >> goal[i];
	}

	if(std::accumulate(start, start + n, 0) != std::accumulate(goal, goal + n, 0)){
		std::cout << -1;
		return 0;
	}
}