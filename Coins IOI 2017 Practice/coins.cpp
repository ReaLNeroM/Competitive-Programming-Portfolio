#include "coins.h"
#include <iostream>

std::vector<int> coin_flips(std::vector<int> b, int c) {
    std::vector<int> flips;
    for(int i = 0; i < b.size(); i++){
        int summer = 0;
        for(int j = 0; j < b.size(); j++){
            summer *= 541;
            if((b[j] and i != j) or (!b[j] and i == j)){
                summer += (j + 16) / 16;
            }
            summer %= 64;
        }

        if(summer == c){
            flips.push_back(i);
            return flips;
        }
    }
}

int find_coin(std::vector<int> b) {
    int pos = 0;
    for(int i = 0; i < 64; i++){
        pos *= 541;
        pos += (i + 16) / 16 * b[i];
        pos %= 64;
    }

    return pos;
}
