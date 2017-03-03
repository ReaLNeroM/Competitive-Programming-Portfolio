#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);

	ll a, b, c;
	cin >> a >> b >> c;

	while(c > 2 and min(a, b) != 0){
		if(a >= b){
			ll times = a / b;

			a = a % b;
			//b remains constant

			c -= min(((c - 1) / 2) * 2, 2 * times);
		} else {
			ll times = b / a;

			//a remains constant
			b = b % a;

			c -= min(((c - 1) / 2) * 2, 2 * times);
		}
	}

	if(min(a, b) == 0){
		c--;
		c %= 2;
		c++; //kekeke
	}

	if(c == 1){
		cout << a;
	} else {
		cout << b;
	}
}
