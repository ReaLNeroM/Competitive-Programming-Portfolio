#include <bits/stdc++.h>

typedef long long ll;

std::map<ll, ll> app;

ll gcd(ll a, ll b){
	while(b != 0){
		ll temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int main(){
	std::ios::sync_with_stdio(false);
	int count = 0;
	for(ll i = 1; i < 1000001; i++){
		for(ll j = 1; j < i; j++){
			if((i % 2 + j % 2 == 1) and i * i - j * j <= 1000000){
				if(gcd(i, j) == 1){
					app[i * i - j * j]++;
					app[2 * i * j]++;
					count += 2;
				}
			}
			if(2 * i * j > 1000000){
				break;
			}
		}

		if(i % 128 == 0){
			std::cout << i << std::endl;
		}
	}

	ll most = 0;

	std::cout << count << std::endl;

	auto ite = app.begin();
	while(ite != app.end()){
		most = std::max(most, ite->second);
		ite++;
	}

	std::cout << most;
}