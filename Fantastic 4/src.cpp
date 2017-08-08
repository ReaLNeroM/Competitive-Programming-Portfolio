#include <bits/stdc++.h>

typedef long long ll;

int main(){
    std::ios::sync_with_stdio(false);
    
	std::vector<ll> v(4);    

	std::cin >> v[0] >> v[1] >> v[2] >> v[3];	
    
	ll most = 0;

    for(ll i = 3; i < 4; i++){
    	auto v2 = v;
    	std::swap(v2[i], v2[0]);

        for(ll j = 1; j < 4; j++){
        	if(v2[j] < v2[1]){
        		std::swap(v2[j], v2[1]);
        	}
        }

        std::cerr << v2[0] << ' ' << v2[1] << ' ' << v2[2] << ' ' << v2[3] << std::endl;
        v2[0] += v2[1] * 2;
        v2[2] -= v2[1];
        v2[3] -= v2[1];
        v2[1] -= v2[1];
        std::cerr << v2[0] << ' ' << v2[1] << ' ' << v2[2] << ' ' << v2[3] << std::endl;

        ll x = std::min(v2[2], v2[3]) / 3;

        v2[0] += x * 3;
        v2[1] += x * 2 - x * 2;
        v2[2] -= x * 3;
        v2[3] -= x * 3;
        std::cerr << v2[0] << ' ' << v2[1] << ' ' << v2[2] << ' ' << v2[3] << std::endl;
        
        if(std::min(v2[2], v2[3]) == 2){
        	v2[0]++;
        	v2[1]++;
        	v2[2] -= 2;
        	v2[3] -= 2;
        } 
        std::cerr << v2[0] << ' ' << v2[1] << ' ' << v2[2] << ' ' << v2[3] << std::endl;

    	most = std::max(most, v2[0]);
    }
    
	std::cout << most << std::endl;
}