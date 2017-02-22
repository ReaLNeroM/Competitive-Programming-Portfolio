#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxv = 1024;
int app[2][maxv];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, steps, x;
	cin >> n >> steps >> x;

	for(int i = 0; i < n; i++){
		int vv;
		cin >> vv;
		app[0][vv]++;
	}

	for(int i = 0; i < steps; i++){
		int val_pos = 0;
		for(int j = 0; j < maxv; j++){
			int to_oper = app[0][j];
			if(val_pos % 2 == 0){
				to_oper = to_oper / 2 + to_oper % 2;
			} else {
				to_oper /= 2;
			}
			app[1][j ^ x] += to_oper;
			app[1][j] += app[0][j] - to_oper;
			val_pos += app[0][j];
		}
		for(int j = 0; j < maxv; j++){
			app[0][j] = app[1][j];
			app[1][j] = 0;
		}
	}

	for(int i = maxv - 1; i >= 0; i--){
		if(app[0][i]){
			cout << i << ' ';
			break;
		}
	}

	for(int i = 0; i < maxv; i++){
		if(app[0][i]){
			cout << i;
			break;
		}
	}
}

