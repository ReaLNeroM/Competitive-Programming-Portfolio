#include <iostream>

typedef long long ll;

ll Acker(int m, int n){
	if(m == 0){
		return n + 1;
	} else if(n == 0){
		return Acker(m - 1, 1);
	} else {
		return Acker(m - 1, Acker(m, n - 1));
	}
}

int main() {
	int x;
	std::cin >> x;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			std::cout << Acker(i, j) << " ";
			std::cout.flush();
		}
		std::cout << std::endl;
	}

	return 0;
}
