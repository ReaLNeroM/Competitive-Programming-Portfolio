#include <bits/stdc++.h>

typedef long long ll;

int array[] = {0, -1, 9, -1, 8, -1, 7, -1, 6, -1, 5, -1, 4, -1, 3, -1, 2, -1, 1};
const int array_size = 19;

bool good(ll number){
	for(int i = 0; i <= 19; i++){
		if(i == 19){
			return true;
		}

		if(array[i] != -1 and array[i] != number % 10){
			return false;
		}

		number /= 10;
	}
}

int main(){
	bool found = false;
	for(ll i = 1388314624 ; !found; i++){
		if(i % 1048576 == 0){
			std::cout << i << '\n';
		}
		if(good(i * i)){
			std::cout << i << ' ' << i * i << std::endl;
			return 0;
		}
	}
}