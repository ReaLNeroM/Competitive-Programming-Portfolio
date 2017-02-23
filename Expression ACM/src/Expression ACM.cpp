#include <iostream>

using namespace std;
typedef long long ll;

const ll mod = 45678;

ll size;
static ll s[200005];

void build(){
	for(ll i = size - 1; i > 0; i--){
		s[i] = s[2 * i] * s[2 * i + 1];
		s[i] %= mod;
	}
}

ll query(ll l, ll r){
	ll res = 1;

	for(l += size, r += size; l <= r; l /= 2, r /= 2){
		if(l % 2 == 1){
			res *= s[l];
			l++;
		}
		if(r % 2 == 0){
			res *= s[r];
			r--;
		}

		res %= mod;
	}

	return res;
}
int main() {
    ios::sync_with_stdio(false);

    ll cases;
    cin >> cases;
    const ll m = 100010;
    static ll val[m];
    static ll prefix[m], begin[m], suffix[m], end[m], sum[m];
    static bool mult[m];
    for (ll test = 0; test < cases; test++) {
    	for(ll i = 0; i < m; i++){
    		val[i] = prefix[i] = begin[i] = suffix[i] = end[i] = sum[i] = 0;
    		mult[i] = false;
    	}

    	ll n;
        cin >> n;

        size = n;

        cin >> val[0];
        s[size + 0] = val[0];

        prefix[0] = val[0];
        begin[0] = 0;

        for (ll i = 1; i < n; i++) {
            char ch;
            cin >> ch;
            cin >> val[i];
            s[size + i] = val[i];

            if (ch == '*') {
                mult[i - 1] = true;
                prefix[i] = prefix[i - 1] * val[i];
                prefix[i] %= mod;
                begin[i] = begin[i - 1];
            } else {
                mult[i - 1] = false;
                prefix[i] = val[i];
                begin[i] = i;
            }
        }

        suffix[n - 1] = val[n - 1];
        end[n - 1] = n - 1;

        for (ll i = n - 2; i >= 0; i--) {
            if (mult[i]) {
                suffix[i] = suffix[i + 1] * val[i];
                suffix[i] %= mod;
                end[i] = end[i + 1];
            } else {
                suffix[i] = val[i];
                end[i] = i;
            }
        }

        for(ll i = 0; i < n; i++){
        	if(begin[i] != 0){
        		sum[i] = sum[begin[i] - 1];
        	}

        	sum[i] += prefix[i];
        }

        build();
        ll queries;
        cin >> queries;
        for (ll i = 0; i < queries; i++) {
            ll l, r;
            cin >> l >> r;

            l--, r--;
            ll res = 0;
            if (begin[r] > end[l]) {
                res += suffix[l] + prefix[r];
                r = begin[r];
                l = end[l];
                r--, l++;
                if (r >= l) {
                	res += sum[r];
                	if(l > 0){
                		res -= sum[l - 1];
                	}
                }
            } else {
            	res = query(l, r);
            }

            res %= mod;
            cout << res << '\n';
        }
    }

    return 0;
}
