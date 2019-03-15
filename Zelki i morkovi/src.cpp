#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	int sum_a = 0, sum_b = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		std::cin >> a >> b;
		sum_a += a;
		sum_b += b;
	}

	if(sum_a > sum_b){
		std::cout << "zelka\n";
		std::cout << sum_a;
	} else {
		std::cout << "morkov\n";
		std::cout << sum_b;
	}
}