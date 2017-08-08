#include "cup.h"

const int INF_bit = 536870912;

std::vector<int> find_cup() {
    int orig = ask_shahrasb(0, 0);
    int pos = 0;
    int neg = 0;
    for(int i = 1; i < INF_bit; i *= 2){
    	int curr = ask_shahrasb(i, 0);
    	if((curr ^ orig) == i){
    		pos += i;
    	} else {
    		neg += i;
    	}
    }

    int pos_q = orig ^ pos;
    int neg_q = orig ^ neg;

    int fp = ask_shahrasb(pos, pos_q);

    if(fp == 0){
    	if((ask_shahrasb(INF_bit, 0) ^ orig) == INF_bit){
    		return {-neg, -neg_q};
    	} else {
    		return {pos, pos_q};
    	}
    } else {
    	if((ask_shahrasb(INF_bit, 0) ^ orig) == INF_bit){
    		return {-neg, neg_q};
    	} else {
    		return {pos, -pos_q};
    	}
    }
}