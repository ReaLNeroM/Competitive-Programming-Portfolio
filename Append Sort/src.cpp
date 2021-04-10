#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 10;
const ll INF = 1000000000000000010;

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        int n;
        std::cin >> n;

        std::string s[n];
        for(int i = 0; i < n; i++){
            std::cin >> s[i];
        }

        int res = 0;

        string sl = s[0];

        for(int i = 1; i < n; i++){
            if(s[i - 1].size() < s[i].size()){
                // skip!
                sl = s[i];
            } else if(s[i - 1].size() == s[i].size()){
                if(sl < s[i]){
                    // we should be good!
                    sl = s[i];
                } else {
                    // we have to add 0-9.
                    s[i] += '0';
                    sl = s[i];
                    res++;
                }
            } else if(s[i - 1].size() > s[i].size()){
                int status = 0;
                for(int k = 0; k < sl.size() and k < s[i].size(); k++){
                    if(sl[k] < s[i][k]){
                        status = 1;
                        break;
                    } else if(sl[k] > s[i][k]){
                        status = -1;
                        break;
                    }
                }

                if(status > 0){
                    // just make digits equal
                    while(s[i - 1].size() > s[i].size()){
                        s[i] += '0';
                        res++;
                    }
                    sl = s[i];
                } else if(status == 0){
                    // tricky
                    sl = s[i];
                    while(s[i - 1].size() > sl.size()){
                        sl += '9';
                    }
                    if(s[i - 1] < sl){
                        res += s[i - 1].size() - s[i].size();
                        s[i] = s[i - 1];
                        int carry = 1;
                        for(int k = s[i].size() - 1; k >= 0; k--){
                            s[i][k] += carry;
                            if(s[i][k] > '9'){
                                s[i][k] -= 10;
                                carry = 1;
                            } else {
                                carry = 0;
                                break;
                            }
                        }
                        sl = s[i];
                    } else {
                        // exceed by one digit.
                        while(s[i - 1].size() >= s[i].size()){
                            s[i] += '0';
                            res++;
                        }
                        sl = s[i];
                    }
                } else {
                    // exceed by one digit.
                    while(s[i - 1].size() >= s[i].size()){
                        s[i] += '0';
                        res++;
                    }
                    sl = s[i];
                }
            }
        }

        cout << res;

        std::cout << '\n';
    }
}