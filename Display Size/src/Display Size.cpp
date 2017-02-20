#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int best = 1;
	int r = n;

	for(int i = 1; i * i <= n; i++){
		while(i * r > n){
			r--;
		}

		if(i * r == n){
			best = i;
		}
	}

	cout << best << ' ' << n / best;
}
