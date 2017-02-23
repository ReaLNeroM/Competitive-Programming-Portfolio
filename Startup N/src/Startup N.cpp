#include <iostream>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	int mat[n];
	for(int i = 0; i < n; i++){
		std::cin >> mat[i];
	}

	int minprefix[n], start = 0;
	minprefix[0] = 0;
	for(int i = 1; i < n; i++){
		start += mat[i - 1];
		minprefix[i] = std::min(minprefix[i - 1], start);
	}

	int suffix[n + 1];
	suffix[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		suffix[i] = suffix[i + 1] + mat[i];
	}

	int minprefixofnth[n + 1];
	minprefixofnth[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		minprefixofnth[i] = std::min(minprefixofnth[i + 1], 0) + mat[i];
	}

	int res = 0;
	for(int i = 0; i < n; i++){
		if(minprefixofnth[i] >= 0 and suffix[i] + minprefix[i] >= 0){
			res++;
		}
	}

	std::cout << res;
	return 0;
}
