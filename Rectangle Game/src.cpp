#include <bits/stdc++.h>

typedef long long ll;

const ll max_log = 28;
const ll maxn = 100000000;

int main(){
	ll x = -1, y = -1;

	ll x_equal[max_log];
	ll x_step[max_log];

	ll y_equal[max_log];
	ll y_step[max_log];

	x_equal[0] = 1;
	x_step[0] = 1;	

	for(ll i = 1; i < max_log; i++){
		x_step[i] = x_step[i - 1] * 2;
		x_equal[i] = x_equal[i - 1] + x_step[i];
	}

	for(ll i = 0; i < max_log; i++){
		y_equal[i] = x_equal[i];
		y_step[i] = x_step[i];
	}
	
	while(x + y != 2){
		std::cin >> x >> y;

		bool found = false;
		for(ll i = 0; i < max_log and !found; i++){
			ll new_height = x_equal[i] + (x - 1) * x_step[i];

			if(y > new_height and y - new_height <= new_height){
				std::cout << "H " << new_height << std::endl;
				found = true;
			}
		}

		for(ll i = 0; i < max_log and !found; i++){
			ll new_height = y_equal[i] + (y - 1) * y_step[i];

			if(x > new_height and x - new_height <= new_height){
				std::cout << "V " << new_height << std::endl;
				found = true;
			}
		}

		if(x == 1 or y == 1){
			//last step
			break;
		}
	}

	std::cout << "-1 -1" << std::endl;
}
