#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);

	char mat[4][4];

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cin >> mat[i][j];
		}
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(mat[i][j] == '.'){
				mat[i][j] = 'x';

				for(int k = 0; k + 2 < 4; k++){
					for(int l = 0; l + 2 < 4; l++){
						if(mat[k][l] == 'x' and mat[k][l + 1] == 'x' and mat[k][l + 2] == 'x'){
							cout << "YES" << endl;
							return 0;
						} else if(mat[k][l] == 'x' and mat[k + 1][l + 1] == 'x' and mat[k + 2][l + 2] == 'x'){
							cout << "YES" << endl;
							return 0;
						} else if(mat[k][l] == 'x' and mat[k + 1][l] == 'x' and mat[k + 2][l] == 'x'){
							cout << "YES" << endl;
							return 0;
						} else if(mat[k + 2][l] == 'x' and mat[k + 1][l + 1] == 'x' and mat[k][l + 2] == 'x'){
							cout << "YES" << endl;
							return 0;
						}
					}
				}
			}
		}
	}

	cout << "NO" << endl;
}
