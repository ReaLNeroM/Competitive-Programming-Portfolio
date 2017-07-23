#include <bits/stdc++.h>

typedef long long ll;

const ll most = 1e9;

bool query(ll val){
	std::cout << "? " << val << std::endl;
	
	char c;
	std::cin >> c;
	
	return (c == 'Y');
}

int main(){
	ll length = 1;
	
	if(!query(9)){
		for(ll i = 10; i <= most; i *= 10){
			if(query(i * 10 - 1)){
				length = i;
				break;
			}
		}
	}
	
	if(!query(most)){
		for(ll i = most; i >= 1; i /= 10){
			if(query(i)){
				length = i;
				break;
			}
		}
	}
	
	ll l = length;
	ll r = length * 10 - 1;
	
	ll best = r;
	
	while(l <= r){
		ll mid = (l + r) / 2;
		
		if(query(mid * 10)){
			r = mid - 1;
			best = mid;
		} else {
			l = mid + 1;
		}
	}
	
	std::cout << "! " << best << std::endl;
}