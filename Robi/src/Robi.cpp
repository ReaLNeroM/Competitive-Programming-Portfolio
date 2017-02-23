#include <iostream>
#include <cmath>

typedef long long ll;

int abs(int x){
	if(x < 0){
		return -x;
	}

	return x;
}

int main() {
	int x, y;
	std::cin >> x >> y;

	int points;
	std::cin >> points;

	int px[points], py[points];
	for(int i = 0; i < points; i++){
		std::cin >> px[i] >> py[i];
		px[i]--, py[i]--;
	}

	int confused = 0;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			int min = x * y, times = 0;
			for(int k = 0; k < points; k++){
				int check = px[k] - i + py[k] - j;
				if(check < min){
					min = check;
					times = 1;
				} else if(check == min){
					times++;
				}
			}

			if(times > 1){
				confused++;
			}
		}
	}

	std::cout << confused;
	return 0;
}
