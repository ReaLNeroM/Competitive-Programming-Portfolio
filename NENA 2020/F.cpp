// https://nena20.kattis.com/problems/march6.unreadmessages

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e3 + 1e2;
ll val[maxn];
std::map<ll, ll> lastread;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    ll p, m;
    std::cin >> p >> m;

    for(ll i = 0; i < m; i++){
        std::cin >> val[i];
    }

    long long unread = 0;
    for(ll i = 0; i < m; i++){
        unread += p;
        ll last_read = lastread[val[i]];
        unread -= (i + 1) - (last_read);
        lastread[val[i]] = i + 1;
        cout << unread << '\n';
    }
}
