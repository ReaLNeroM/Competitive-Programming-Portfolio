#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

static int laz[100];
static bool cir[100];

void shift(bool add, int ind, int h, bool leaf){
	if(h == -1){
		return;
	}
	if(laz[ind] == -1 and (!leaf or add)){
		laz[ind] = h;
		cir[ind] = add;
		return;
	}
	if(add == 1){
		if(laz[ind] < h){
			cir[ind] = add;
			laz[ind] = h;
		}
	} else {
		if(laz[ind] > h){
			cir[ind] = add;
			laz[ind] = h;
		}
	}
}

void up(int ind, int cl, int cr, int ql, int qr, int h, bool type){
	if(qr <= cl or cr <= ql){
		return;
	}

	if(ql <= cl and cr <= qr){
		shift(type, ind, h, (cl == cr + 1));
		return;
	}

	int mid = (cl + cr) / 2;

	shift(cir[ind], 2 * ind + 1, laz[ind], (cl == cr + 1));
	shift(cir[ind], 2 * ind + 2, laz[ind], (cl == cr + 1));

	up(2 * ind + 1, cl, mid, ql, qr, h, type);
	up(2 * ind + 2, mid, cr, ql, qr, h, type);

	laz[ind] = -1;
}


int query(int ind, int cl, int cr, int ql, int qr){
	if(qr <= cl or cr <= ql){
		return -1;
	}

	if(ql <= cl and cr <= qr){
		if(laz[ind] != -1){
			return laz[ind];
		}
		return 0;
	}

	int val = -1;
	int mid = (cl + cr) / 2;

	shift(cir[ind], 2 * ind + 1, laz[ind], (cl + 1 == mid));
	shift(cir[ind], 2 * ind + 2, laz[ind], (mid + 1 == cr));

	val = query(2 * ind + 1, cl, mid, ql, qr);
	if(val == -1){
		val = query(2 * ind + 2, mid, cr, ql, qr);
	}
	laz[ind] = -1;

	return val;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	for(int i = 0; i < 100; i++){
		laz[i] = -1;
	}
	for(int i = 0; i < q; i++){
		char c;
		int l, r, h;
		cin >> c >> l >> r >> h;

		if(c == 'a'){
			up(0, 0, n, l, r + 1, h, 1);
		} else {
			up(0, 0, n, l, r + 1, h, 0);
		}
		for(int i = 0; i < n; i++){
			cout << query(0, 0, n, i, i + 1) << ' ';
		}
		cout << endl;
	}

	return 0;
}
