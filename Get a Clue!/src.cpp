#include <bits/stdc++.h>

typedef long long ll;

int ans[50][20];
int yours[5];
std::set<int> found[3];

bool good(int a, int b, int c){
	
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	for(int i = 0; i < 5; i++){
		char val;
		std::cin >> val

		yours[i] = val - 'A';
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			char val;
			std::cin >> val;

			if(j <= 2){
				ans[i][j] = val - 'A';
			} else {
				if(val[i][j] == '-'){
					ans[i][j] = -1;
				} else if(val[i][j] == '*'){
					ans[i][j] = -2;
					break;
				} else {
					ans[i][j] = val - 'A';
				}
			}
		}
	}

	for(int i = 0; i < 6; i++){
		for(int j = 6; j < 12; j++){
			for(int k = 12; k < 21; k++){
				if(good(i, j, k)){
					found[0].insert(i);
					found[1].insert(j);
					found[2].insert(k);
				}
			}
		}
	}

	for(int i = 0; i < 3; i++){
		if(found[i].size() != 1){
			std::cout << '?';
		} else {
			std::cout << (char) ('A' + *found[i].begin());
		}
	}
}