#include "coins.h"

std::vector<int> coin_flips(std::vector<int> b, int c) {
    std::vector<int> flips(0);
    for(int i = 1, ind = 0; i <= 63; i *= 2, ind++){
        if(c & i){
            if(!b[ind]){
                flips.push_back(ind);
            }
        } else {
            if(b[ind]){
                flips.push_back(ind);
            }
        }
    }

    if(flips.empty()){
        flips.push_back(63);
        flips.push_back(63);
    }
    return flips;
}

int find_coin(std::vector<int> b) {
    int pos = 0;
    for(int i = 1, ind = 0; i <= 63; i *= 2, ind++){
        if(b[ind]){
            pos += i;
        }
    }

    return pos;
}
