// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145

#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 10;
const ll INF = 1e6;

int val[maxn];
int dp[maxn][2];
int x, y;
std::string s;

char int_to_char(int t){
    if(t == 0){
        return 'C';
    } else {
        return 'J';
    }
}

int char_to_int(char c){
    if(c == 'C'){
        return 0;
    } else {
        return 1;
    }
}

int penalty(int a, int b){
    if(a != b and a == 0){
        return x;
    } else if(a != b and a == 1){
        return y;
    } else {
        return 0;
    }
}

int dpfunc(int pos, int last){
    if(dp[pos][last] != -1){
        return dp[pos][last];
    }

    int& ans = dp[pos][last];
    ans = INF;

    if(pos == s.size()){
        ans = 0;
        return ans;
    }

    if(s[pos] == '?'){
        ans = std::min(dpfunc(pos + 1, 0) + penalty(last, 0),
                       dpfunc(pos + 1, 1) + penalty(last, 1));
    } else {
        int now = char_to_int(s[pos]);
        ans = std::min(ans, dpfunc(pos + 1, now) + penalty(last, now));
    }

    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        std::cin >> x >> y >> s;

        memset(dp, -1, sizeof(dp));

        for(int i = s.size(); i >= 0; i--){
            dpfunc(i, 0);
            dpfunc(i, 1);
        }

        int res;
        if(s[0] == '?'){
            res = std::min(dpfunc(1, 0), dpfunc(1, 1));
        } else {
            res = dpfunc(1, char_to_int(s[0]));
        }

        std::cout << res << '\n';
    }
}