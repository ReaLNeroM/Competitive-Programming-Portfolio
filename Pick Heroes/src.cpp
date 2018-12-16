#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e3 + 1e2;
int val[maxn];
int a[maxn], b[maxn];
std::map<int, int> heroPairMap;
bool used[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int heroes, heroPairs;
	std::cin >> heroes >> heroPairs;

	for(int i = 1; i <= 2 * heroes; i++){
		std::cin >> val[i];
	}

	for(int i = 0; i < heroPairs; i++){
		std::cin >> a[i] >> b[i];
		heroPairMap[a[i]] = b[i];
		heroPairMap[b[i]] = a[i];
	}

	int t;
	std::cin >> t;

	if(t == 2){
		int response;

		while(std::cin >> response) {
			used[response] = true;

			if(heroPairMap.find(response) != heroPairMap.end()){
				std::cout << heroPairMap[response] << std::endl;
				used[heroPairMap[response]] = true;
			} else {
				break;
			}
		}
	}

	for(int i = 0; i < heroPairs; i++){
		if(used[a[i]] or used[b[i]]){
			continue;
		}

		if(val[a[i]] >= val[b[i]]){
			std::cout << a[i] << std::endl;
		} else {
			std::cout << b[i] << std::endl;
		}

		int response;
		std::cin >> response;
		
		used[a[i]] = true;
		used[b[i]] = true;
	}

	for(int i = 0; i < 2 * heroes; i++){
		int best = -1;
		for(int j = 1; j <= 2 * heroes; j++){
			if(!used[j] and (best == -1 or val[best] < val[j])){
				best = j;
			}
		}

		if(best == -1){
			break;
		}

		std::cout << best << std::endl;
		used[best] = true;
		int response;
		std::cin >> response;
		used[response] = true;
	}
}