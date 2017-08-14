#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int pos[maxn];
int target[maxn];

int main(){
	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		val[i]--;
		target[i] = val[i];
		pos[val[i]] = i;
	}

	for(int i = 0; i < n; i++){
		if(pos[i] is not taken and pos[i] / 2 is not taken){

		}
		//check if good

	}

	for(int i = 0; i < n; i++){
		std::cout << target[i] + 1 << ' ';
	}
}