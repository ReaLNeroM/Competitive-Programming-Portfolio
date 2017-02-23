#include <iostream>

typedef long long ll;

int main() {
	ll start, end;
	std::cin >> start >> end;

	ll changes = 0;
	if(start * 2 > end){
		changes = (end - start) / 2 + (end - start) % 2;
	} else {
		if(start == 1 and end > 2){
			start += 2;
			changes++;
		}
		while(start != end){
			if(start * 2 <= end and end % 2 != 1){
				end /= 2;
			} else {
				end -= 1;
			}

			changes++;
		}
	}

	std::cout << changes;
	return 0;
}
