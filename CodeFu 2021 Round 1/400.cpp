// https://codefu.mk/codefu2021-round1.html?subpage=problem&problemid=3215

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
// #include <iostream>

typedef long long ll;
using namespace std;

struct DSU {
    DSU* parent = this;
    int ind;
    int rank = 0;

    DSU* head(){
        if(parent != parent->parent){
            parent = parent->head();
        }

        return parent;
    }
    void merge(DSU* second){
        DSU* first = head();
        second = second->head();

        if(first->rank > second->rank){
            second->parent = first;
        } else if(first->rank < second->rank){
            first->parent = second;
        } else {
            second->parent = first;
            first->rank++;
        }
    }
};

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};

class Marker {
    int dp[101][101][2];
    std::vector<int> a;
    int n;
    int k;
    int dfs(int pos, int left, bool sign){
        int& ans = dp[pos][left][sign];
        if(ans != -1){
            return ans;
        }

        if(pos == n){
            if(left == 0){
                ans = 0;
            } else {
                ans = -100000;
            }
            return ans;
        }

        ans = dfs(pos + 1, left, sign) + (sign ? -a[pos] : a[pos]);
        if(left > 0){
            ans = std::max(ans, dfs(pos + 1, left - 1, !sign) + ((!sign) ? -a[pos] : a[pos]));
        }

        return ans;
    }
public:
    int bestMarking(vector<int> _a, int _n, int _k){
        a = _a;
        n = _n;
        k = _k;
        memset(dp, -1, sizeof(dp));

        return dfs(0, k, 0);
    }
};
