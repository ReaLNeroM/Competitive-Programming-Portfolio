#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const double pi = 3.14159265358979323846264338;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	pair<ll, ll> volume[n];
	for(int i = 0; i < n; i++){
		ll rad, h;
		cin >> rad >> h;
		volume[i].first = rad * rad * h;
		volume[i].second = i;
	}

	sort(volume, volume + n);

	
	return 0;
}
