// https://codefu.mk/codefu2021-round2.html?subpage=problem&problemid=3274

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

typedef long long ll;
using namespace std;

class Birds {
public:
    int distance(string sa, string sb){
        ll la = 0;
        ll lb = 0;
        for(int i = 0; i < sa.size(); i++){
            la *= 10;
            la += sa[i] - '0';
        }
        for(int i = 0; i < sb.size(); i++){
            lb *= 10;
            lb += sb[i] - '0';
        }
        int res = 0;
        while(la != lb){
            if(la < lb){
                lb /= 2;
                res++;
            } else {
                la /= 2;
                res++;
            }
        }
        return res;
    }
};
