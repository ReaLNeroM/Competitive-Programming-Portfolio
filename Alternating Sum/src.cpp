#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 9;

ll pow(ll a, ll b){
	a %= mod;
	
	ll res = 1;

	while(b != 0){
		if(b % 2 == 1){
			res = res * a % mod;
		}

		a = a * a % mod;

		b /= 2;
	}

	return res;
}

ll inverse(ll a){
	return pow(a, mod - 2LL);
}

ll roll(ll a){
	a %= mod;

	if(a < 0){
		a += mod;
	}

	return a;
}

ll calculate_expression(ll a, ll b, ll n, ll k, ll start){
	ll generated_expression = 1;

	ll first_number = pow(a, start) * pow(b, n - start);
	ll second_number = pow((b * inverse(a)) % mod, n + 1) + mod - 1;
	ll third_number = inverse(pow((b * inverse(a)) % mod, k) + mod - 1);

	first_number = roll(first_number);
	second_number = roll(second_number);
	third_number = roll(third_number);

	if(third_number == 0){
		return roll(((n + 1) / k) * first_number);
	}

	generated_expression = roll(generated_expression * first_number);
	generated_expression = roll(generated_expression * second_number);
	generated_expression = roll(generated_expression * third_number);

	return generated_expression;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n, a, b, k;
	std::cin >> n >> a >> b >> k;

	std::string s;
	std::cin >> s;

	ll res = 0;
	for(int i = 0; i < k; i++){
		if(s[i] == '-'){
			res -= calculate_expression(a, b, n, k, n - i);
		} else if(s[i] == '+'){
			res += calculate_expression(a, b, n, k, n - i);
		}

		res = roll(res);
	}

	std::cout << res << '\n';
}