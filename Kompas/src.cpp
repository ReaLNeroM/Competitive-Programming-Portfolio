#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 360;
int znae[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	for(int i = 0; i < n; i++){
		int agol;
		std::cin >> agol;
		znae[agol] = true;
	}

	for(int i = 0; i < 360; i++){
		for(int j = 0; j < 360; j++){
			for(int k = 0; k < 360; k++){
				if(znae[j] and znae[k]){
					znae[(j + k) % 360] = true;
					if(j - k > 0){
						znae[j - k] = true;
					}
					if(k - j > 0){
						znae[k - j] = true;
					}
				}
			}
		}
	}

	for(int i = 0; i < k; i++){
		int agol;
		std::cin >> agol;

		if(znae[agol]){
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}

}