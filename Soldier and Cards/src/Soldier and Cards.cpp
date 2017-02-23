#include <iostream>
#include <deque>

typedef long long ll;

int main() {
	int cards;
	std::cin >> cards;

	std::deque<ll> first, second;

	int fsize;
	std::cin >> fsize;
	for(ll i = 0, inp; i < fsize; i++){
		std::cin >> inp;
		first.push_front(inp);
	}

	int ssize;
	std::cin >> ssize;
	for(ll i = 0, inp; i < ssize; i++){
		std::cin >> inp;
		second.push_front(inp);
	}

	ll i;
	for(i = 0; i <= 3628800 and !first.empty() and !second.empty(); i++){
		if(first.back() > second.back()){
			first.push_front(second.back());
			second.pop_back();
			first.push_front(first.back());
			first.pop_back();
		} else {
			second.push_front(first.back());
			first.pop_back();
			second.push_front(second.back());
			second.pop_back();
		}
	}

	if(i <= 3628800){
		std::cout << i << " ";
		if(first.empty()){
			std::cout << 2;
		} else {
			std::cout << 1;
		}
	} else {
		std::cout << -1;
	}
	return 0;
}
