#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	std::string a, b, c;
	std::cin >> a >> b >> c;

	for(int i = 0; i < c.size(); i++){
		if('A' <= c[i] and c[i] <= 'Z'){
			for(int j = 0; j < a.size(); j++){
				if(c[i] + ('a' - 'A') == a[j]){
					std::cout << (char) (b[j] + ('A' - 'a'));
				}
			}			
		} else if('a' <= c[i] and c[i] <= 'z'){
			for(int j = 0; j < a.size(); j++){
				if(c[i] == a[j]){
					std::cout << b[j];
				}
			}
		} else {
			std::cout << c[i];
		}
	}
}