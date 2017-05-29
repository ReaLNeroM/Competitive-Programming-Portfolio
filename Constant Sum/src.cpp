#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
double val[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    int n, q;
    std::cin >> n >> q;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }

    double zero = 0.0;

    for(int i = 0; i < q; i++){
    	int type;
    	std::cin >> type;

    	if(type == 0){
    		int ind;
    		double increase;
    		std::cin >> ind >> increase;
    		ind--;

    		double small_increase = increase;
    		small_increase /= (double) (n - 1);
    		
    		val[ind] += increase + small_increase;
    		zero -= small_increase;
    	} else {
    		int ind;
    		std::cin >> ind;
    		ind--;
    		std::cout.precision(9);
    		std::cout << std::fixed << val[ind] + zero << '\n';
    	}
    }
}