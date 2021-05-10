// https://codefu.mk/codefu2021-round2.html?subpage=problem&problemid=3272

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

typedef long long ll;
using namespace std;

class AstralKombat {
public:
    int fight(vector<int> A, vector<int> B){
        int accum = 0;
        int wins = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] + accum <= B[i]){
                accum = 0;
            } else {
                accum = (A[i] + accum) - B[i];
                wins++;
            }
        }
        return wins;
    }
};
