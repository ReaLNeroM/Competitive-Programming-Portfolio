#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int p1[maxn];
int p2[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	std::string s;

	while(std::cin >> s){
		std::fill(p1, p1 + s.size(), 0);
		std::fill(p2, p2 + s.size(), 0);

		int res = s.size();
		int best_pos = 0;

		int n = s.size();
		
		int l = 0, r = -1;

		for(int i = 0; i < s.size(); i++){
			if(r < i){
				p1[i] = 0;
			} else {
				p1[i] = std::min(p1[l + r - i], r - i);
			}

			while(0 < i - p1[i] and i + p1[i] < n - 1 and s[i - p1[i] - 1] == s[i + p1[i] + 1]){
				p1[i]++;
			}

			if(r < i + p1[i]){
				l = i - p1[i];
				r = i + p1[i];
			}

			if(r == n - 1){
				res = l;
				break;
			}
		}

		l = 0, r = -1;

		for(int i = 0; i < s.size(); i++){
			if(r < i){
				p2[i] = -1;
			} else {
				p2[i] = std::min(p2[l + r - i], r - i);
			}

			while(0 < i - p2[i] - 1 and i + p2[i] < n - 1 and s[i - p2[i] - 2] == s[i + p2[i] + 1]){
				p2[i]++;
			}

			if(r < i + p2[i]){
				l = i - p2[i] - 1;
				r = i + p2[i];
			}

			if(r == n - 1 and l < res){
				res = std::min(res, l);
			}
		}

		std::cout << s;

		for(int i = res - 1; i >= 0; i--){
			std::cout << s[i];
		}
		std::cout << '\n';
	}
}
