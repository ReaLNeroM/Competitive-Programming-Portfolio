#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	bool same = true;

	for(int i = 0; i + 1 < n; i++){
		if(s[i] != s[i + 1]){
			same = false;
		}
	}

	if(same){
		std::cout << "0 0\n";
		return 0;
	}

	ll res = 1e18;
	for(int side = 0; side < 2; side++){
		for(char& i : s){
			if(i == 'L'){
				i = 'R';
			} else if(i == 'R'){
				i = 'L';
			}
		}

		ll attempt = 0;

		std::deque<int> left, right;

		for(int i = 0; i < n; i++){
			if(s[i] == chase){
				attempt += (i + 1 - (int) right.size());
				right.push_back(i);
			}
		}

		int size = right.size();
		for(int i = 0; i + right.size <= n; i++){
			//try to swap into left
			res = std::min(res, attempt);

			//change this from right into left pos

			//do maths
		}
	}

	std::cout << res;
}