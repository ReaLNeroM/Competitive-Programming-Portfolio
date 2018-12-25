#include <bits/stdc++.h>
using namespace std;

static int dp[4096][250];
static int trans[250][26];
class Solution {
public:
    map<std::string, int> m;
    map<std::string, int> fill;
    map<int, std::string> mb;
    vector<string> v;

    int dpf(int bit, int pos){
        if(dp[bit][pos] != -1){
            return dp[bit][pos];
        }

        int& ans = dp[bit][pos];

        if(bit + 1 == (1 << v.size())){
            ans = 0;
            return ans;
        }

        ans = 1e9;
        for(int i = 0; i < 26; i++){
            ans = std::min(ans, dpf(bit | fill[mb[trans[pos][i]]], trans[pos][i]) + 1);
        }

        return ans;
    }

    string dpr(int bit, int pos){
        if(bit + 1 == (1 << v.size())){
            return "";
        }

        for(int i = 0; i < 26; i++){
            if(dp[bit][pos] == dpf(bit | fill[mb[trans[pos][i]]], trans[pos][i]) + 1){
                return ((char) ('a' + i)) + dpr(bit | fill[mb[trans[pos][i]]], trans[pos][i]);
            }
        }
    }

    string shortestSuperstring(vector<string>& A) {
        memset(dp, -1, sizeof(dp));
        v = A;
        int ms = 0;

        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j <= A[i].size(); j++){
                m[A[i].substr(0, j)] = ms;
                mb[ms] = A[i].substr(0, j);
                ms++;
            }
            fill[A[i]] |= (1 << i);
        }

        memset(trans, 0, sizeof(trans));
        for(int i = 0; i < ms; i++){
            std::string xx = mb[i];
            for(int j = 0; j < 26; j++){
                std::string vv = xx + ((char) ('a' + j));
                while(m.find(vv) == m.end()){
                    vv.erase(vv.begin());
                }
                trans[i][j] = m[vv];
            }
        }

        dpf(0, 0);

        return dpr(0, 0);
    }
};

int main(){
    std::cout << "2" << '\n';
    Solution x;
    std::vector<string> v = std::vector<string>{"gruuz","zjr","uuzj","rfgr"};
    std::cout << x.shortestSuperstring(v);
}
