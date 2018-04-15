#include <bits/stdc++.h>

typedef long long ll;

int n;

bool within(int a, int l, int r){
	return l <= a and a <= r;
}

template <class T>
T dist(T a, T b){
	if(a > b){
		std::swap(a, b);
	}

	return std::min(b - a, a + n - b);
}

int main(){
	std::ios::sync_with_stdio(false);

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
	ll best_position = 0;
	ll attempt = 0;

	for(int side = 0; side < 2; side++){
		int l_count = std::count(s.begin(), s.end(), 'L');

		std::vector<int> crips, bloods;
		int 
		for(int i = 0; i < 2 * n; i++){
			if(s[i] == 'L'){
				if()
			}
		}
		//try to gather the Ls
		for(int i = l_count - 1; i < s.size(); i++){
			double position = (i + 1) / 2.0;
			//gather the fuckers here

			//check for changing sides
		}

		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'L'){
				s[i] = 'R';
			} else {
				s[i] = 'L';
			}
		}
	}

	std::cout << 1 << ' ' << res << '\n';
}
