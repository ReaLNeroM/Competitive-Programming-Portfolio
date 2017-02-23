#include <iostream>
#include <algorithm>
#include <functional>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	ll size;
	cin >> size;

	ll v[size];
	for(ll i = 0; i < size; i++){
		cin >> v[i];
	}

	sort(v, v + size, greater<ll>());

	ll used = 0;
	for(ll i = 0; i < size; i++){
		used += v[i];

		while(i != size - 1 and v[i] <= v[i + 1] and v[i + 1] != 0){
			v[i + 1]--;
		}
	}

	cout << used;
	return 0;
}
