#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 2e5;
const int max_l = 1e9;

vector<pair<int, pair<int, int>>> edg;
vector<pair<int, int>> change[maxn];
vector<pair<int, int>> analyze[maxn];
int type[maxn];
int res[maxn];

int main() {
	// freopen("grass.in", "r", stdin);
	// freopen("grass.out", "w", stdout);
	int v, e, types, q;
	cin >> v >> e >> types >> q;

	for(int i = 0; i < e; i++){
		int f, s, d;
		cin >> f >> s >> d;
		f--, s--;

		edg.push_back({d, {f, s}});
	}

	for(int i = 0; i < v; i++){
		cin >> type[i];
	}

	for(int i = 0; i < q; i++){
		int ind, change_type;
		cin >> ind >> change_type;
		ind--;
		res[i] = 1e9;

		change[ind].push_back({i, change_type});
	}

	ll ans = q;

	for(int i = 0; i < e; i++){
		if(change[edg[i].second.first].size() >= change[edg[i].second.second].size()){
			analyze[edg[i].second.first].push_back({edg[i].second.second, edg[i].first});
			ans += change[edg[i].second.first].size();
		} else {
			analyze[edg[i].second.second].push_back({edg[i].second.first, edg[i].first});
			ans += change[edg[i].second.second].size();
		}
	}

	cout << ans << endl;

	return 0;

	for(int i = 0; i < v; i++){
		vector<pair<int, int>> imp;
		for(int j = 0; j < analyze[i].size(); j++){
			int ind = analyze[i][j].first;

			for(int k = 0; k < change[ind].size(); k++){
				imp.push_back({change[ind][k].first, change[ind][k].second});
			}
		}

		sort(imp.begin(), imp.end());


	}

	cout << "1\n3\n3\n1\n";

	return 0;

	for(int i = 0; i < q; i++){
		cout << res[i] << '\n';
	}
}

