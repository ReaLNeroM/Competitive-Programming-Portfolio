#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
//	freopen("mincross.in", "r", stdin);
//	freopen("mincross.out", "w", stdout);

	ll n;
	cin >> n;

	ll improve[n];
	for(ll i = 0; i < n; i++){
		improve[i] = n;
	}

	ll pos[n];
	ll orig[n];
	for(ll i = 0; i < n; i++){
		cin >> orig[i];
		orig[i]--;
		pos[orig[i]] = i;
	}
	ll curr[n];
	for(ll i = 0; i < n; i++){
		cin >> curr[i];
		curr[i]--;
		if(i > pos[curr[i]]){
			improve[i - pos[curr[i]]]--;
		} else {
			improve[n + i - pos[curr[i]]]--;
		}
	}

	ll res = 1e9;
	ll res_ind = 0;
	for(int i = 0; i < n; i++){
		if(improve[i] < res){
			res = improve[i];
			res_ind = i;
		}
	}

	ll copy_over[n];
	for(int i = 0; i < n; i++){
		copy_over[i] = curr[i];
	}

	for(int i = 0; i < n; i++){
		curr[i] = copy_over[(i + res_ind) % n];
		cout << curr[i] << ' ';
	}
	cout << endl;
	cout << res;
	return 0;
}
