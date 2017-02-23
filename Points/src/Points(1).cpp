#include <iostream>
#include <vector>

typedef long long ll;

class BIT {
	std::vector<ll> array;
public:
	ll size;
	void update(ll pos, ll val){
		while(pos < size){
			array[pos] += val;
			pos += pos & (-pos);
		}
	}
	ll check(ll pos){
		ll res = array[0];

		while(pos > 0){
			res += array[pos];
			pos -= pos & (-pos);
		}
	}
	ll resize(ll size){
		array.resize(size, 0);
	}
};

int main() {
	ll points;
	std::cin >> points;

	ll sum[points];
	for(ll i = 0; i < points; i++){
		std::cin >> sum[i];
	}

	BIT used;
	used.resize(10000);

	for(ll i = points - 1; i >= 0; i++){
//		for(ll pos = )
	}

	std::cout << used.check(used.size - 1);

	return 0;
}
