#include <iostream>
#include <set>

typedef long long ll;

int main() {
	ll boardsize, ships, shipsize;
	std::cin >> boardsize >> ships >> shipsize;

	ll queries;
	std::cin >> queries;

	std::set<ll> setstart, setend;

	setstart.insert(-1), setend.insert(boardsize);

	ll res = -1, left = (boardsize - boardsize / shipsize) / shipsize;
	for(ll i = 0; i < queries; i++){
		ll inp;
		std::cin >> inp;

		if(res == -1){
			std::set<ll>::iterator ite = setstart.lower_bound(-inp);
			std::set<ll>::iterator ite2 = setend.lower_bound(inp);

			ll start = -(*ite);
			ll end = *ite2;
			setstart.erase(ite);
			setend.erase(ite2);

			ll difference = (end - start + ) / shipsize;

			setstart.insert(-start);
			setend.insert(inp - 1);
			difference -= (inp - 1 - start + 1 + 1) / shipsize;

			setstart.insert(-inp - 1);
			setend.insert(end);
			difference -= (end - inp + 1 + 1) / shipsize;

			left -= difference;

			if(left < ships){
				res = i + 1;
			}
		}
	}

	std::cout << res;
	return 0;
}
