#include <bits/stdc++.h>
 
typedef long long ll;

ll f_brute(ll b){
    ll res = 0;
    for(ll a = b / 2 + 1; a <= b; a++){
        if((b * a) % (2 * a - b) == 0){
            res += 2;
            // std::cout << a << ' ' << (b * a) / (2 * a - b) << std::endl;
        }
    }
 
    res--; // a == c leads to overcounting

    return res;
}

ll f_smart(ll b){
	if(b == 2){
		return 1;
	} else if(b == 4){
		return 3;
	}
 	
 	if(b % 2 == 0){
 		ll residue = b;

 		residue /= 2;

 		ll factors = 1;

 		for(int i = 2; i * i <= residue; i++){
 			ll pow = 0;
 			while(residue % i == 0){
 				pow++;
 				residue /= i;
 			}

 			if(pow){
 				factors *= (2 * pow) + 1;
 			}
  		}

  		if(residue > 1){
  			factors *= 3;
  		}

  		return factors;
 	} else {
 		ll residue = b;

 		ll factors = 1;

 		for(int i = 2; i * i <= residue; i++){
 			ll pow = 0;

 			while(residue % i == 0){
 				pow++;
 				residue /= i;
 			}


	 		factors *= 2 * pow + 1;
  		}

  		if(residue != 1){
  			factors *= 3;
  		}

 		return factors;
 	}
}

int main(){
	std::ios::sync_with_stdio(false);
 
	ll b;	
	std::cin >> b;

	std::cout << f_smart(b) << std::endl;
}