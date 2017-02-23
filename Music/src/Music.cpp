#include <iostream>

typedef long long ll;

int main() {
	ll duration, downloaded, speed;

	std::cin >> duration >> downloaded >> speed;

	ll playbackpos = 0, rewinded = 0;

	double dled = downloaded;

	for(ll i = 0; playbackpos < duration; i++){
		playbackpos++;
		dled += ((double) speed - 1) / speed;

		if((double) playbackpos - dled > 0.00000001){
			playbackpos = 1;
			rewinded++;
		}
	}

	std::cout << rewinded + 1;
	return 0;
}
