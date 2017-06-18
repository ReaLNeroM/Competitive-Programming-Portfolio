#include <bits/stdc++.h>

typedef long long ll;

const ll INF = 1e18 + 1e2;
const int maxn = 1e5 + 1e2;
std::map<ll, ll> s;
 	
int seg[4 * maxn];
int laz[4 * maxn];
int l[maxn], r[maxn], t[maxn];

ll update(ll ind, ll cl, ll cr, ll ql, ll qr, ll qt){

}

ll query(ll ind, ll cl, ll cr){
	
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> t[i] >> l[i] >> r[i];
		s.insert(l[i] - 1);
		s.insert(l[i]);
		s.insert(r[i]);
		s.insert(r[i] + 1);

	}
	int curr_ite = 0;
	for(auto ite = s.begin(); ite != s.end(); ite++){
		ite->second = curr_ite;
		curr_ite++;
	}

	for(int i = 0; i < n; i++){
		l[i] = s[l[i]];
		r[i] = s[r[i]];

		update(0, 1, INF, l[i], r[i], t[i]);
		std::cout << query(0, 1, curr_ite) << '\n';
	}
}