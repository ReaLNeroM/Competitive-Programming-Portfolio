#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
const double eps = 1e-11;
int val[maxn];
int orbs, q;

double calc(int adds){

}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> orbs >> q;
	for(int i = 0; i < q; i++){
		double v;
		cin >> v;
		v -= eps;
		v /= (double) 2000.0;

		int best = 1e6;
		int l = orbs, r = 1e6;
		while(l <= r){
			int mid = (l + r) / 2;

			double get_chance = calc(mid);

			if(v < get_chance){
				r = mid - 1;
				best = mid;
			} else {
				l = mid + 1;
			}
		}

		cout << best << '\n';
	}

}

