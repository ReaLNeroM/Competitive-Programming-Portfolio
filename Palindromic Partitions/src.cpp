#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;
int main(){
	std::ios::sync_with_stdio(false);
	
	int t;
	std::cin >> t;
	
	for(int test = 0; test < t; test++){
		std::string s;
		std::cin >> s;
		int n = s.size();
		
		int res = 1;
		
		ll ahash = 0;
		ll bhash = 0;
		ll apow = 1;
		ll bpow = 0;
		
		for(int i = 0; i < n; i++){
			bool change = false;
			
			ahash = 0;
			bhash = 0;
			apow = 1;
			bpow = 0;
			
			for(int size = 1; i + size < n; size++){
				ahash += (s[i + size - 1] - 'a' + 1) * apow;
				ahash %= mod;
				int j = n - size;
				bhash *= 31;
				bhash += (s[j] - 'a' + 1);
				bhash %= mod;
			
				if(i + size <= j and ahash == bhash){
					res += 2;
					n -= size;
					i += size - 1;
					if(i + 1 == n){
						res--;
					}
					change = true;
					break;
				}
				
				apow *= 31;
				apow %= mod;
				bpow *= 31;
				bpow++;
				bpow %= mod;
			}
			
			if(!change){
				break;
			}
		}
		
		std::cout << res << std::endl;
	}
}
