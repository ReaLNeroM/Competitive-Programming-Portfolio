#include <iostream>

typedef unsigned long long ll;

const ll max = 1002;

int main(){

	int smallmax = 20000, check;
	for(ll j = 1; j <= smallmax; j++){

		if(j % 8 == 0){
			std::cout << j << std::endl;
		}
		for(ll k = j; k <= smallmax; k++){
			for(ll l = k; l <= smallmax; l++){

				check = j * k - l;
				if(check != 0 and check == (check & -check)){
					check = j * l - k;
					if(check != 0 and check == (check & -check)){
						check = k * l - j;
						if(check != 0 and check == (check & -check)){
							std::cout << j << " " << k << " " << l << std::endl;
						}
					}
				}
			}
		}
	}
}
