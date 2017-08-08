#include <bits/stdc++.h>

typedef long long ll;

int main(){
	int n, k;
	std::cin >> n >> k;

	int small = 0, big = 0;

	if(k == 2){
		std::cout << n - 1 << std::endl;
		for(int i = 1; i < n; i++){
			std::cout << i << ' ' << i + 1 << std::endl;
		}
		return 0;
	}

	std::vector<int> v;

	int sum = 0;
	for(int i = 0; i < n; i++){
		int x = i * k - (n - 1);
		int y = k - x;
		if(y < 0 or x < 0 or y * i + x * (i - 1) != n - 1 or y + x != k){
			continue;
		}

		for(int j = 0; j < y; j++){
			v.push_back(i);
		}
		for(int j = 0; j < x; j++){
			v.push_back(i - 1);
		}
		break;
	}

	std::cout << v[0] + v[1] << '\n';

	int curr_ind = 2;
	for(int i = 0; i < v.size(); i++){
		std::cout << 1 << ' ' << curr_ind << '\n';
		curr_ind++;
		for(int j = 2; j <= v[i]; j++){
			std::cout << curr_ind - 1 << ' ' << curr_ind << '\n';
			curr_ind++;
		}
	}
}