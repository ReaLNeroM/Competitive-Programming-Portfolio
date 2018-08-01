#include <bits/stdc++.h>

std::vector<int> zfunction(int n, std::string& s){
	std::vector<int> res(n + 1);

	int curr_pos = 0;

	for(int i = 1; i < n; i++){
		while(curr_pos > 0 and s[i] != s[curr_pos])
			curr_pos = res[curr_pos - 1];

		if(s[i] == s[curr_pos])
			curr_pos++;

		res[i + 1] = curr_pos;
	}

	return res;
}

int main(){
	std::string s;
	std::cin >> s;

	int n = s.size();

	std::vector<int> table = zfunction(n, s);

	for(int i : table)
		std::cerr << i << ' ';
}