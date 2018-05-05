//============================================================================
// Name        : Veridba.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
 
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
 
int main() {
    long long a, b, clenovi;
    std::cin >> a >> b >> clenovi;
 
    if(a > b){
        std::swap(a, b);
    }
 
    int res = 3;

    for(long long i = 1; i * i <= clenovi; i++){
        long long other = clenovi / i;

        if(i * other == clenovi){
            if(i == a and other == b){
                res = std::min(res, 0);
            } else if((i == a and other <= b) or (i == b and other <= a) or (other == a and i <= b) or (other == b and i <= a)){
                res = std::min(res, 1);
            } else if(i <= a and other <= b){
                res = std::min(res, 2);
            }
        }
    }

    if(res == 3){
        res = -1;
    }

    std::cout << res << '\n';
    return 0;
}