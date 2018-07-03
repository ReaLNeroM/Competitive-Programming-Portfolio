#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
std::string s;
std::vector<std::string> v;
int n;
bool possible = true;

std::string minimal_fill(std::string number){
	if(number[0] == '?'){
		number[0] = '1';
	}

	for(int i = 1; i < number.size(); i++){
		if(number[i] == '?'){
			number[i] = '0';
		}
	}

	return number;
}

std::string maximal_fill(std::string number){
	for(int i = 0; i < number.size(); i++){
		if(number[i] == '?'){
			number[i] = '9';
		}
	}

	return number;
}

std::string next_fill(std::string number, std::string lower_bound){
	for(int i = 0; i < number.size(); i++){
		if(number[i] == '?'){
			for(char j = '0'; j <= '9'; j++){
				if(j == '0' and i == 0){
					continue;
				}

				number[i] = j;
				if(lower_bound < maximal_fill(number)){
					break;
				}

				if(j == '9'){
					return "impossible";
				}
			}
		}
	}

	return number;
}

std::string solve(std::string s){
	n = s.size();

	v.clear();

	std::string part = "";
	for(int i = 0; i <= n; i++){
		if(i == n or s[i] == ','){
			if(part == ""){
				return "impossible";
			}

			v.push_back(part);
			part = "";
		} else {
			part += s[i];
		}
	}

	possible = true;

	if(v[0].size() == 0){
		return "impossible";
	}

	int numbers = v.size();
	v[0] = minimal_fill(v[0]);

	for(int i = 1; i < numbers; i++){
		if(v[i].size() > v[i - 1].size()){
			v[i] = minimal_fill(v[i]);
		} else if(v[i].size() == v[i - 1].size()){
			v[i] = next_fill(v[i], v[i - 1]);
		} else {
			return "impossible";
		}
	}

	for(int i = 0; i < numbers; i++){
		if(v[i][0] == '0'){
			return "impossible";
		}
	}

	for(int i = 1; i < numbers; i++){
		if(v[i - 1].size() < v[i].size()){
			continue;
		} else if(v[i - 1].size() == v[i].size() and v[i - 1] < v[i]){
			continue;
		} else {
			return "impossible";
		}
	}

	std::string ret = "impossible";

	if(possible){
		ret = "";
		for(int i = 0; i < numbers; i++){
			ret += v[i];
			if(i + 1 != numbers){
				ret += ',';
			}
		}
	}

	return ret;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> s;
	n = s.size();

	std::string res = "impossible";

	res = solve(s);

	for(int i = 0; i < n; i++){
		if(s[i] == '?'){
			s[i] = ',';
			std::string attempt = solve(s);
			if(attempt != "impossible"){
				res = std::min(res, attempt);
				continue;
			} else {
				s[i] = '?';
			}
		}
	}


	std::cout << res << '\n';
}
