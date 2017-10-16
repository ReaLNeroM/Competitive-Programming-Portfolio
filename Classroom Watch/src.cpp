#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::deque<int> v;

	for(int i = n; i >= 0 and n - i <= 100; i--){
		std::stringstream str;
		str << i;

		std::string res;
		str >> res;

		int get = i;
		for(char j : res){
			get += (char) (j - '0');
		}

		if(get == n){
			v.push_front(i);
		}
	}

	std::cout << v.size() << '\n';

	for(int i = 0; i < v.size(); i++){
		std::cout << v[i] << '\n';
	}
}