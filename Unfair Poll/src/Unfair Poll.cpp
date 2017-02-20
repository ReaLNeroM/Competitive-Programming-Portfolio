#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e3;
ll board[maxn][maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll y, x;
	cin >> y >> x;

	ll questions;
	cin >> questions;

	ll y_pos, x_pos;
	cin >> y_pos >> x_pos;
	y_pos--, x_pos--;

	if(y == 1){
		for(ll j = 0; j < x; j++){
			board[0][j] += questions / x;
		}
		for(ll j = 0; j < questions % x; j++){
			board[0][j]++;
		}
	} else if(questions <= x){
		for(int j = 0; j < questions; j++){
			board[0][j]++;
		}
	} else {
		ll curr_row = 1;

		for(ll j = 0; j < x; j++){
			board[0][j]++;
		}
		questions -= x;

		ll order = 1;

		ll start_1 = 0, start_y = 0;
		if(questions > y * x){
			ll gotten = questions / ((y - 1) * x);
			start_1 = gotten / 2 + gotten % 2;
			start_y = gotten / 2;

			if(gotten % 2 == 0){
				curr_row = 1;
			} else {
				curr_row = y - 2;
				order = -1;
			}

			questions -= gotten * (y - 1) * x;
		}

		for(ll i = 1; i < y; i++){
			for(ll j = 0; j < x; j++){
				board[i][j] += start_1;
			}
		}

		for(ll i = 0; i < y - 1; i++){
			for(ll j = 0; j < x; j++){
				board[i][j] += start_y;
			}
		}

		ll curr_pos = 0;
		while(questions > 0){
			if(curr_pos == x){
				curr_pos = 0;

				curr_row += order;
				if(curr_row < 0){
					curr_row = 1;
					order = 1;
				} else if(curr_row >= y){
					curr_row = y - 2;
					order = -1;
				}
			} else {
				board[curr_row][curr_pos]++;
				curr_pos++;
				questions--;
			}
		}
	}

	ll minv = 1e18, maxv = 0, sergei = board[y_pos][x_pos];
	for(ll i = 0; i < y; i++){
		for(ll j = 0; j < x; j++){
			minv = min(minv, board[i][j]);
			maxv = max(maxv, board[i][j]);
		}
	}

	cout << maxv << ' ' << minv << ' ' << sergei;
}

