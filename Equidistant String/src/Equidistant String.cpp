#include <iostream>

typedef long long ll;

int main() {
	std::string a, b;
	std::cin >> a >> b;

	ll distance = 0;
	for(ll i = 0; i < a.length(); i++){
		if(a[i] != b[i]){
			distance++;
		}
	}

	if(distance % 2 == 1){
		std::cout << "impossible";
	} else {
		ll i, left;
		for(i = 0, left = distance / 2; left > 0 and i < a.length() and left > 0; i++){
			std::cout << a[i];
			if(a[i] != b[i]){
				left--;
			}
		}
		while(i < b.length()){
			std::cout << b[i];
			i++;
		}
	}
	return 0;
}
