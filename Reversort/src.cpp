// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c

#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 10;
const ll INF = 1000000000000000010;

int val[maxn];

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        int n;
        std::cin >> n;

        std::map<int, int> m;
        for(int i = 0; i < n; i++){
            std::cin >> val[i];
            m[val[i]] = 0;
        }

        int compressed = 0;
        for(auto& i : m){
            i.second = compressed++;
        }
        for(int i = 0; i < n; i++){
            val[i] = m[val[i]];
        }

        int res = 0;
        for(int i = 0; i < n - 1; i++){
            int loc = -1;
            for(int j = 0; j < n; j++){
                if(val[j] == i){
                    loc = j;
                    break;
                }
            }

            res += loc - i + 1;
            for(int j = i, k = loc; j <= k; j++, k--){
                std::swap(val[j], val[k]);
            }
        }

        std::cout << res << '\n';
    }
}