#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 35;
vector<int> adj[maxn];
pair<int, int> pos[maxn];


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int f, s;
		cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	
	pos[0] = {0, 0};

	
}
