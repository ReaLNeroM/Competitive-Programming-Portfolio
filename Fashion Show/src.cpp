#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 305;
int rook[maxn][maxn];
int bishop[maxn][maxn]; //0 - empty, 1 - given, 2 - player-placed
int usedv[maxn], usedh[maxn];
int useddd[maxn], usedda[maxn];

int main(){
	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		int n, models;
		cin >> n >> models;

		for(int i = 0; i < maxn; i++){
			for(int j = 0; j < maxn; j++){
				rook[i][j] = 0;
				bishop[i][j] = 0;
			}
			usedv[i] = 0;
			usedh[i] = 0;
			useddd[i] = 0;
			usedda[i] = 0;
		}

		for(int i = 0; i < models; i++){
			char c;
			int py, px;
			cin >> c;
			cin >> py >> px;
			py--, px--;

			if(c == '+' or c == 'o'){
				bishop[py][px] = 1;
				useddd[py + px] = true;
				usedda[py - px + n] = true;
			}
			if(c == 'x' or c == 'o'){
				rook[py][px] = 1;
				usedv[px] = true;
				usedh[py] = true;
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!usedv[j] and !usedh[i]){
					usedv[j] = true, usedh[i] = true;

					rook[i][j] = 2;
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					if((n - 1) - j + k == i or j + (n - 1) - k == i or j + k == i or (n - 1) - j + (n - 1) - k == i){
						if(!useddd[j + k] and !usedda[j - k + n]){
							useddd[j + k] = true;
							usedda[j - k + n] = true;

							bishop[j][k] = 2;
						}
					}
				}
			}
		}

		int style = 0;
		int added = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(bishop[i][j]){
					style++;
				}
				if(rook[i][j]){
					style++;
				}
				if(bishop[i][j] == 2 or rook[i][j] == 2){
					added++;
				}
			}
		}

		cout << "Case #" << x + 1 << ": " << style << ' ' << added << '\n';
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((rook[i][j] == 2 or bishop[i][j] == 2) and (rook[i][j] and bishop[i][j])){
					cout << "o " << i + 1 << ' ' << j + 1 << '\n';
				} else if(rook[i][j] == 2){
					cout << "x " << i + 1 << ' ' << j + 1 << '\n';
				} else if(bishop[i][j] == 2){
					cout << "+ " << i + 1 << ' ' << j + 1 << '\n';
				}
			}
		}
	}
}
