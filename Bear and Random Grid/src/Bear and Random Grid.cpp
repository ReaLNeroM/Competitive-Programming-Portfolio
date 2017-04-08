#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e3 + 1e2;
int mat[maxn][maxn];
int loc[maxn][maxn];
char action[256];
int ay[] = {1, -1, 0, 0};
int ax[] = {0, 0, 1, -1};

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	action['U'] = 1;
	action['D'] = 0;
	action['R'] = 2;
	action['L'] = 3;
	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		int l, n;
		cin >> l >> n;

		string s;
		cin >> s;

		int py = 0, px = 0;

		vector<pair<int, int> > pl;
		vector<int> actual_step;
		pl.push_back({py, px});
		actual_step.push_back(0);

		set<pair<int, int> > set_s;
		set_s.insert(pl[0]);

		for(int i = 0; i < l; i++){
			py += ay[action[s[i]]];
			px += ax[action[s[i]]];
			if(set_s.find({py, px}) == set_s.end()){
				pl.push_back({py, px});
				actual_step.push_back(i);
				set_s.insert({py, px});
			}
		}

		for(int i = 0; i < maxn; i++){
			for(int j = 0; j < maxn; j++){
				mat[i][j] = 0;
			}
		}

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				char c;
				cin >> c;

				if(c == '#'){
					mat[i][j] = 0;
				} else {
					mat[i][j] = 1;
				}
				loc[i][j] = (1 << 29);
			}
		}

		int white = 0, black = 4 * n;

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(!mat[i][j]){
					black++;
				} else {
					white++;
				}
			}
		}

		int sum = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(mat[i][j]){
					loc[i][j] = l;
					for(int k = 0; k < pl.size(); k++){
						if(!mat[i + pl[k].first][j + pl[k].second]){
							loc[i][j] = actual_step[k];
							break;
						}
					}
				}
			}
		}

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(mat[i][j]){
					sum ^= loc[i][j];
				}
			}
		}

		cout << sum << endl;
	}
}

