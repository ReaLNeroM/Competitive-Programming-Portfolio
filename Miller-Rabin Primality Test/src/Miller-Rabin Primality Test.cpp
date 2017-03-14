#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll russian_peasantry(ll a, ll b, ll n){
	ll res = 0;

	for(ll i = 1; i <= b; i *= 2, a = (a * 2) % n){
		if(i & b){
			res += a;
			res %= n;
		}
	}

	return res;
}

ll exponentiate(ll a, ll b, ll mod){
	ll res = 1;
	for(ll i = 1; i <= b; i *= 2, a = russian_peasantry(a, a, mod)){
		if(i & b){
			res = russian_peasantry(res, a, mod);
		}
	}

	return res;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	ll r = 1, d = n - 1;
	while(d % 2 == 0){
		r++;
		d /= 2;
	}

	if(n == 1 or n == 4){
		cout << "FALSE" << endl;
	} else if(n == 2 or n == 3){
		cout << "TRUE" << endl;
	} else if(n % 2 == 0){
		cout << "FALSE" << endl;
	}

	srand(time(0));
	for(int i = 0; i < 50; i++){
		ll num = rand() % (n - 2 - 2 + 1) + 2;

		num = exponentiate(num, d, n);

		for(int j = 0; j < r; j++){
	        ll nnext = (num * num) % n;
	        if (nnext == 1 and num != 1 and num != n-1){
	        	cout << "FALSE" << endl;
	        	return 0;
	        }
	        num = nnext;
	    }
	    if (num != 1){
	    	cout << "FALSE" << endl;
	    	return 0;
	    }
	}

	cout << "PROBABLY TRUE";
}

