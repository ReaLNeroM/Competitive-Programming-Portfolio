#include <bits/stdc++.h>

typedef long long ll;

struct treap {
	ll val, prior, size;
	treap *l, *r;
};

typedef treap* ptreap;

ptreap head = NULL;

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

void merge(ptreap& pos, ptreap l, ptreap r){
	if(!l or !r){
		if(!l){
			pos = r;
		} else {
			pos = l;
		}
	} else if(l->prior > r->prior){
		merge(l->r, l->r, r);
		pos = l;
	} else {
		merge(r->l, l, r->l);
		pos = r;
	}

	update_size(pos);
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

void erase(ptreap& pos, ll val){
	if(!pos){
		return;
	} else if(val == pos->val){
		ptreap temp = pos;
		merge(pos, pos->l, pos->r);
		delete temp;
	} else if(val < pos->val){
		erase(pos->l, val);
	} else {
		erase(pos->r, val);
	}

	update_size(pos);
}

ll count(ptreap pos, ll val){
	if(!pos){
		return 0;
	} else if(val > pos->val){
		return count(pos->r, val);
	} else {
		return count(pos->l, val) + size(pos->r) + 1;
	}
}

ptreap init(ll val, ll prior){
	ptreap curr = new treap;
	curr->val = val;
	curr->prior = prior;
	curr->size = 1;
	curr->l = NULL;
	curr->r = NULL;

	return curr;
}


const ll maxn = 1e6 + 1e2;
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, m;
	std::cin >> n >> m;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		val[i] -= m;
	}

	ll prefsum = 0;

	for(ll i = 0; i < n; i++){
		prefsum += val[i];

		ptreap curr = init(prefsum, rand());
		insert(head, curr);
	}

	ll res = 0;
	prefsum = 0;
	for(ll i = 0; i < n; i++){
		res += count(head, prefsum);
		prefsum += val[i];
		erase(head, prefsum);
	}

	std::cout << res << '\n';
}
