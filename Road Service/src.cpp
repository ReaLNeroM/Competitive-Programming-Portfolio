#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
int n, k, w;
std::vector<int> adj[maxn];
char used[maxn];
int dist[maxn];
std::vector<std::vector<int>> candidates, bestCandidates;
int taggedDist[maxn];

int score(){
	int sum = 0;

	for(int i = 0; i < n; i++){
		memset(used, false, sizeof(used));
		std::queue<int> q;
		q.push(i);
		used[i] = true;
		dist[i] = 0;

		while(!q.empty()){
			int fr = q.front();
			q.pop();
			if(i <= fr){
				sum += dist[fr];
			}

			for(int next : adj[fr]){
				if(!used[next]){
					used[next] = true;
					dist[next] = dist[fr] + 1;
					q.push(next);
				}
			}
		}
	}

	return sum;
}

double grade(double w, double w0){
	double coefficient = 1.0 - w/w0;

	if(n == 1000){
		return 18.0 * std::min(1.0, std::pow(20.0, coefficient));
	} else {
		return 10.0 * std::min(1.0, std::pow(20.0, coefficient));
	}
}

void addNewSource(int pos){
	std::queue<int> q;
	q.push(pos);
	taggedDist[pos] = 0;

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		for(int next : adj[fr]){
			if(taggedDist[next] == -1 or taggedDist[next] > taggedDist[fr] + 1){
				taggedDist[next] = taggedDist[fr] + 1;
				q.push(next);
			}
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

	std::srand(std::time(0));

	int bestScore = 1e9;
	double bestMagic = 0.0;
	for(int minDistThreshold = 2; minDistThreshold <= 8; minDistThreshold++){
		std::cerr << minDistThreshold << ' ';
		std::cout.flush();
		for(int x = 0; x < 100; x++){
			for(auto& v : candidates){
				adj[v[0]].erase(std::find(adj[v[0]].begin(), adj[v[0]].end(), v[1]));
				adj[v[1]].erase(std::find(adj[v[1]].begin(), adj[v[1]].end(), v[0]));
			}
			memset(taggedDist, -1, sizeof(taggedDist));
			candidates.clear();

			int start = std::rand() % n;
			addNewSource(start);

			int besti = start;
			int randomNodesIte = 0;
			for(int curr_k = 0; curr_k < k; curr_k++){
				int i = std::rand() % n;
				randomNodesIte++;

				if(taggedDist[i] >= minDistThreshold and (besti == start or taggedDist[besti] > taggedDist[i])){
					besti = i;
				}
				if(randomNodesIte < 250){
					curr_k--;
					continue;
				}
				randomNodesIte = 0;
				candidates.push_back({start, besti});

				adj[besti].push_back(start);
				adj[start].push_back(besti);
				addNewSource(besti);
				besti = start;

			}

			int checkScore = score();
			if(checkScore < bestScore){
				bestScore = checkScore;
				bestMagic = minDistThreshold;
				bestCandidates = candidates;
			}
		}
	}

	std::cerr << '\n';

	for(auto& v : bestCandidates){
		std::cout << v[0] << ' ' << v[1] << '\n';
	}

	std::cerr << bestMagic << ' ' << grade(bestScore, w) << '\n';
}
