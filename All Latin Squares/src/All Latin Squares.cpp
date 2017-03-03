/*
ID: vlade.m1
PROG: latin
LANG: C++
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 7;
int n;
int usedy[maxn][maxn];
int usedx[maxn][maxn];
int left[maxn][maxn];
int found = 0;

void dfs(int y, int x){
	if(y == n){
		found++;
		return;
	} else if(y == 1 and x <= n - 1){
		int diff = -1;
		for(int i = 0; i < n; i++){
			if(!usedy[i][y] and !usedx[i][x]){
				usedy[i][y] = true, usedx[i][x] = true;
				if(diff == -1 or diff == -2){
					int last = found;
					if(x + 1 == n){
						dfs(y + 1, 1);
					} else {
						dfs(y, x + 1);
					}
					if(diff == -2){
						diff = found - last;
					} else {
						diff = -2;
					}
				} else if(diff >= 0){
					found += diff;
				}
				usedy[i][y] = false, usedx[i][x] = false;
			}
		}
	} else {
		for(int i = 0; i < n - (y == n - 1); i++){
			if(!usedy[i][y] and !usedx[i][x]){
				usedy[i][y] = true, usedx[i][x] = true;
				int last = found;
				if(x + 1 == n){
					dfs(y + 1, 1);
				} else {
					dfs(y, x + 1);
				}
				usedy[i][y] = false, usedx[i][x] = false;
			}
		}
	}
}

int main(){
//	freopen("latin.in", "r", stdin);
//	freopen("latin.out", "w", stdout);
	cin >> n;

	for(int i = 0; i < n; i++){
		usedx[i][i] = true;
		usedy[i][0] = true;
		usedx[i][0] = true;
		usedy[i][i] = true;
	}

	dfs(1, 1);

	ll foundll = found;
	for(int i = 1; i <= n - 1; i++){
		foundll *= i;
	}

	cout << foundll << endl;
}
