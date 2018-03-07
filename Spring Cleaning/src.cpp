#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int p[maxn];
int par[maxn];
std::vector<int> rev[maxn];
bool loop[maxn];
bool killed[maxn];
int visited[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	
	int n;
	std::cin >> n;
	
	for(int i = 0; i < n; i++){
		std::cin >> p[i];
		p[i]--;

		rev[p[i]].push_back(i);
	}

	std::fill(par, par + n, -1);
	std::fill(visited, visited + n, -1);

	for(int i = 0; i < n; i++){
		if(visited[i] == -1){
			visited[i] = i;
			int curr = i;
			while(par[p[curr]] == -1){
				par[p[curr]] = curr;
				curr = p[curr];
				visited[curr] = i;
			}

			if(loop[curr] or loop[p[curr]] or visited[p[curr]] != i){
				continue;
			}

			int loop_start = p[curr];

			do {
				loop[curr] = true;
				curr = p[curr];
			} while(!loop[curr]);
		}
	}

	std::vector<std::vector<int>> res;
	for(int i = 0; i < n; i++){
		if(loop[i] and rev[i].size() >= 2 and !killed[i]){
			int curr = i;
			while(p[curr] != i){
				curr = p[curr];
			}

			do {
				res.push_back({par[curr], curr});
				curr = par[curr];
			} while(curr != i);
		}
	}

	for(int i = 0; i < n; i++){
		if(loop[i] and rev[i].size() >= 2){
			std::queue<int> q;
			q.push(i);

			while(!q.empty()){
				int fr = q.front();
				q.pop();

				for(int next : rev[fr]){
					if(!loop[next]){
						if(!killed[fr] and !killed[next]){
							res.push_back({next, fr});
							killed[fr] = true;
						}

						q.push(next);
					}
				}
			}
		}
	}

	for(std::vector<int> i : res){
		std::cout << i[0] + 1 << ' ' << i[1] + 1 << '\n';
	}
}
