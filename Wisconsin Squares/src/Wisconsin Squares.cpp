/*
ID: vlade.m1
PROG: wissqu
LANG: C++
*/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 4;
char mat[maxn][maxn];
int found = 0;
const int ay[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int ax[] = {-1,  0,  1, -1, 1, -1, 0, 1};
int app[5];
int allowed[] = {3, 3, 3, 4, 3};
string res = "";

void best_check(char board[4][4], int left[4][4]){
	string made = "";

	for(int i = 1; i <= 16; i++){
		for(int j = 0; j < maxn; j++){
			for(int k = 0; k < maxn; k++){
				if(left[j][k] == i){
					made += board[j][k];
					made += ' ';
					made += (char) (j + 1 + '0');
					made += ' ';
					made += (char) (k + 1 + '0');
					made += '\n';
				}
			}
		}
	}

	if(res == "" or res > made){
		res = made;
	}
}
void check(char board[4][4], int left[4][4], int filled = 0){
	if(filled == maxn * maxn){
		best_check(board, left);
		found++;
		return;
	}
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			if(!left[i][j]){
				bool good = true;
				for(int k = 0; k < 8; k++){
					int ny = i + ay[k];
					int nx = j + ax[k];

					if(0 <= ny and ny < maxn and 0 <= nx and nx < maxn){
						if(left[ny][nx] and board[ny][nx] == board[i][j]){
							good = false;
						} else if(!left[ny][nx] and mat[ny][nx] == board[i][j]){
							good = false;
						}
					}
				}
				if(good){
					left[i][j] = filled + 1;
					check(board, left, filled + 1);
					left[i][j] = 0;
				}
			}
		}
	}
}

void dfs(char board[4][4], int y, int x){
	if(x == maxn){
		y++;
		x = 0;
	}
	if(y == maxn){
		int left[4][4];
		for(int i = 0; i < maxn; i++){
			for(int j = 0; j < maxn; j++){
				left[i][j] = 0;
			}
		}
		check(board, left, 0);
		return;
	}
	for(int i = 0; i <= 4; i++){
		board[y][x] = 'A' + i;

		if(board[y][x] != mat[y][x]){
			bool good = true;
			for(int j = 0; j < 8; j++){
				int ny = y + ay[j];
				int nx = x + ax[j];

				if(0 <= ny and ny < maxn and 0 <= nx and nx < maxn){
					if(ny < y){
						if(board[y][x] == board[ny][nx]){
							good = false;
						}
					} else if(ny == y and nx < x){
						if(board[y][x] == board[ny][nx]){
							good = false;
						}
					}
				}
			}
			if(good){
				app[i]++;
				if(app[i] <= allowed[i]){
					dfs(board, y, x + 1);
				}
				app[i]--;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("wissqu.in", "r", stdin);
    freopen("wissqu.out", "w", stdout);

    for(int i = 0; i < 4; i++){
    	for(int j = 0; j < 4; j++){
    		cin >> mat[i][j];
    	}
    }
    char board[4][4];

    dfs(board, 0, 0);

    cout << res;

    cout << found << endl;
}

