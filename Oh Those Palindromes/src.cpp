#include <bits/stdc++.h>

typedef long long ll;

const int alpha = 26;
char set[alpha];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::string s;
	std::cin >> n >> s;

	std::sort(s.begin(), s.end());

	std::cout << s << '\n';

}