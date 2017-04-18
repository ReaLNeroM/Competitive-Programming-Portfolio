#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int found[26];

int main(){
	std::ios::sync_with_stdio(false);

	std::string s;
	std::cin >> s;

	for(int i = 0; i < s.size(); i++){
		found[s[i] - 'a']++;
	}

	int s_to_push = 0;

	std::string resulting = "";
	std::stack<char> stack;

	for(int i = 0; i < 26; i++){
		while(!stack.empty() and stack.top() <= (char) ('a' + i)){
			resulting += stack.top();
			stack.pop();
		}
		while(found[i] > 0){
			stack.push(s[s_to_push]);
			while(!stack.empty() and stack.top() <= (char) ('a' + i)){
				resulting += stack.top();
				stack.pop();
			}
			found[s[s_to_push] - 'a']--;
			s_to_push++;
		}
	}

	while(!stack.empty()){
		resulting += stack.top();
		stack.pop();
	}


	std::cout << resulting << std::endl;
}