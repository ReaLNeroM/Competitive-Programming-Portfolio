#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e3;
int val[2][maxn][3];

vector<int> ident[2][maxn * 3];

int curr_step;

map<string, int> m;
int curr_num = 1;

int assign(string v){
	if(m[v] == 0){
		m[v] = curr_num;
		curr_num++;
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int v[2];
	cin >> v[0] >> v[1];

	for(int x = 0; x < 2; x++){
		m.clear();

		for(int i = 0; i < v[x]; i++){
			string a, b, c;
			cin >> a >> b >> b >> c >> c;

			val[x][i][0] = assign(a);
			val[x][i][1] = assign(b);
			val[x][i][2] = assign(c);
		}
	}

	int best_res = 0;

	for(int i = 0; i < v[0]; i++){
		int r = -1;
		for(int j = 0; j < v[1]; j++){
			r = max(r, -1);

			bool good = true;
			while(good){
				if(ident[val[0][i + r + 1][0]] and ident[val[0][i + r + 1][0]] != val[1][j + r + 1][0]){
					good = false;
				}
				if(ident[val[1][j + 1 + 1][0]] and ident[val[1][j + r + 1][0]] != val[0][i + r + 1][0]){
					good = false;
				}

				if(val[0][i + r + 1][1] == val[0][i + r + 1][2]){
					if(val[1][j + r + 1][1] != val[1][j + r + 1][2]){
						good = false;
					}
					if(ident[val[0][i + r + 1][1]] and ident[val[0][i + r + 1][1]] != val[1][j + r + 1][1]){
						good = false;
					}
					if(ident[val[1][j + r + 1][1]] and ident[val[1][j + r + 1][1]] != val[0][i + r + 1][1]){
						good = false;
					}
				} else {
					if(val[1][j + r + 1][1] == val[1][j + r + 1][2]){
						good = false;
					}
					for(int x = 0; x < 2; x++){
						if(ident[val[x][]])
						for(int y = 0; x < 2; x++){

						}
					}
				}

				if(good){
					ident[val[0][i + r + 1][0]] = val[1][j + r + 1][0];
					ident[val[1][j + r + 1][0]] = val[0][i + r + 1][0];

					if(val[0][i + r + 1][1] == val[0][i + r + 1][2]){
						ident[val[0][i + r + 1][1]] = val[1][j + r + 1][1];
					} else {
						//possibilities
					}
					r++;
				}
			}

			best_res = max(best_res, r);
			//disable j
			r--;
		}
	}

	cout << best_res;
}

