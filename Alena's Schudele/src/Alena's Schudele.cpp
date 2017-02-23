#include <iostream>

typedef long long ll;

int main() {
	int lessons;
	std::cin >> lessons;

	int l[lessons];
	for(int i = 0; i < lessons; i++){
		std::cin >> l[i];
	}

	int needtogo = 0;
	for(int i = 0; i < lessons; i++){
		if(l[i] == 1){
			needtogo++;
		} else if(needtogo > 0 and l[i] == 0){

			if(i != lessons - 1 and l[i + 1] == 1){
				needtogo++;
			}

			while(i != lessons - 1 and l[i + 1] == 0){
				i++;
			}
		}
	}

	std::cout << needtogo;
	return 0;
}
