#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int dist[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int f, s, g, u, d;
	std::cin >> f >> s >> g >> u >> d;

	std::queue<int> q;

	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	q.push(s);

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		if(fr + u <= f and dist[fr + u] == -1){
			dist[fr + u] = dist[fr] + 1;
			q.push(fr + u);
		}
		if(fr - d >= 1 and dist[fr - d] == -1){
			dist[fr - d] = dist[fr] + 1;
			q.push(fr - d);
		}
	}

	if(dist[g] != -1){
		std::cout << dist[g];
	} else {
		std::cout << "use the stairs";
	}
}