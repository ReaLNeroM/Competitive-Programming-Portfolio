#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>

typedef long long ll;

class FlippingCards {
    char flip(char x){
        if(x == '0'){
            return '1';
        } else {
            return '0';
        }
    }

public:
    int transform(std::string x){
        int bitset = 0;
        for(int i = 0; i < x.size(); i++){
            bitset *= 2;
            bitset += (x[i] == 'U');
        }

        int res = 0;

        for(int i = 0; i < x.size() - 2; i++){
            if(x[i] == '1'){
                res++;

                x[i    ] = flip(x[i    ]);
                x[i + 1] = flip(x[i + 1]);
                x[i + 2] = flip(x[i + 2]);
            }
        }

        if(x[x.size() - 2] == '1' or x[x.size() - 1] == '1'){
            return -1;
        }

        return res;
    }
};