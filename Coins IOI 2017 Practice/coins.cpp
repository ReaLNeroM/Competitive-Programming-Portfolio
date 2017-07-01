#include "coins.h"

std::vector<int> coin_flips(std::vector<int> b, int c) {
    int summer = 0;
    for(int i = 0; i < b.size(); i++){
        if(b[i]){
            summer ^= i;
        }
    }

    for(int i = 0; i < b.size(); i++){
    	if((summer ^ i) == c){
    		return {i};
    	}
    }
}

int find_coin(std::vector<int> b) {
    int pos = 0;
    for(int i = 0; i < 64; i++){
        if(b[i]){
            pos ^= i;
        }
    }

    return pos;
}
