#include <iostream>
#include <list>

int main() {
    int a, b;
    std::string h;
    std::cin >> a >> b >> h;
    if(a > b){
    	std::swap(a, b);
    }

    int u = 0, d = 0;
    for(int i = a; i < b; i++){
    	if(h[i] == 'U'){
    		u++;
    	} else {
    		if(u > 0){
    			u--;
    		} else{
    			d++;
    		}
    	}
    }

    std::cout << u + d;
    return 0;
}
