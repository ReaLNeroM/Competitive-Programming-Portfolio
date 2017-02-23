#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

static ll val[13][4000005];
static short laz[13][4000005];

ll query(ll ind, ll cl, ll cr, ll ql, ll qr, ll seg){
	if(qr <= cl or cr <= ql){
		return 0;
	}
	if(ql <= cl and cr <= qr){
		return val[seg][ind];
	}

	ll sum = 0;
	ll mid = (cl + cr) / 2;

	if(laz[seg][ind] != 0){
		laz[seg][2 * ind + 1] += laz[seg][ind];
		val[seg][2 * ind + 1] += (mid - cl) * laz[seg][ind];

		laz[seg][2 * ind + 2] += laz[seg][ind];
		val[seg][2 * ind + 2] += (cr - mid) * laz[seg][ind];

		laz[seg][ind] = 0;
	}

	sum += query(2 * ind + 1, cl, mid, ql, qr, seg);
	sum += query(2 * ind + 2, mid, cr, ql, qr, seg);

	return sum;
}

void update(ll ind, ll cl, ll cr, ll ql, ll qr, ll seg, ll valx){
	if(qr <= cl or cr <= ql){
		return;
	}
	if(ql <= cl and cr <= qr){
		val[seg][ind] += (cr - cl) * valx;
		laz[seg][ind] += valx;
		return;
	}

	ll mid = (cl + cr) / 2;

	if(laz[seg][ind] != 0){
		laz[seg][2 * ind + 1] += laz[seg][ind];
		val[seg][2 * ind + 1] += (mid - cl) * laz[seg][ind];

		laz[seg][2 * ind + 2] += laz[seg][ind];
		val[seg][2 * ind + 2] += (cr - mid) * laz[seg][ind];

		laz[seg][ind] = 0;
	}
	update(2 * ind + 1, cl, mid, ql, qr, seg, valx);
	update(2 * ind + 2, mid, cr, ql, qr, seg, valx);
	val[seg][ind] = val[seg][2 * ind + 1] + val[seg][2 * ind + 2];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);

	ll y, x;
	cin >> y >> x;

	ll q;
	cin >> q;
	for(ll i = 0; i < q; i++){
		char c;
		ll y1, x1, y2, x2;
		cin >> c >> y1 >> x1 >> y2 >> x2;
		y1--, x1--, y2--, x2--;

		if(c == 'q'){
			ll sum = 0;
			for(ll i = y1; i <= y2; i++){
				sum += query(0, 0, x, x1, x2 + 1, i);
			}

			cout << sum << '\n';
		} else {
			ll valx;
			if(c == 'a'){
				valx = 1;
			} else {
				valx = -1;
			}

			for(ll i = y1; i <= y2; i++){
				update(0, 0, x, x1, x2 + 1, i, valx);
			}
		}
	}
	return 0;
}
