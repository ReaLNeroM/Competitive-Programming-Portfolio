#include <bits/stdc++.h>

typedef long long ll;

int n;
std::set<int> s[2];

int main(){
	std::ios::sync_with_stdio(false);

	std::string str;
	std::cin >> str;

	n = str.size();

	s[0].insert(n);
	s[1].insert(n);
	for(int i = 0; i < n; i++){
		if(str[i] == '0'){
			s[0].insert(i);
		} else {
			s[1].insert(i);
		}
	}

	std::vector<std::vector<int>> res;

	bool possible = true;

	for(int i = 0; i < n; i++){
		std::vector<int> curr;

		int pos = i;

		if(str[i] == '1'){
			possible = false;
		} else if(str[i] == 'x'){
			continue;
		}

		while(pos != n){
			curr.push_back(pos);
			int next;

			if(str[pos] == '0'){
				s[0].erase(pos);
				next = *s[1].lower_bound(pos);
				int next_next = *s[0].lower_bound(next);

				str[pos] = 'x';
				if(next_next == n){
					break;
				}
			} else {
				s[1].erase(pos);
				next = *s[0].lower_bound(pos);

				str[pos] = 'x';
			}

			pos = next;
		}

		res.push_back(curr);
	}

	if(!possible){
		std::cout << -1 << '\n';
		return 0;
	}

	std::cout << res.size() << '\n';
	for(auto& i : res){
		std::cout << i.size() << ' ';
		for(auto j : i){
			std::cout << j + 1 << ' ';
		}
		std::cout << '\n';
	}
}