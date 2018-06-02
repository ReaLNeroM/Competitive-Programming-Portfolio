#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1e2;
const int maxbit = 20;
std::vector<int> adj[maxn];
int height[maxn];
int up[maxn][maxbit];
int sum[maxn];

int jump_up(int pos, int steps){
	for(int i = 0, bit = 1; bit <= steps; i++, bit *= 2){
		if(steps & bit){
			pos = up[pos][i];
		}
	}

	return pos;
}

int get_lca(int a, int b){
	if(height[a] > height[b]){
		std::swap(a, b);
	}

	if(height[a] != height[b]){
		b = jump_up(b, height[b] - height[a]);
	}

	int l = 0, r = height[a];
	int best = 0;
	while(l <= r){
		int mid = (l + r) / 2;

		if(jump_up(a, mid) == jump_up(b, mid)){
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return best;
}

void landslide(int n) {
	std::fill(height, height + maxn, -1);

	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	std::queue<int> q;
	q.push(0);
	height[0] = 0;
	up[0][0] = -1;

	while(!q.empty()){
		int fr = q.top();
		q.pop();

		for(int next : adj[fr]){
			if(height[next] == -1){
				height[next] = height[fr] + 1;
				up[next][0] = fr;
				q.push(next);
			}
		}
	}

	for(int j = 1; j < maxbit; j++){
		for(int i = 0; i < n; i++){
			if(up[i][j - 1] == -1){
				up[i][j] = -1;
			} else {
				up[i][j] = up[up[i][j - 1]][j - 1];
			}
		}
	}

	int q;
	std::cin >> q;

	for(int i = 0; i < n; i++){
		char type;
		int f, s;
		std::cin >> type >> f >> s;
		f--, s--;

		if(height[f] > height[s]){
			std::swap(f, s);
		}

		if(type == 'd' or type == 'c'){
			int inc = 1;
			if(type == 'c'){
				inc = -1;
			}

			int sh = height[f]; //ShortHeight
			while(sh > 0){
				
				sh -= sh & -sh;
			}
		} else if(type == 'q'){
			bool blocked = false;
			int lca = get_lca(f, s);
			//get sum between f and lca(f, s)
			//get sum between s and lca(f, s)

			if(!blocked){
				std::cout << height[f] + height[s] - 2 * height[lca] << '\n';
			} else {
				std::cout << "Impossible\n";
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	landslide(n);

	return 0;
}
