#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
int v[maxn];

int main(){
	int test_cases;
	std::cin >> test_cases;

	for(int test_case = 1; test_case <= test_cases; test_case++){
		int n;
		std::cin >> n;

		for(int i = 0; i < n; i++){
			std::cin >> v[i];
		}

		int res = 0;
		int curr = 0;

		for(int j = 0; j < n; j++){
			if(v[j] > curr){
				res += v[j] - curr;
			}

			curr = v[j];
		}

		std::cout << "Case #" << test_case << ": " << res << '\n';
	}
}