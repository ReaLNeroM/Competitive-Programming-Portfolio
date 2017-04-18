#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, r, b;
	cin >> n >> r >> b;

	vector<ll> vr;
	for(ll i = 0; i < r; i++){
		ll ind;
		cin >> ind;
		vr.push_back(ind - 1);
	}

	map<ll, ll> s, m;

	for(ll i = 0; i < b; i++){
		ll ind;
		cin >> ind;
		m[ind - 1] = 2;
		s[-(ind - 1)] = 2;
	}

	ll sum = 0;
	
	for(ll i = 0; i < vr.size(); i++){
		ll mindist = n;
		if(m.lower_bound(vr[i]) != m.end()){
			mindist = min(mindist, abs(vr[i] - m.lower_bound(vr[i])->first));
		}
		if(s.lower_bound(-vr[i]) != s.end()){
			mindist = min(mindist, abs(vr[i] + s.lower_bound(-vr[i])->first));
		}

		sum += mindist;
	}
	
	cout << sum;
	
}
