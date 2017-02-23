#include <iostream>
#include <vector>

typedef long long ll;

std::vector<ll> height;

class BIT{
	std::vector<ll> val;
public:
	ll check(ll a, ll b){
		ll res = 0;
		while(b > 0){
			res += val[b];
			b -= b & (-b);
		}
		while(a > 0){
			res -= val[a];
			a -= a & (-a);
		}

		return res;
	}
	void update(ll a, ll x){
		while(a < val.size()){
			val[a] += x;
			a += a & (-a);
		}
	}
	ll process(ll a, ll b, ll c){
		ll res = 0;


		return res;
	}
	void resize(ll size){
		val.resize(size, 0);
	}
};
int main() {
	ll palms, queries;
	std::cin >> palms >> queries;

	BIT tree;
	tree.resize(palms);
	height.resize(palms);

	bool found = false, increasing = true;
	for(ll i = 0; i < palms; i++){
		std::cin >> height[i];
		if(!found and i > 0){
			if(height[i] > height[i - 1]){
				found = true;
				increasing = false;
				tree.update(i, 1);
			} else if(height[i] < height[i - 1]){
				found = true;
				increasing = true;
				tree.update(i, 1);
			}
		} else if(found){
			if(increasing and height[i] > height[i - 1]){
				increasing = false;
				tree.update(i, 1);
			} else if(!increasing and height[i] < height[i - 1]){
				increasing = true;
				tree.update(i, 1);
			}
		}
	}

	ll cases = 0, res[queries];

	for(ll test = 0; test < queries; test++){
		std::string command;
		ll a, b;
		std::cin >> command >> a >> b;

		if(command == "REPLACE"){
			if(a > 0){

			}
			if(a < palms){

			}
		} else {
			res[cases] = tree.check(b, a);
			cases++;
		}
	}

	for(ll i = 0; i < cases; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
