// https://open.kattis.com/contests/nadc21practice1/problems/sodaslurper

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int e, f, c;
    cin >> e >> f >> c;

    int t = e + f;
    int d = 0;
    while(t >= c){
        t -= c;
        t += 1;
        d++;
    }

    cout << d << '\n';
}
