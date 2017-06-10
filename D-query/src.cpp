#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 30005;
const int maxval = 1e6 + 1e2;
int n;
int seg[100 * maxn];
int last[maxval];
int l[100 * maxn];
int r[100 * maxn];
int location[maxn];
int val[maxn];
int next = 1;

int build(int a, int b){
	int curr = next;
	next++;

	if(a == b){
		seg[curr] = 1;
	} else {
		l[curr] = build(a, (a + b) / 2);
		r[curr] = 0;
		seg[curr] = seg[l[curr]] + seg[r[curr]];
	}

	return curr;
}

int update(int loc, int cl, int cr, int ql, int qr, int change){
	int curr = next;
	next++;

	if(ql <= cl and cr <= qr){
		seg[curr] = seg[loc] + change;

		return curr;
	} else if(qr < cl or cr < ql){
		return loc;
	}

	int mid = (cl + cr) / 2;

	l[curr] = update(l[loc], cl     , mid, ql, qr, change);
	r[curr] = update(r[loc], mid + 1,  cr, ql, qr, change);

	seg[curr] = seg[l[curr]] + seg[r[curr]];

	return curr;
}

int query(int pos, int cl, int cr, int ql, int qr){
	if(ql <= cl and cr <= qr){
		return seg[pos];
	} else if(qr < cl or cr < ql){
		return 0;
	}

	int mid = (cl + cr) / 2;

	return query(l[pos], cl     , mid, ql, qr) +
		   query(r[pos], mid + 1,  cr, ql, qr);
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		last[val[i]] = -1;
	}

	location[0] = build(0, n - 1);
	last[val[0]] = 0;

	for(int i = 1; i < n; i++){
		location[i] = update(location[i - 1], 0, n - 1, i, i, 1);
		if(last[val[i]] != -1){
			location[i] = update(location[i], 0, n - 1, last[val[i]], last[val[i]], -1);
		}

		last[val[i]] = i;
	}

	int q;
	std::cin >> q;

	std::stringstream istr;
	
	for(int i = 0; i < q; i++){
		int x, y;
		
		std::cin >> x >> y;
		x--, y--;

		istr << query(location[y], 0, n - 1, x, y) << '\n';
	}

	std::cout << istr.str();
}
