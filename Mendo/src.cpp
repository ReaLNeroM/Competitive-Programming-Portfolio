#include <bits/stdc++.h>

typedef long long ll;

<<<<<<< HEAD
struct treap {
	ll val, prior, size;
	treap *l, *r;
};

typedef treap* ptreap;

ll size(ptreap p){
	if(p){
		return p->size;
	}

	return 0;
}

ll update_size(ptreap p){
	if(p){
		p->size = 1 + size(p->l) + size(p->r);
	}
}

void split(ptreap pos, ptreap& l, ptreap& r, ll val){
	if(!pos){
		l = r = NULL;
	} else if(val <= pos->val){
		split(pos->l, l, pos->l, val);
		r = pos;
	} else {
		split(pos->r, pos->r, r, val);
		l = pos;
	}

	update_size(pos);
}

void insert(ptreap& pos, ptreap add){
	if(!pos){
		pos = add;
	} else if(add->prior > pos->prior){
		split(pos, add->l, add->r, add->val);
		pos = add;
	} else if(add->val <= pos->val){
		insert(pos->l, add);
	} else {
		insert(pos->r, add);
	}

	update_size(pos);
}

ll count(ptreap pos, ll val){
	if(!pos){
		return 0;
	} else if(val <= pos->val){
		return count(pos->l, val);
	} else {
		return count(pos->r, val) + size(pos->l) + 1;
	}
}

const ll maxn = 500005;
ptreap pos[maxn], neg[maxn];

ptreap init(ll ind, ll val, ll prior){
	pos[ind] = new treap;
	pos[ind]->val = val;
	pos[ind]->prior = prior;
	pos[ind]->size = 1;
	pos[ind]->l = NULL;
	pos[ind]->r = NULL;

	return pos[ind];
}

ll curr = 1;
ll other = maxn - 1;

std::unordered_map<ll, ll> m;

void initialize(ll n, ll m){

}

void update(ll x, ll y1, ll y2){
	ll ind = m[x];

	if(ind == 0){
		m[x] = curr;
		ind = curr;
		curr++;
	}

	insert(pos[ind], init(other, y1, rand()));
	insert(neg[ind], init(other, y2 + 1, rand()));
	other--;
}

ll query(ll x, ll y){
	ll ind = m[x];

	if(ind == 0){
		return 0;
	} else {
		return count(pos[ind], y + 1) - count(neg[ind], y + 1);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	ll y, x;
	std::cin >> y >> x;

	ll t;

	initialize(y, x);

	while(std::cin >> t){
		if(t == 0){
			ll qx, qy1, qy2;
			std::cin >> qx >> qy1 >> qy2;

			update(qx, qy1, qy2);
		} else {
			ll qx, qy;
			std::cin >> qx >> qy;

			std::cout << query(qx, qy) << '\n';
		}
	}
=======
const ll maxn = 1e6 + 100;
ll n;
ll h[maxn];
ll candles[maxn];

ll res = 0;

bool good(ll pos){
    if(pos == 0){
        return true;
    }
    std::map<ll, ll> m;
    for(ll i = 0; i < pos; i++){
        m[candles[i]]++;
    }

    std::vector<ll> v;
    v.resize(m.rbegin()->first, 0);
    ll sum = 0;
    ll prev = m.rbegin()->first - 1;
    ll ind;
    for(auto i = m.rbegin(); true; i++){
        if(i == m.rend()){
            ind = 0;
            for(ll j = ind; j <= prev; j++){
            	v[j] = sum;
            }
            prev = ind;
            break;
        } else {
            ind = i->first - 1;
            for(ll j = ind; j <= prev; j++){
                v[j] = sum;
            }
            prev = ind;
        }
        sum += i->second;
    }

    std::sort(v.begin(), v.end());

    ll curr = 0;
    ll left = 0;
    for(ll i = 0; i < v.size(); i++){
        do {
            if(curr == n){
                return false;
            }
            left += h[curr];
            curr++;
        } while(left < v[i]);

        left -= v[i];
    }

    return true;
}

int main(){
    std::ios::sync_with_stdio(false);

    ll evenings;
    std::cin >> n >> evenings;

    for(ll i = 0; i < n; i++){
        std::cin >> h[i];
//    	h[i] = 99998;
    }
    std::sort(h, h + n);

    for(ll i = 0; i < evenings; i++){
        std::cin >> candles[i];
//    	candles[i] = 99998;
    }

    ll l = 0, r = evenings;

    while(l <= r){
        ll mid = (l + r) / 2;

        if(good(mid)){
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    std::cout << res;
>>>>>>> 06dca68cc092752aad30f6d18dce3c7425891903
}
