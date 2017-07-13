#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int v[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}

	int state = 0;
	for(int i = 0; i < n - 1; i++){
		if(v[i] < v[i + 1] and state == 0){
		} else if(v[i] == v[i + 1] and state != 2){
			state = 1;
		} else if(v[i] > v[i + 1]){
			state = 2;
		} else {
			std::cout << "NO";
			return 0;
		}
	}

	std::cout << "YES";
}