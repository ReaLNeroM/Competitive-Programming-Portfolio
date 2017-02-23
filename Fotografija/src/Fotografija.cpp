#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct person {
	ll val, pos;

	bool operator<(const person &x) const {
		return val < x.val;
	}
};

class BIT {
	std::vector<int> array;

	public:
	void resize(ll size){
		array.resize(size, 0);
	}
	ll check(ll pos){
		ll val = array[0];
		while(pos > 0){
			val += array[pos];
			pos -= pos & -pos;
		}

		return val;
	}
	void update(ll pos, ll x){
		while(pos < array.size()){
			array[pos] += x;
			pos += pos & -pos;
		}
	}
};

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;

	ll val[n];
	person pers[n];

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		pers[i].val = val[i];
		pers[i].pos = i;
	}

	std::sort(pers, pers + n);

	for(ll i = 0; i < n; i++){
		val[pers[i].pos] = i + 1;
	}

	BIT left, right;
	left.resize(n + 1), right.resize(n + 1);

	for(ll i = 0; i < n; i++){
		right.update(val[i], 1);
	}

	long long res = 0;

	for(ll i = 0; i < n - 1; i++){
		right.update(val[i], -1);

		res += (left.check(n) - left.check(val[i])) * right.check(val[i]);
		left.update(val[i], 1);
	}

	std::cout << res;
}
