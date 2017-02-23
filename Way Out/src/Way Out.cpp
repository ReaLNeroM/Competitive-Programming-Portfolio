#include <iostream>
#include <vector>

typedef long long ll;

std::vector<ll> array;
ll size;

void update(ll left, ll right, ll val){
	while(left <= size){
		array[left] += val;
		left += (left) & (-left);
	}

	right++;
	while(right <= size){
		array[right] -= val;
		right += (right) & (-right);
	}
}

ll query(ll pos){
	ll res = 0;

	while(pos > 0){
		res += array[pos];
		pos -= (pos) & (-pos);
	}

	return res;
}

int main() {
	ll cases;
	std::cin >> cases;

	ll res[cases];

	for(ll i = 0; i < cases; i++){

		ll height;
		std::cin >> size >> height;

		res[i] = size * size;

		array.resize(size + 1);
		for(ll j = 1; j <= size; j++){
			array[j] = 0;
		}

		for(ll j = 0, left, right; j < size; j++){
			std::cin >> left >> right;

			update(left + 1, right + 1, 1);
		}

		ll curr = height * size;
		for(ll fill = 1; fill < height; fill++){
			curr -= query(fill);
		}
		for(ll fill = height; fill <= size; fill++){
			curr -= query(fill);
			res[i] = std::min(res[i], curr);
			curr += query(fill - height + 1);
		}
	}

	for(ll i = 0; i < cases; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
