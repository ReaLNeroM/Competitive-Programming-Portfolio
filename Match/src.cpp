#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int n;
std::string s;
std::string assigned;

bool works(){
	std::stack<char> sc;

	for(int i = 0; i < n; i++){
		if(assigned[i] == '('){
			sc.push(s[i]);
		} else if(assigned[i] == ')'){
			if(sc.empty() or sc.top() != s[i]){
				return false;
			}

			sc.pop();
		} else if(!sc.empty() and sc.top() == s[i]){
			sc.pop();
		} else {
			sc.push(s[i]);
		}
	}

	return sc.empty();
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> s;
	n = s.size();
	assigned = std::string(n, '0');

	for(int i = 0; i < n; i++){
		assigned[i] = '(';
		if(!works()){
			assigned[i] = ')';
		}
	}

	if(!works()){
		std::cout << -1 << '\n';
		return 0;
	}

	std::cout << assigned << '\n';
}