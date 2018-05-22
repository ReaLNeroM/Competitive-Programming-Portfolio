#include <bits/stdc++.h>

typedef long long ll;

ll l_a = 1, l_b = 0, d_a = 0, d_b = 1;
ll gcd = -1;

void extended(ll a, ll b){
	if(b == 0){
		gcd = a;
		//std::cout << l_a << ' ' << l_b << ' ' << a << std::endl;
		return;
	}

	ll nl_a, nl_b, nd_a, nd_b;

	nl_a = d_a;
	nl_b = d_b;

	nd_a = l_a - a/b * d_a;
	nd_b = l_b - a/b * d_b;

	l_a = nl_a;
	l_b = nl_b;
	d_a = nd_a;
	d_b = nd_b;

	extended(b, a % b);
}

int main(){
	std::ios::sync_with_stdio(false);

	ll y, x, posy, posx, vx, vy;
	std::cin >> x >> y >> posx >> posy >> vx >> vy;

	if(vy == 0 and vx == 0){
		std::cout << -1 << '\n';
		return 0;
	}
	if(vx == 0){
		if(posx == x or posx == 0){
			if(vy == 1){
				std::cout << posx << ' ' << y << '\n';
			} else if(vy == -1){
				std::cout << posx << ' ' << 0 << '\n';
			}
			return 0;
		} else {
			std::cout << -1 << '\n';
			return 0;
		}
	}
	if(vy == 0){
		if(posy == y or posy == 0){
			if(vx == 1){
				std::cout << x << ' ' << posy << '\n';
			} else if(vx == -1){
				std::cout << 0 << ' ' << posy << '\n';
			}
			return 0;
		} else {
			std::cout << -1 << '\n';
			return 0;
		}
	}
	ll resy = -1, resx = -1;

	ll alpha1;
	if(vy == 1){
		alpha1 = y - posy;
	} else if(vy == -1){
		alpha1 = posy;
	}

	ll alpha2;
	if(vx == 1){
		alpha2 = x - posx;
	} else if(vx == -1){
		alpha2 = posx;
	}

	ll beta1 = y;
	ll beta2 = x;

	extended(y, x);

	if(std::abs(alpha1 - alpha2) % gcd == 0){
		l_a *= (alpha1 - alpha2) / gcd;
		l_b *= (alpha1 - alpha2) / gcd;

		ll time = alpha1 - beta1 * l_a;
		if(time < 0){
			time += y * x;
		}

		std::vector<ll> updated = {posy + time * vy, posx + time * vx};

		if((updated[0] / y) % 2 == 0){
			resy = 0;
		} else {
			resy = y;
		}
		if((updated[1] / x) % 2 == 0){
			resx = 0;
		} else {
			resx = x;
		}
	}

	if(resy == -1){
		std::cout << -1 << '\n';
	} else {
		std::cout << resx << ' ' << resy << '\n';
	}
}