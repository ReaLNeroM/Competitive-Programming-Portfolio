/*
ID: vlade.m1
PROG: clocks
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int board[9];
int ans_found = -1;

vector<int> ans;
string moves[] = {"ABDE", "ABC", "BCEF",
				"ADG", "BDEFH", "CFI",
				"DEGH", "GHI", "EFHI"};
int moves_done[9];
void dfs(int pos, int done){
	if(pos == 9){
		for(int j = 0; j < 9; j++){
			if(board[j] != 4){
				return;
			}
		}
		if(ans_found == -1 or ans.size() > done){
			ans_found = 1;
			ans.clear();
			for(int j = 0; j < 9; j++){
				for(int k = 0; k < moves_done[j]; k++){
					ans.push_back(j + 1);
				}
			}
		}
		return;
	}
	for(int i = 0; i < 4; i++){
		moves_done[pos] = i;
		dfs(pos + 1, done + i);

		for(int j = 0; j < moves[pos].size(); j++){
			board[moves[pos][j] - 'A']++;
			if(board[moves[pos][j] - 'A'] > 4){
				board[moves[pos][j] - 'A'] = 1;
			}
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < moves[pos].size(); j++){
			board[moves[pos][j] - 'A']--;
			if(board[moves[pos][j] - 'A'] == 0){
				board[moves[pos][j] - 'A'] = 4;
			}
		}
	}
}

int main(){
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> board[i * 3 + j];
			board[i * 3 + j] /= 3;
		}
	}

	dfs(0, 0);

	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i != ans.size() - 1){
			cout << ' ';
		} else {
			cout << '\n';
		}
	}
}
