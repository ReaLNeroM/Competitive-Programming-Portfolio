#include <iostream>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	bool vert[n], hor[n];
	for(int i = 0; i < n; i++){
		vert[i] = hor[i] = false;
	}

	int res[n * n];
	for(int i = 0, x, y; i < n * n; i++){
		res[i] = false;
		std::cin >> x >> y;
		x--, y--;
		if(!hor[x] and !vert[y]){
			hor[x] = vert[y] = true;
			res[i] = true;
		}
	}

	for(int i = 0; i < n * n; i++){
		if(res[i]){
			std::cout << i + 1 << ' ';
		}
	}
	return 0;
}
