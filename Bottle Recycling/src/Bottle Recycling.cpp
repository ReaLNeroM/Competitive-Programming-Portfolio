#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, k;
	cin >> n >> k;

	ll drink = 0;
	while(n >= k){
		drink += n - (n % k);
		n = n / k + n % k;
	}

	cout << drink + n;

}

