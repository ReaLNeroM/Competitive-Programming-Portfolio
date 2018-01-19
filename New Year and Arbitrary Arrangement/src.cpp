#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;

struct rational {
	ll a = 0, b = 1;

	rational(){
		a = 0, b = 1;
	}
	rational(ll ca, ll cb){
		a = ca;
		b = cb;
	}
	rational coprime(rational x){
		ll gcd_calculated = std::__gcd(x.a, x.b);
		x.a /= gcd_calculated;
		x.b /= gcd_calculated;

		return x;
	}
	rational operator+(rational sec){
		rational x = *this;
		x.b *= sec.b;
		sec.b = x.b;
		x.a += sec.a;

		return x;
	}
	rational operator-(rational sec){
		rational x = *this;
		x.b *= sec.b;
		sec.b = x.b;
		x.a -= sec.a;

		return x;
	}
	operator+=(rational sec){
		b *= sec.b;
		sec.b = b;
		a -= sec.a;
	}
	rational operator*(rational sec){
		rational x = *this;
		x.a *= sec.a;
		x.b *= sec.b;

		x = coprime(x);
		return x;
	}
	rational operator*(ll mult){
		rational x = *this;
		x.a *= mult;

		x = coprime(x);
		return x;
	}
	rational operator/(rational sec){
		rational x = *this;
		x.a *= sec.b;
		x.b *= sec.a;

		x = coprime(x);
		return x;
	}
	rational operator/(ll div){
		rational x = *this;
		x.b *= div;

		x = coprime(x);
		return x;
	}
};

rational make_rational(ll x, ll y){
	rational temp;
	temp.a = x;
	temp.b = y;

	return temp;
}

rational prob[maxn][maxn];
rational identity;

rational f(rational a, rational b){
	return b / (identity - a) + a / ((identity - a) * (identity - a));
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cout.precision(10);

	int k, i_p_a, i_p_b;
	std::cin >> k >> i_p_a >> i_p_b;

	rational p_a(i_p_a, i_p_a + i_p_b);
	rational p_b(i_p_b, i_p_a + i_p_b);
	identity = make_rational(1, 1);

	prob[0][0] = identity;
	for(int i = 0; i < k; i++){
		for(int j = 0; j <= k; j++){
			if(j == k){
				prob[i][j] = prob[i][j] / (identity - p_a);
			}
			if(j == 0){
				prob[i][j] = prob[i][j] / (identity - p_b);
			}
			if(j != k){
				prob[i][j + 1] += prob[i][j] * p_a;
			}
			if(i + j < k and j != 0){
				prob[i + j][j] += prob[i][j] * p_b;
			}

			if(j == k){
				prob[i][j] = prob[i][j] * (identity - p_a);
			}
		}
		std::cout << '\n';
	}

	rational res(0, 1);
	for(int i = 0; i < k; i++){
		for(int j = 0; j <= k; j++){
			if(j == k){
				rational temp(i + j, 1);
				res += prob[i][j] * p_b * (temp / (identity - p_a) + p_a / ((identity - p_a) * (identity - p_a)));
			} else if(i + j >= k){
				res += prob[i][j] * p_b * (i + j);
			}
		}
	}

	std::cout.precision(10);
	std::cout << std::fixed << res.a << '\n'
};