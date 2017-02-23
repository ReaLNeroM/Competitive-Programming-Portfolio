#include <iostream>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll n, maxlevel, vmax, vmin;
	ll left;
	cin >> n >> maxlevel >> vmax >> vmin >> left;

	pair<ll, ll> val[n + 1];
	for(ll i = 0; i < n; i++){
		cin >> val[i].first;
		val[i].second = i;
	}
	sort(val, val + n, greater<pair<ll, ll> >());

	map<ll, ll> m;
	int need[n];
	val[n] = val[n - 1];
	m[0] = n - 1;
	ll needed = 0;
	for(ll i = n - 1; i >= 0; i--){
		needed += (n - i) * (val[i].first - val[i + 1].first);
		need[i] = needed;
		m[needed] = i;
	}

	ll maxforce = 0, maxindex, maxsecondleft;
	for(ll i = 0; i <= n and left >= 0; i++){
		int pieces = 0, secondleft = 0, minend;
		if(need[i] <= left){
			minend = i;
			pieces = n - i;
			secondleft = left - need[i];
		} else {
			map<ll, ll>::iterator ite = m.upper_bound(left);
			ite--;
			minend = ite->second;
			pieces = n - ite->second;
			secondleft = left - ite->first;
		}

		if(vmax * i + vmin * min(maxlevel, (val[minend].first + secondleft / pieces)) > maxforce){
			maxforce = vmax * i + vmin * min(maxlevel, (val[minend].first + secondleft / pieces));
			maxindex = i;
			maxsecondleft = secondleft;
		}

		if(i != n){
			left -= maxlevel - val[i].first;
		}
	}

	ll copy[n];
	for(int i = 0; i < maxindex; i++){
		copy[val[i].second] = maxlevel;
	}
	for(int i = maxindex; i < n; i++){
		copy[val[i].second] = val[i].first;
	}

	ll bonuses = 0;
	if(maxindex != n){
		bonuses = maxsecondleft % (n - maxindex);
	}
	for(int i = n - 1; i >= maxindex; i--){
		if(n == maxindex){
			copy[val[i].second] = maxlevel;
		} else {
			copy[val[i].second] = min(maxlevel, (val[maxindex].first + maxsecondleft / (n - maxindex)));
		}
		if(bonuses > 0){
			copy[val[i].second]++;
			bonuses--;
		}
	}

	cout << maxforce << endl;
	for(int i = 0; i < n; i++){
		cout << copy[i] << ' ';
	}
	return 0;
}
