#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct order{
	ll price, volume;
	char direction;

	bool operator<(const order &x) const{
		if(direction == 'S'){
			return price < x.price;
		} else {
			return price > x.price;
		}
	}
} copy;

int main() {
	ll orders, length;
	std::cin >> orders >> length;

	std::vector<order> buy, sell;
	for(ll i = 0; i < orders; i++){
		std::cin >> copy.direction >> copy.price >> copy.volume;

		if(copy.direction == 'S'){
			sell.push_back(copy);
		} else{
			buy.push_back(copy);
		}
	}


	if(!sell.empty()){
		std::sort(sell.begin(), sell.end());
		for(ll i = 0; i < sell.size() - 1; i++){
			if(sell[i].price == sell[i + 1].price){
				sell[i].volume += sell[i + 1].volume;
				sell.erase(sell.begin() + i + 1);
				i--;
			}
		}
		for(ll i = std::min((ll) sell.size() - 1, length - 1); i >= 0; i--){
			std::cout << 'S' << " " << sell[i].price << " " << sell[i].volume << std::endl;
		}
	}

	if(!buy.empty()){
		std::sort(buy.begin(), buy.end());
		for(ll i = 0; i < buy.size() - 1; i++){
			if(buy[i].price == buy[i + 1].price){
				buy[i].volume += buy[i + 1].volume;
				buy.erase(buy.begin() + i + 1);
				i--;
			}
		}
		for(ll i = 0; i < buy.size() and i < length; i++){
			std::cout << 'B' << " " << buy[i].price << " " << buy[i].volume << std::endl;
		}
	}
	return 0;
}
