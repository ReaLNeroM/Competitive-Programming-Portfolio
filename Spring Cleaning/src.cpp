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

	for(int i = 0; i < n; i++){  //set up par, loop, and visited
		if(visited[i] == -1){
			int curr = i;

			while(visited[curr] == -1){
				if(par[p[curr]] == -1){
					par[p[curr]] = curr;
				}
				visited[curr] = i;
				curr = p[curr];
			}

			if(visited[curr] != i){
				continue;
			}

			while(!loop[curr]){
				loop[curr] = true;
				curr = p[curr];
			}
		}
	}

	std::deque<std::vector<int>> res;

	for(int i = 0; i < n; i++){ //start killing loop at branch point, if needed
		if(loop[i] and rev[i].size() >= 2 and !killed[i] and !killed[p[i]]){
			int curr = i;
			while(p[curr] != i){
				res.push_front({curr, p[curr]});
				killed[p[curr]] = true;
				curr = p[curr];
			}
		}
	}
	for(int i = 0; i < n; i++){ //start killing loop wherever
		if(loop[i] and !killed[i] and !killed[p[i]]){
			int curr = i;
			while(p[curr] != i){
				res.push_front({curr, p[curr]});
				killed[p[curr]] = true;
				curr = p[curr];
			}
		}
	}

	for(int i = 0; i < n; i++){ //if a tree branches out from a loop node, propagate backwards
		if(loop[i] and rev[i].size() >= 2){
			std::queue<int> q;
			q.push(i);

			while(!q.empty()){
				int fr = q.front();
				q.pop();

				for(int next : rev[fr]){
					if(!loop[next]){
						if(!killed[fr]){
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
	
