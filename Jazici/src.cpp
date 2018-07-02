#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
std::vector<int> v[maxn];
std::vector<int> poznavaci[maxn];
bool used[maxn];
bool usedlanguage[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	for(int i = 0; i < n; i++){
		int languages;
		std::cin >> languages;

		v[i].resize(languages);

		for(int j = 0; j < languages; j++){
			std::cin >> v[i][j];
			poznavaci[v[i][j]].push_back(i);
		}
	}

	std::queue<int> q;
	q.push(0);
	used[0] = true;

	int left = n;
	int last = 0;
	while(!q.empty()){
		int fr = q.front();
		left--;
		last = fr;
		q.pop();

		for(int i = 0; i < v[fr].size(); i++){
			if(!usedlanguage[v[fr][i]]){
				usedlanguage[v[fr][i]] = true;
				for(int j = 0; j < poznavaci[v[fr][i]].size(); j++){
					int curr = poznavaci[v[fr][i]][j];

					if(!used[curr]){
						used[curr] = true;
						q.push(curr);
					}
				}
			}
		}
	}

	if(left == 0){
		std::cout << "YES\n";
		return 0;
	}
	std::cout << "NO\n";
	return 0;
}
