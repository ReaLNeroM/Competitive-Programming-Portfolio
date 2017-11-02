#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	std::multiset<int> s;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	for(int i = 0; i < k; i++){
		s.insert(val[i]);
	}

	int res = 0;
	for(int i = 0; i < n - 1; i++){
		if(i + k < n){
			s.insert(val[i + k]);
		}
		s.erase(s.find(val[i]));

		if(*s.begin() < val[i]){
			for(int j = i + k; j > i; j--){
				if(val[j] == *s.begin()){
					std::swap(val[i], val[j]);
				}
			}
			break;
		}
	}

	for(int i = 0; i < n; i++){
		std::cout << val[i] << ' ';
	}
	std::cout << std::endl;
}