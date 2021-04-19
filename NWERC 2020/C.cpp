// https://codeforces.com/gym/103049/problem/C

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    ll n, k;
    ll d, s;
    cin >> n >> k >> d >> s;

    ll ss = n * d;
    ss -= s * k;

    if(ss < 0 or 100LL * (n - k) < ss){
        cout << "impossible\n";
        return 0;
    }

    long double tt = (long double) ss / (n - k);

    std::cout.precision(10);
    cout << std::fixed << tt << '\n';
}
