#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 500005;
const ll over_max = 1e16;
pair<ll, ll> res;
ll y, x;
ll blocks;
ll points;
ll price[maxn], size[maxn];
ll board[maxn];
ll dp[maxn];
pair<ll, ll> p[maxn];

void calc_dp(){
	dp[0] = 0;
	for(ll i = 1; i < maxn; i++){
		dp[i] = 1e18;
		for(ll j = 0; j < blocks; j++){
			if(i - size[j] >= 0){
				dp[i] = min(dp[i], dp[i - size[j]] + price[j]);
			}
		}
	}
}

ll dp_for_value(ll val){
	ll best = 1e18;
	if(val < maxn){
		return dp[val];
	}
	for(ll i = 0; i < blocks; i++){
		ll nesto = (val - maxn + size[i]) / size[i];
		best = min(best, nesto * price[i] + dp[val - nesto * size[i]]);
		//val - size[i] * nesto < maxn
		//-size[i] * nesto < maxn - val
		//-nesto < (maxn - val) / size[i]
		// nesto > (val - maxn) / size[i]
	}

	return best;
}

pair<ll, ll> calc(){
	pair<ll, ll> sum;
	sum.first = sum.second = 0;

	map<ll, ll> need;

	for(ll i = 0; i < points; i++){
		if(p[i].second != p[i - 1].second){
			need[p[i].first] += p[i].second - p[i - 1].second;
		}
	}

	for(ll i = 1; i < points - 1; i++){
		p[i].first = -p[i].first + y;
	}

	vector<pair<ll, ll>> v;
	for(ll i = 0; i < points; i++){
		if(v.empty() or v[v.size() - 1].first < p[i].first){
			v.push_back({p[i].first, p[i].second});
		} else {
			while(!v.empty() and v[v.size() - 1].first > p[i].first){
				if(v[v.size() - 2].first < p[i].first){
					need[p[i].second - v[v.size() - 1].second] += v[v.size() - 1].first - p[i].first;
					v[v.size() - 1].first = p[i].first;
				} else {
					need[p[i].second - v[v.size() - 1].second] += v[v.size() - 1].first - v[v.size() - 2].first;
					v.pop_back();
				}
			}
		}

	}

	for(auto ite = need.begin(); ite != need.end(); ++ite){
//		sum += dp_for_value(ite->first) * ite->second;

		pair<ll, ll> over;
		over.first = 0;
		over.second = dp_for_value(ite->first);
		ll sec = ite->second;
		while(sec){
			if(sec % 2 == 1){
				sum.first += over.first;
				sum.second += over.second;
				if(sum.second >= over_max){
					sum.second -= over_max;
					sum.first++;
				}
			}
			sec /= 2;
			over.first *= 2;
			over.second *= 2;
			while(over.second >= over_max){
				over.second -= over_max;
				over.first++;
			}
		}
	}

	return sum;
}

void calc_with_flip(){
	res = min(res, calc());

	res = min(res, calc());
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> x >> y;

	cin >> blocks;
	
	for(ll i = 0; i < blocks; i++){
		cin >> size[i] >> price[i];
	}
	calc_dp();
	
	cin >> points;

	for(ll i = 1; i <= points; i++){
		cin >> p[i].second >> p[i].first;
	}
	
	p[0] = {0, 0};
	p[points + 1] = {0, x};
	points += 2;

	res.first = 1e16;
	res.second = 0;

	calc_with_flip();

	string a = "";
	while(res.first > 0){
		a.insert(a.begin(), res.first % 10 + '0');
		res.first /= 10;
	}
	string b = "";
	for(int i = 0; i < 16; i++){
		if(a.empty() and res.second == 0){
			break;
		}
		b.insert(b.begin(), res.second % 10 + '0');
		res.second /= 10;
	}
	cout << a << b;
}
