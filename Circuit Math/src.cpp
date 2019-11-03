#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 30;
int input[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		char c;
		std::cin >> c;

		input[i] = (c == 'T');
	}

	std::string s;
	std::getline(std::cin, s);
	std::getline(std::cin, s);

	std::stack<int> st;
	for(int i = 0; i < s.size(); i++){
		char c = s[i];

		if(c == ' '){
			continue;
		} else if(c == '*'){
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(a & b);
		} else if(c == '+'){
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(a | b);
		} else if(c == '-'){
			int a = st.top();
			st.pop();
			st.push(!a);
		} else {
			int index = c - 'A';
			st.push(input[index]);
		}
	}

	std::cout << ((st.top() == 1) ? 'T' : 'F') << '\n';
}