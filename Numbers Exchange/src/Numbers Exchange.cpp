#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;
int val[maxn];
int app[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int> > v[2];
	vector<int> empty[2];

	for(int i = 0; i < n; i++){
		cin >> val[i];
		if(val[i] < maxn){
			app[val[i]]++;
		}
		v[val[i] % 2].push_back({val[i], i});
	}
	for(int i = 1; i < maxn and i <= k; i++){
		if(app[i] == 0){
			empty[i % 2].push_back(i);
		}
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	int changes = 0;
	int f[] = {v[0].size(), v[1].size()};

	for(int i = 0; i < 2; i++){
		for(int j = 0; j + 1 < v[i].size(); j++){
			if(v[i][j].first == v[i][j + 1].first){
				if(f[i] < f[!i] or (f[i] == f[!i] and !empty[i].empty())){
					if(empty[i].empty()){
						cout << -1 << endl;
						return 0;
					}
					changes++;
					v[i][j].first = empty[i][empty[i].size() - 1];
					empty[i].pop_back();
				} else if(f[i] > f[!i] or f[i] == f[!i]){
					if(empty[!i].empty()){
						cout << -1 << endl;
						return 0;
					}
					f[i]--, f[!i]++;
					changes++;
					v[i][j].first = empty[!i][empty[!i].size() - 1];
					empty[!i].pop_back();
				}
			}
		}
	}

	for(int i = 0; i < 2; i++){
		if(f[i] > f[!i]){
			if(f[i] - f[!i] > empty[!i].size()){
				cout << -1 << endl;
				return 0;
			}

			for(int j = 0; j < v[i].size() and f[i] > f[!i]; j++){
				if(v[i][j].first % 2 != i){
					continue;
				}
				f[i]--, f[!i]++;
				changes++;
				v[i][j].first = empty[!i][empty[!i].size() - 1];
				empty[!i].pop_back();
			}
		}
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < v[i].size(); j++){
			val[v[i][j].second] = v[i][j].first;
		}
	}

	cout << changes << endl;
	for(int i = 0; i < n; i++){
		cout << val[i] << ' ';
	}
}
