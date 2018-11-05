#include <bits/stdc++.h>

typedef long long ll;

int main(){
	ll digits;

	std::cout << "Enter desired number of digits: ";
	std::cout.flush();
	std::cin >> digits;

	std::vector<ll> s(digits);
	for(ll i = 0; i < digits; i++){
		ll a = 120LL * i * i + 151LL * i + 47LL;
		ll b = 512LL * i * i * i * i + 1024LL * i * i * i + 712LL * i * i + 194LL * i + 15LL;
		for(ll j = i; j < digits; j++){
			s[j] += (a / b) % 16;
			a *= 16;
			a %= 16 * b;
		}
	}

	for(int j = digits - 1; j > 0; j--){
		s[j - 1] += s[j] / 16;
		s[j] %= 16;
	}

	// std::vector<ll> conv(digits + 1);

	// int curr10pos = 0;
	// int rem = 0;

	// for(int i = 0; i < digits; i++){
	// 	rem *= 16;
	// 	rem += s[i];
	// }

	// for(int j = digits - 1; j > 0; j--){
	// 	conv[j - 1] += conv[j] / 10;
	// 	conv[j] %= 10;
	// }
	for(int i = 0; i < digits; i++){
		if(s[i] >= 10){
			std::cout << (char) ('A' + s[i] - 10);
		} else {
			std::cout << s[i];
		}
	}

	std::cout << '\n';
}
