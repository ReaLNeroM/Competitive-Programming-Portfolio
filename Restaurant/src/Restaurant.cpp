#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	int orders;
	std::cin >> orders;

	std::pair<int, int> o[orders];
	for(int i = 0; i < orders; i++){
		std::cin >> o[i].first >> o[i].second;
	}

	std::sort(o, o + orders);

	int secondlast = 0, last = o[0].second, taken = 1;
	for(int i = 1; i < orders; i++){
		if(last < o[i].first){
			secondlast = last;
			last = o[i].second;
			taken++;
		} else if(last > o[i].second and secondlast < o[i].first){
			last = o[i].second;
		}
	}

	std::cout << taken;
	return 0;
}
