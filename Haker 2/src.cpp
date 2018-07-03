#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll INF = 1e16;
ll val[maxn];
ll tree[maxn];
ll tree2[maxn];
ll tree_single[maxn];
ll tree2_single[maxn];
std::multiset<ll> s1, s2;

void update(ll pos, ll change){
	pos++;

	ll copy_pos = pos;

	while(copy_pos < maxn){
		tree[copy_pos] += change * (pos - 1);
		tree_single[copy_pos] += change;
		copy_pos += copy_pos & -copy_pos;
	}

	copy_pos = pos;
	while(copy_pos > 0){
		tree2[copy_pos] += change * (pos - 1);
		tree2_single[copy_pos] += change;
		copy_pos -= copy_pos & -copy_pos;
	}
}

ll n, k;

ll query(ll pos, ll single_cost){
	pos++;

	ll res = 0;

	while(pos > 0){
		res -= tree[pos];
		res += single_cost * tree_single[pos];
		pos -= pos & -pos;
	}

	return res;
}

ll query2(ll pos, ll single_cost){
	pos++;

	ll res = 0;

	while(pos < maxn){
		res += tree2[pos];
		res -= single_cost * tree2_single[pos];
		pos += pos & -pos;
	}

	return res;
}

void add_bst(ll x){
	if(s2.empty() or *s2.begin() >= x){
		s1.insert(x);
	} else {
		s2.insert(x);
	}
}
void remove_bst(ll x){
	if(s1.find(x) != s1.end()){
		s1.erase(s1.find(x));
	} else {
		s2.erase(s2.find(x));
	}
}
ll find_median(){
	ll size = s1.size() + s2.size();
	ll expected_s1 = (size + 1) / 2;
	ll expected_s2 = size / 2;

	while(s1.size() < expected_s1){
		s1.insert(*s2.begin());
		s2.erase(s2.begin());
	}
	while(s2.size() < expected_s2){
		s2.insert(*--s1.end());
		s1.erase(--s1.end());
	}

	return *s1.rbegin();
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> k;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	ll res = INF, res_index = 0;

	for(ll i = 0; i < n; i++){
		update(val[i], 1);
		add_bst(val[i]);

		if(i - k + 1 >= 0){
			ll median = find_median();

			ll attempt = query(median - 1, median) + query2(median + 1, median);

			if(attempt < res){
				res = attempt;
				res_index = i - k + 1;
			}

			remove_bst(val[i - k + 1]);
			update(val[i - k + 1], -1);
		}
	}

	std::cout << res << ' ' << res_index + 1 << '\n';
}
