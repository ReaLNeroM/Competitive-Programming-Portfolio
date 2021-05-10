// https://codefu.mk/codefu2021-round2.html?subpage=problem&problemid=3273

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

typedef long long ll;
using namespace std;

class DnaSequencing {
public:
    int calculateErrors(string A, string B){
        int res = B.size();
        for(int i = 0; i + B.size() <= A.size(); i++){
            int diffs = 0;
            for(int j = 0; j < B.size(); j++){
                if(A[i + j] != B[j]){
                    diffs++;
                }
            }
            res = min(res, diffs);
        }
        return res;
    }
};
