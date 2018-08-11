#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
int n, k, w;
std::vector<int> adj[maxn];
char used[maxn];
int dist[maxn];
std::vector<std::vector<int> > added, bestadded;
bool takenCareOf[maxn];
int taggedDist[maxn];

double score(){
	double sum = 0.0;

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
		return 18.0 * std::pow(20.0, coefficient);
	} else {
		return 10.0 * std::pow(20.0, coefficient);
	}
}

void expand(int pos){
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

	std::srand(4361234);

	double bestscore = 1e18;
	for(int magicJohnson = 1; magicJohnson <= 10; magicJohnson++){
		std::cerr << magicJohnson << ' ';
		std::cout.flush();
		for(int x = 0; x < 50; x++){
			for(auto v : added){
				adj[v[0]].erase(std::find(adj[v[0]].begin(), adj[v[0]].end(), v[1]));
				adj[v[1]].erase(std::find(adj[v[1]].begin(), adj[v[1]].end(), v[0]));
			}
			memset(taggedDist, -1, sizeof(taggedDist));
			added.clear();

			int start = std::rand() % n;
			expand(start);

			int probe = 0;
			for(int curr_k = 0; curr_k < k; curr_k++){
				int i = std::rand() % n;
				probe++;
				if(probe != 100 and (i == start or taggedDist[i] <= magicJohnson)){
					curr_k--;
					continue;
				}
				probe = 0;

				adj[i].push_back(start);
				adj[start].push_back(i);
				expand(i);

				added.push_back({start, i});
			}

			double checkscore = score();
			if(checkscore < bestscore){
				bestscore = checkscore;
				bestadded = added;
			}
		}
	}
	std::cerr << '\n';

	for(int i = 0; i < added.size(); i++){
		std::cout << bestadded[i][0] << ' ' << bestadded[i][1] << '\n';
	}
	std::cerr << grade(bestscore, w) << '\n';
}
