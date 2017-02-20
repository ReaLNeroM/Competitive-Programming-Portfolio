#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll y, x;
	cin >> y >> x;
	if(y > x){
		swap(y, x);
	}

	ll best = 1e18;

	for(ll oy = 1; oy * oy <= y * x; oy++){
		if((y * x) % oy == 0){
			ll ox = y * x / oy;
			best = min(best, abs(oy - ox));
		}
	}

	cout << best;

}

