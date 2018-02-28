#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	ll sum, digits;
	std::cin >> sum >> digits;

	ll pow = 1;
	for(ll i = 1; i < digits; i++){
		pow *= 10;
		pow += 1;
	}

	while(pow >= 1){
		for(ll j = 0; j <= 9; j++){
			if(j * pow <= sum and sum < (j + 1) * pow){
				sum -= j * pow;
				std::cout << j;
				break;
			}
		}
		
		pow /= 10;
	}
}