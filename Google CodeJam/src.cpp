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

        for(int i = 0; i < n; i++){
            std::cin >> val[i];
        }

        //TODO

        std::cout << '\n';
    }
}