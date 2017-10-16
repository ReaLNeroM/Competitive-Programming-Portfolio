#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
std::string s[maxn];
bool tagged[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	
	int t;
	std::cin >> t;

	for(int x = 0; x < t; x++){
		int n, k;
		std::cin >> n >> k;
		
		for(int i = 0; i < n; i++){
			std::cin >> s[i];
			tagged[i] = false;
		}

		ll nl = n, kl = k;

		ll first = nl * nl * kl / 2;
		ll second = nl * kl * kl * 20 + nl * 20;

		if(first < 30000000){
			for(int i = 0; i < n; i++){
				for(int j = i + 1; j < n; j++){
					int diff = 0;

					for(int k = 0; k < k; k++){
						if(s[i][k] != s[j][k]){
							diff++;
						}
					}

					if(diff <= 2){
						tagged[i] = true;
						tagged[j] = true;
					}

					found = true;
				}

				if(tagged[i]){
					std::cout << '1';
				} else {
					std::cout << '0';
				}
			}
		} else {
			std::set<ll> st;

			for(int i = 0; i < n; i++){
				for(int j = 0; j < k; j++){
					char prev = s[j];

					for(char l = 'a'; l <= 'z'; l++){
						s[j] = l;
					}

					s[j] = prev;
				}
			}
		}

		std::cout << '\n';
	}
}