#include "gap.h"
#include <algorithm>

#include <iostream>

typedef long long ll;

ll maxn = 1e18;

long long findGap(int T, int N)
{
	ll res = 0;

	if(T == 1 or N == 2){
		ll l = -1, r = maxn + 1;

		for(ll a = 0, b = N - 1; a <= b; a++, b--){
			ll res_l, res_r;

			MinMax(l + 1, r - 1, &res_l, &res_r);

			if(res_l == -1){
				break;
			}
			if(l != -1){
				res = std::max(res, res_l - l);
				res = std::max(res, r - res_r);
			}
			if(a == b - 1){
				res = std::max(res, res_r - res_l);
			}

			l = res_l;
			r = res_r;
		}
	} else {
		ll last_seen;
		ll border;

		MinMax(0, maxn, &last_seen, &border);

		ll distance = border - last_seen;
		ll amount = N - 1;

		ll must_gap = (distance + amount - 1) / amount;

		ll l = last_seen + 1;

		while(l < border){
			ll new_l, new_r;
			MinMax(l, l + must_gap - 1, &new_l, &new_r);

			if(new_l == -1){
				l = l + must_gap;
			} else {
				res = std::max(res, new_l - last_seen);

				last_seen = new_r;
				l = new_r + 1;
			}
		}

		res = std::max(res, border - last_seen);
	}
	
	return res;
}
