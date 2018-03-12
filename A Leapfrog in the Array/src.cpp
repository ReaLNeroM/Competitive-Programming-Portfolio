#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n, q;
	std::cin >> n >> q;

	for(int i = 0; i < q; i++){
		int ind;
		std::cin >> ind;

		int jump = 2 * (n - ind) + 1;

		ind = 2 * ind - 1;

		while(ind - jump >= 1){
			ind -= jump;

			int after = (2 * n - 1 - ind) / 2;
			jump = 2 * after + 2;
		}

		std::cout << ind << '\n';
	}
}
