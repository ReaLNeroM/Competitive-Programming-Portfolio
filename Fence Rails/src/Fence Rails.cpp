/*
ID: vlade.m1
PROG: fence8
LANG: C++
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int n;
int val[maxn];
vector<int> rails;

bool good(int pos){
	vector<int> left;
	for(int i = 0; i < pos; i++){
		left.push_back(rails[i]);
	}

	for(int i = 0; i < n; i++){
		int board[val[i] + 1];
		int par[val[i] + 1];
		for(int j = 0; j <= val[i]; j++){
			board[j] = false;
			par[j] = -1;
		}
		board[0] = true;
		int biggest = 0;
		for(int j = left.size() - 1; j >= 0; j--){
			for(int k = val[i]; k - left[j] >= 0; k--){
				if(!board[k] and board[k - left[j]]){
					board[k] = true;
					par[k] = j;
					biggest = max(biggest, k);
				}
			}
		}
		int pos = biggest;
		vector<int> to_remove;
		while(pos != 0){
			int last = par[pos];
			pos = pos - left[par[pos]];
			to_remove.push_back(last);
		}
		for(int j = to_remove.size() - 1; j >= 0; j--){
			left.erase(left.begin() + to_remove[j]);
		}
	}

	if(left.empty()){
		return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("fence8.in", "r", stdin);
    freopen("fence8.out", "w", stdout);

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	sort(val, val + n);

	int rail;
	cin >> rail;

	rails.resize(rail);
	for(int i = 0; i < rail; i++){
		cin >> rails[i];
	}
	sort(rails.begin(), rails.end());

	int best = 0;
	int l = 1, r = rails.size();
	while(l <= r){
		int mid = (l + r) / 2;

		if(good(mid)){
			best = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << best << endl;
}

