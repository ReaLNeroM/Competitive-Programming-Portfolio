#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 55;
int mat[maxn][maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int y, x;
	cin >> y >> x;
	
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			cin >> mat[i][j];
		}
	}
	
	int res = 0;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			int mindist = 500;
			for(int k = 0; k < y; k++){
				for(int l = 0; l < x; l++){
					if(mat[k][l] == 1){
						mindist = min(mindist, max(abs(i - k), abs(j - l)));
					}
				}
			}
			res = max(res, mindist);
		}
	}
	
	cout << res;
}
