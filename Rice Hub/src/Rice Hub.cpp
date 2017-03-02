#include <bits/stdc++.h>
#include "grader.h"

typedef long long ll;
using namespace std;

int besthub(int R, int L, int X[], long long B){
	ll l = 1, r = R;
	ll best = 0;

	while(l <= r){
		ll mid = (l + r) / 2;

		ll sum = 0;
		ll med = (mid - 1) / 2;
		ll li = 0, ri = mid - 1;
		for(int i = 0; i < mid; i++){
			sum += abs(X[i] - X[med]);
		}

		bool good = false;
 		for(int i = mid; i < R; i++){
			if(sum <= B){
				good = true;
			}

			li++;
			sum -= abs(X[i - mid] - X[med]);

			sum += abs(X[i] - X[med]);
			ri++;

			while((li + ri) / 2 > med){
				sum += (med - li + 1) * (X[med + 1] - X[med]);
				sum -= (ri - med) * (X[med + 1] - X[med]);
				med++;
			}
		}
		if(sum <= B){
			good = true;
		}

		if(good){
			l = mid + 1;
			best = max(best, mid);
		} else {
			r = mid - 1;
		}
	}

	return best;
}
