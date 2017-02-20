#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5 + 1e2;
const int alpha = 26;
int board[maxn][alpha];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;

	for(int i = 0; i < alpha; i++){
		board[a.size()][i] = a.size();
	}

	for(int i = a.size() - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			if(a[i] - 'a' == j){
				board[i][j] = i;
			} else {
				board[i][j] = board[i + 1][j];
			}
		}
	}

	int pos = 0;
	int taken = 1;
	for(int i = 0; i < b.size(); i++){
		if(board[pos][b[i] - 'a'] == a.size()){
			taken++;
			pos = 0;
			if(board[0][b[i] - 'a'] == a.size()){
				cout << -1 << endl;
				return 0;
			}
			i--;
		} else {
			pos = board[pos][b[i] - 'a'] + 1;
		}
	}

	cout << taken << endl;
}

