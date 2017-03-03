#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5;
int pos[maxn];
int a[maxn];
int b[maxn];

int main(){
	ios::sync_with_stdio(false);

	ll n, l, r;
	cin >> n >> l >> r;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		int ind;
		cin >> ind;
		ind--;
		pos[ind] = i;
	}

	bool possible = true;

	int lower = -2e9;

	for(int i = 0; i < n; i++){
		int lowest = l - a[pos[i]];
		int highest = r - a[pos[i]];

		if(lower < highest){
			lower = max(lower + 1, lowest);
			b[pos[i]] = lower + a[pos[i]];
		} else {
			possible = false;
		}
	}

	if(!possible){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++){
		cout << b[i] << ' ';
	}
}
