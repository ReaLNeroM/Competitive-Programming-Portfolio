#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int valy[maxn];
int valx[maxn];
int most_bit = (1 << 30);
int res = 0;

struct trie {
    trie *t1 = NULL;
    trie *t0 = NULL;
};

trie *even, *odd;

void add(trie* pos, int bit, int v){
    if(bit == 0){
        return;
    }

    if(v & bit){
        if(!pos->t1){
            pos->t1 = new trie;
            pos->t1->t1 = NULL;
            pos->t1->t0 = NULL;
        }

        add(pos->t1, bit / 2, v);
    } else {
        if(!pos->t0){
            pos->t0 = new trie;
            pos->t0->t1 = NULL;
            pos->t0->t0 = NULL;
        }

        add(pos->t0, bit / 2, v);
    }
}

int best(trie* pos, int bit, int v){
    if(bit == 0){
        return 0;
    }

    if(!pos->t0 and !pos->t1){
    	return -1;
    }

    if((v & bit) and pos->t0){
        return best(pos->t0, bit / 2, v);
    } else if((!(v & bit)) and pos->t1){
        return bit ^ best(pos->t1, bit / 2, v);
    } else if((v & bit) and pos->t1){
        return bit ^ best(pos->t1, bit / 2, v);
    } else if((!(v & bit)) and pos->t0){
        return best(pos->t0, bit / 2, v);
    } else {
        return 0;
    }
}

int main(){
    std::ios::sync_with_stdio(false);

    even = new trie;
    even->t0 = NULL;
    even->t1 = NULL;

    odd = new trie;
    odd->t0 = NULL;
    odd->t1 = NULL;

    int y, x;
    std::cin >> y >> x;

    for(int i = 0; i < y; i++){
        std::cin >> valy[i];
    }

    for(int i = 0; i < x; i++){
        std::cin >> valx[i];
    }

    for(int i = 0; i < y; i++){
        int v = 0;
        for(int j = i; j < y; j++){
            v ^= valy[j];
            if((j - i + 1) % 2 == 1){
                add(odd, most_bit, v);
            } else {
                add(even, most_bit, v);
            }
        }
    }

    for(int i = 0; i < x; i++){
        int v = 0;
        for(int j = i; j < x; j++){
            v ^= valx[j];
            if((j - i + 1) % 2 == 1){
                res = std::max(res, v ^ best(odd, most_bit, v));
                res = std::max(res, best(even, most_bit, v));
            } else {
                res = std::max(res, v);
            }
        }
    }

    std::cout << res << '\n';
}
