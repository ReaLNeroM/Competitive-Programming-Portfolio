#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 3e8 + 1e2;
const int maxsqrn = 20000;
const ll mod = (1LL << 32);

static std::bitset<maxn / 3> composite;
ll a, b, c, d;

double other = 0.0;

ll calculate(ll x, ll n){
	ll p = x;

	other += std::log(n) / std::log(x);

	ll sum = 0;

	while(p <= n){
		sum += n / p;
		p *= x;
	}

	return sum * (a * x * x % mod * x % mod +
					b * x * x % mod +
					c * x % mod +
					d)
							% mod;
}

int main(){

	ll n;
	std::cin >> n;

	std::cin >> a >> b >> c >> d;

	ll res = calculate(2, n) + calculate(3, n);

	for(ll i = 6, ind = 0; i - 1 <= n; i += 6, ind += 2){
		if(composite[ind] == 0){
			res += calculate(i - 1, n);
		}
		if(i + 1 <= n and composite[ind + 1] == 0){
			res += calculate(i + 1, n);
		}

		if(i < maxsqrn){
			ll factor = (i - 1) * (i - 1);

			int appear1, appear5;
			int jmp1to5, jmp5to1;

			if(composite[ind] == 0){
				appear1 = 6;
				appear5 = 6;

				for(int j = 0; j < 6; j++){
					if((i - 1) * j % 6 == 1){
						appear1 = j;
					} else if((i - 1) * j % 6 == 5){
						appear5 = j;
					}
				}

				jmp1to5 = (appear5 - appear1 + 6) % 6 * (i - 1);
				jmp5to1 = (appear1 - appear5 + 6) % 6 * (i - 1);

				if(composite[ind] == 0){
					while(factor <= n){
						if(factor % 6 == 1 or factor % 6 == 5){
							composite[(factor + 1) / 3 - 2 + (factor % 6 == 1)] = 1;
							if(factor % 6 == 1){
								factor += jmp1to5;
							} else {
								factor += jmp5to1;
							}
						} else {
							factor += i - 1;
						}
					}
				}
			}

			if(composite[ind + 1] == 0){
				appear1 = 6;
				appear5 = 6;

				for(int j = 0; j < 6; j++){
					if((i + 1) * j % 6 == 1){
						appear1 = j;
					} else if((i + 1) * j % 6 == 5){
						appear5 = j;
					}
				}

				jmp1to5 = (appear5 - appear1 + 6) % 6 * (i + 1);
				jmp5to1 = (appear1 - appear5 + 6) % 6 * (i + 1);

				factor = (i + 1) * (i + 1);
				while(factor <= n){
					if(factor % 6 == 1 or factor % 6 == 5){
						composite[(factor + 1) / 3 - 2 + (factor % 6 == 1)] = 1;
						if(factor % 6 == 1){
							factor += jmp1to5;
						} else {
							factor += jmp5to1;
						}
					} else {
						factor += i + 1;
					}
				}
			}
		}
	}

	std::cout << other << '\n';
}
