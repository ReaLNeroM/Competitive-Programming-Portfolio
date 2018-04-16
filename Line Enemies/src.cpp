#include <bits/stdc++.h>

typedef long long ll;

std::multiset<int> below, above;

bool check(int type, int s1, int s2, int g1, int g2){
	if(type == 0){
		if(s1 == g1 and s2 == g2){
			return true;
		}

		return false;
	} else if(type == 1){
		if(g2 < s1 or s2 < g1){
			return true;
		}
		return false;
	} else if(type == 2){
		int l = std::min(s1, g1);
		int r = std::max(s2, g2);

		if(above.lower_bound(r + 1) != above.end()){
			return true;
		}
		if(below.lower_bound(-(l - 1)) != below.end()){
			return true;
		}

		return false;
	} else if(type == 3){
		if(s1 <= g1 and g1 <= s2 and s2 <= g2){
			auto ite = above.lower_bound(s2 + 1);
			if(ite == above.end()){
				return false;
			}
			ite = below.lower_bound(-(g1 - 1));
			if(ite == below.end()){
				return false;
			}

			return true;
		} else if(g1 <= s1 and s1 <= g2 and g2 <= s2){
			auto ite = below.lower_bound(-(s1 - 1));
			if(ite == below.end()){
				return false;
			}
			ite = above.lower_bound(g2 + 1);
			if(ite == above.end()){
				return false;
			}

			return true;
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);
    
    int q;
    std::cin >> q;

    for(int i = 0; i < q; i++){
    	int t;
    	std::cin >> t;

    	if(t == 1){
    		int l, r;
    		std::cin >> l >> r;
    		below.insert(-r);
    		above.insert(l);
    	} else if(t == 2){
    		int l, r;
    		std::cin >> l >> r;
    		below.erase(below.find(-r));
    		above.erase(above.find(l));
    	} else if(t == 3){
    		int s1, s2, g1, g2;
    		std::cin >> s1 >> s2 >> g1 >> g2;

    		bool printed = false;
    		for(int i = 0; i <= 3; i++){
    			if(check(i, s1, s2, g1, g2)){
    				std::cout << i << '\n';
    				printed = true;
    				break;
    			}
    		}

    		if(!printed){
    			std::cout << -1 << '\n';
    		}
    	}
    }
}