#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 50005;
vector<pair<int, int>> adj[max];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n - 1; i++){
		int f, s, d;
		cin >> f >> s >> d;

		adj[f].push_back({s, d});
		adj[s].push_back({f, d});
	}
	
}
