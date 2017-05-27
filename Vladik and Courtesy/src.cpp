#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int a, b;
	std::cin >> a >> b;

	for(int i = 1; i < 1000000; i++){
		if(i % 2 == 0){
			b -= i;
			if(b < 0){
				std::cout << "Valera";
				break;
			}
		} else {
			a -= i;
			if(a < 0){
				std::cout << "Vladik";
				break;
			}
		}
	}
}