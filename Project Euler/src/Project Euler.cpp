#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

typedef long long ll;
using namespace std;

const ll size = 1000000;

int main() {
	ll mistakes = 0;
	for(ll i = 1; i <= size; i++){
		mistakes += i - 1;
	}

	ll found = 0;
	for(ll i = 4; i <= size; i++){
		ll x = i, foundx = 1;

		for(int j = 2; j * j <= x; j++){
			if(x % j == 0){
				ll used = 0;
				while(x % j == 0){
					used++;
					x /= j;
				}

				foundx *= used + 1;
			}
		}
		if(i != x and x != 1 and i % x == 0){
			foundx *= 2;
		}

		if(i != x){
			found += foundx - 2;
		}

	}
	cout << mistakes << ' ' << found << ' ' << mistakes - found << endl;

	return 0;
}
