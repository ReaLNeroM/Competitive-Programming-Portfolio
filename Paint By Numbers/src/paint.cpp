#include <bits/stdc++.h>
typedef long long ll;

const int maxn = 200005;
const int maxk = 105;
int dp[maxn][maxk];
int pref[maxn];
int sw[maxn];
bool white[maxn];
std::vector<int> extent;
std::string global;
int n, k;

int query(int l, int r){
	return (pref[r] - pref[l - 1] == 0);
}

std::string solve_puzzle(std::string s, std::vector<int> c) {
	n = s.size();
	k = c.size();
	c.insert(c.begin(), 0);
	global = "0" + s;
	extent = c;

	pref[0] = 0;
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + (s[i - 1] == '_');
	}

	for(int i = 0; i <= n + 1; i++){
		for(int j = 0; j <= k + 1; j++){
			dp[i][j] = -1;
		}
	}

	std::string res = "";

	for(int p = 0; p <= n; p++){
		for(int b = 0; b <= k; b++){
			dp[p][b] = 0;
			if(p == 0){
				dp[p][b] = (b == 0);
			} else {
				if(global[p] == 'X' or global[p] == '.'){
					if(b != 0 and query(p - extent[b] + 1, p)){
						if(p - extent[b] == 0){
							dp[p][b] |= dp[p - extent[b]][ b - 1];
						} else if (p - extent[b] > 0 and global[p - extent[b]] != 'X'){
							dp[p][b] |= dp[p - extent[b] - 1][ b - 1];
						}
					}
				}
				if(global[p] == '_' or global[p] == '.'){
					dp[p][b] |= dp[p - 1][ b];
				}
			}
		}
	}

	std::queue<int> qp, qb;
	qp.push(n), qb.push(k);
	while(!qp.empty()){
		int p = qp.front(), b = qb.front();
		qp.pop(), qb.pop();

		if(p == 0){
		} else {
			if(global[p] == 'X' or global[p] == '.'){
				if(b != 0 and query(p - extent[b] + 1, p)){
					if(p - extent[b] == 0){
						if(dp[p - extent[b]][b - 1]){
							if(dp[p - extent[b]][b - 1] != 2){
								dp[p - extent[b]][b - 1] = 2;
								qp.push(p - extent[b]), qb.push(b - 1);
							}
							sw[p - extent[b] + 1]++;
							sw[p + 1]--;
						}
					} else if (p - extent[b] > 0 and global[p - extent[b]] != 'X'){
						if(dp[p - extent[b] - 1][b - 1]){
							if(dp[p - extent[b] - 1][b - 1] != 2){
								qp.push(p - extent[b] - 1), qb.push(b - 1);
								dp[p - extent[b] - 1][b - 1] = 2;
							}
							white[p - extent[b]] = true;
							sw[p - extent[b] + 1]++;
							sw[p + 1]--;
						}
					}
				}
			}
			if(global[p] == '_' or global[p] == '.'){
				if(dp[p - 1][b]){
					if(dp[p - 1][b] != 2){
						qp.push(p - 1), qb.push(b);
						dp[p - 1][b] = 2;
					}
					white[p] = true;
				}
			}
		}
	}

	int sweep = 0;
	for(int i = 1; i <= n; i++){
		sweep += sw[i];

		if(sweep and white[i]){
			res += '?';
		} else if(sweep){
			res += 'X';
		} else if(white[i]){
			res += '_';
		}
	}

    return res;
}
