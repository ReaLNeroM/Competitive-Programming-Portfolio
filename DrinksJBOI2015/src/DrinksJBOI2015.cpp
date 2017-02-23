#include <iostream>
#include <vector>

typedef long long ll;

ll packages;
ll happiness[100][2];
ll happydiff;
std::vector<ll> best1, best2;
std::vector<ll> first, second;

void combine(ll pos, ll happy1, ll happy2){
	if(pos == packages){
		if(std::max(happy1, happy2) - std::min(happy1, happy2) < happydiff){
			happydiff = std::max(happy1, happy2) - std::min(happy1, happy2);
			best1 = first, best2 = second;
		}
	} else {
		if(first.size() < packages / 2){
			first.push_back(pos);
			combine(pos + 1, happy1 + happiness[pos][0], happy2);
			first.pop_back();
		}
		if(second.size() < packages / 2){
			second.push_back(pos);
			combine(pos + 1, happy1, happy2 + happiness[pos][1]);
			second.pop_back();
		}
	}
}
int main() {
	std::cin >> packages;

	for(ll i = 0; i < packages; i++){
		std::cin >> happiness[i][0] >> happiness[i][1];
	}

	happydiff = 100000000000000000;

	combine(0, 0, 0);

	std::cout << happydiff << std::endl;
	for(ll i = 0; i < best1.size(); i++){
		std::cout << best1[i] + 1 << " ";
	}
	std::cout << std::endl;
	for(ll i = 0; i < best2.size(); i++){
		std::cout << best2[i] + 1 << " ";
	}
	return 0;
}
