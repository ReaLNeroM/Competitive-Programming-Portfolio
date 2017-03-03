#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 55;
string mat[maxn];
int res = 1e9;

int findx(int pos, char c){
	int dist = 1e8;
	if(c == '0'){
		for(int i = 0; i < mat[pos].size(); i++){
			if('0' <= mat[pos][i] and mat[pos][i] <= '9'){
				dist = min(dist, i);
				dist = min(dist, (int) mat[pos].size() - i);
			}
		}
	} else if(c == 'a'){
		for(int i = 0; i < mat[pos].size(); i++){
			if('a' <= mat[pos][i] and mat[pos][i] <= 'z'){
				dist = min(dist, i);
				dist = min(dist, (int) mat[pos].size() - i);
			}
		}
	} else {
		for(int i = 0; i < mat[pos].size(); i++){
			if(mat[pos][i] == '#' or mat[pos][i] == '*' or mat[pos][i] == '&'){
				dist = min(dist, i);
				dist = min(dist, (int) mat[pos].size() - i);
			}
		}
	}

	return dist;
}

int main(){
	ios::sync_with_stdio(false);

	int y, x;
	cin >> y >> x;

	for(int i = 0; i < y; i++){
		cin >> mat[i];
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < y; j++){
			for(int k = 0; k < y; k++){
				if(i != j and j != k and i != k){
					res = min(res, findx(i, '0') +
									findx(j, 'a') +
									findx(k, '#'));
				}
			}
		}
	}

	cout << res;
}
