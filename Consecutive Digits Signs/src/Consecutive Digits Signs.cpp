#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5;
int could[maxn][10];
int nnext[maxn][10];
int val[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++){
		cin >> val[i];
	}
	for(int j = 0; j < 10; j++){
		could[n - 1][j] = true;
	}

	for(int i = n - 2; i >= 0; i--){
		for(int j = 0; j < 10; j++){
			if(val[i] == -1){
				for(int k = j + 1; k < 10; k++){
					if(could[i + 1][k]){
						could[i][j] = could[i + 1][k];
						nnext[i][j] = k;
					}
				}
			} else if(val[i] == 0){
				could[i][j] = could[i + 1][j];
				nnext[i][j] = j;
			} else if(val[i] == 1){
				for(int k = 0; k < j; k++){
					if(could[i + 1][k]){
						could[i][j] = could[i + 1][k];
						nnext[i][j] = k;
					}
				}
			}
		}
	}
	could[0][0] = false;

	for(int j = 9; j >= 0; j--){
		if(could[0][j]){
			int pos = j;

			for(int i = 0; i < n; i++){
				cout << pos;
				pos = nnext[i][pos];
			}

			cout << endl;

			return 0;
		}
	}

	cout << -1 << endl;
	return 0;

}

