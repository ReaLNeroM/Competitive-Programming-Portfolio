#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 5e5 + 5;
static ll seg[2][4 * maxn];
vector<pair<ll, ll>> fair[maxn];
static ll used[maxn];
static ll freel[maxn];
static ll must[maxn];
static ll reall[maxn];
ll n, u, d, start;
const ll INF = 2000000000;

void spreadd(ll ind, ll l, ll r){
	if(l != r){
		ll mid = (l + r) / 2;

		seg[0][2 * ind + 1] = max(seg[0][2 * ind + 1], seg[0][ind] - (r - mid) * d);
		seg[0][2 * ind + 2] = max(seg[0][2 * ind + 2], seg[0][ind]);

		seg[0][ind] = -INF;
	}
}

void spreadu(ll ind, ll l, ll r){
	if(l != r){
		ll mid = (l + r) / 2 + 1;

		seg[1][2 * ind + 1] = max(seg[1][2 * ind + 1], seg[1][ind]);
		seg[1][2 * ind + 2] = max(seg[1][2 * ind + 2], seg[1][ind] - (mid - l) * u);

		seg[1][ind] = -INF;
	}
}

void do_low(ll pos, ll gotten, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(pos < cl){
		return;
	} else if(cr <= pos){
		spreadd(ind, cl, cr);
		seg[0][ind] = max(seg[0][ind], gotten - (pos - cr) * d);
		return;
	}

	ll mid = (cl + cr) / 2;

	do_low(pos, gotten, 2 * ind + 1, cl     , mid);
	do_low(pos, gotten, 2 * ind + 2, mid + 1, cr );
}

void do_up(ll pos, ll gotten, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(pos <= cl){
		spreadu(ind, cl, cr);
		seg[1][ind] = max(seg[1][ind], gotten - (cl - pos) * u);
		return;
	} else if(cr < pos){
		return;
	}

	ll mid = (cl + cr) / 2;

	do_up(pos, gotten, 2 * ind + 1, cl     , mid);
	do_up(pos, gotten, 2 * ind + 2, mid + 1, cr );
}

void upd(ll pos, ll gotten){
	do_low(pos, gotten);
	do_up(pos, gotten);
}

ll query(ll pos, ll ind = 0, ll l = 0, ll r = maxn - 1){
	if(l == r){
		return max(seg[0][ind], seg[1][ind]);
	}
	spreadd(ind, l, r);
	spreadu(ind, l, r);

	ll mid = (l + r) / 2;

	if(pos <= mid){
		return query(pos, 2 * ind + 1, l      , mid);
	} else {
		return query(pos, 2 * ind + 2, mid + 1, r  );
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> u >> d >> start;
	start--;

	for(ll i = 0; i < n; i++){
		ll day;
		cin >> day;
		pair<ll, ll> curr_fair;
		cin >> curr_fair.first >> curr_fair.second;
		curr_fair.first--;
		fair[day].push_back(curr_fair);
	}

	for(ll i = 0; i < 4 * maxn; i++){
		seg[0][i] = seg[1][i] = -INF;
	}

	upd(start, 0);
	for(ll i = 1; i < maxn; i++){
		if(!fair[i].empty()){
			sort(fair[i].begin(), fair[i].end());
			for(ll j = 0; j < fair[i].size(); j++){
				used[j] = query(fair[i][j].first);
			}

			ll size = fair[i].size();

			must[0] = used[0] + fair[i][0].second;
			freel[0] = fair[i][0].second;
			for(ll j = 1; j < fair[i].size(); j++){
				ll cost = (fair[i][j].first - fair[i][j - 1].first);
				freel[j] = max(0LL, freel[j - 1] - (u + d) * cost) + fair[i][j].second;
				must[j] = max(must[j - 1] - u * cost + fair[i][j].second, freel[j] + used[j]);
			}

			ll up_must = used[size - 1] + fair[i][size - 1].second;
			ll up_freel = fair[i][size - 1].second;

			reall[size - 1] = must[size - 1];
			for(ll j = size - 2; j >= 0; j--){
				ll cost = (fair[i][j + 1].first - fair[i][j].first);

				up_freel = max(0LL, up_freel - cost * (u + d)) + fair[i][j].second;
				up_must = max(up_must - cost * d + fair[i][j].second, used[j] + up_freel);

				reall[j] = max(must[j] + up_freel, up_must + freel[j]) - fair[i][j].second;
			}

			for(ll j = 0; j < fair[i].size(); j++){
				upd(fair[i][j].first, reall[j]);
			}
		}
	}

	cout << query(start);
}
