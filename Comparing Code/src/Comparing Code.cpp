#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e3;
int val[2][maxn][3];

int ident_step[maxn][3];
int ident[maxn][3];

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

	int curr_step = 1;
	for(int i = 0; i < v[0]; i++){
		for(int j = 0; j < v[1]; j++){
			if(v[0] - i < best_res or v[1] - j < best_res){
				continue;
			}

			// swapping storeb and storec adds a layer of complexity
		}
	}

	cout << best_res;
}

