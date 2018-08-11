#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
int n, k, w;
std::vector<int> adj[maxn];
char used[maxn];
int dist[maxn];
int breaki, breakj;
int comp[maxn];
double alpha = 0.001;

double score(int f, int s){
	memset(used, 0, sizeof(used));
	std::queue<int> q;

	q.push(f);
	q.push(s);
	used[f] = 1;
	used[s] = 2;
	dist[f] = 0;
	dist[s] = 0;

	int s1 = 0;
	int s2 = 0;
	double distsum1 = 0;
	double distsum2 = 0;

	bool finished = false;
	while(!q.empty() and !finished){
		int fr = q.front();
		q.pop();

		for(int next : adj[fr]){
			if(used[next] == 0){
				used[next] = used[fr];
				dist[next] = dist[fr] + 1;
				if(used[next] == 1){
					s1++;
					distsum1 += dist[fr];
				} else if(used[next] == 2){
					s2++;
					distsum2 += dist[fr];
				}

				q.push(next);
			} else if(used[next] != used[fr]){
				finished = true;
				breaki = fr, breakj = next;
				break;
			}
		}
	}

	return s1 * s2 - alpha * (distsum1 + distsum2);
}

void get_comps(){
	memset(comp, -1, sizeof(comp));

	int comps = 1;
	for(int i = 0; i < n; i++){
		if(comp[i] == -1){
			std::queue<int> q;
			q.push(i);
			comp[i] = comps;

			while(!q.empty()){
				int fr = q.front();
				q.pop();

				for(int next : adj[fr]){
					if(comp[next] == -1){
						comp[next] = comps;
						q.push(next);
					}
				}
			}

			comps++;
		}
	}
}

int main(){
	std::cin >> n >> k >> w;

	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	std::srand(235236);

	for(int curr_k = 0; curr_k < k; curr_k++){
		double best = -1e9;
		int besti = -1, bestj = -1;
		int bestbreaki = -1, bestbreakj = -1;
		get_comps();

		for(int i = 0; i < n * n; i++){
			int randi = i / n;
			int randj = i % n;
			if(i % 65536 == 0){
				std::cerr << i << std::endl;
			}
			if(randi < randj){
				continue;
			}

			if(comp[randi] == comp[randj]){
				int currscore = score(randi, randj);
				if(best < currscore){
					best = currscore;
					besti = randi, bestj = randj;
					bestbreaki = breaki, bestbreakj = breakj;
				}
			}
		}

		if(best != 0){
			std::cout << besti << ' ' << bestj << std::endl;

			adj[bestbreaki].erase(std::find(adj[bestbreaki].begin(), adj[bestbreaki].end(), bestbreakj));
			adj[bestbreakj].erase(std::find(adj[bestbreakj].begin(), adj[bestbreakj].end(), bestbreaki));
		} else {
			std::cerr << "FUCK\n";
		}
	}
}
