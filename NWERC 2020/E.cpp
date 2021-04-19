// https://codeforces.com/gym/103049/problem/E

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
vector<pair<ll, ll>> moves;
ll n;
ll ax, ay;
ll bx, by;

bool bobgoto(ll x, ll y){
    if(bx == x and by == y){
        return true;
    }
    for(auto i : moves){
        if(bx + i.first == x and by + i.second == y){
            return true;
        }
    }

    std::set<pair<ll, ll>> jumps;
    for(auto i : moves){
        if(0 <= bx + i.first and bx + i.first < n and 0 <= by + i.second and by + i.second < n){
            jumps.insert({bx + i.first, by + i.second});
        }
    }

    // two jumps, kinda tricky
    for(auto i : moves){
        ll bbx = x - i.first;
        ll bby = y - i.second;

        if(jumps.count({bbx, bby})){
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    cin >> ax >> ay;
    cin >> bx >> by;
    ax--, ay--;
    bx--, by--;

    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        moves.push_back({a, b});
    }


    // can alice win?
    for(ll i = 0; i < n; i++){
        moves[i].first *= -1;
        moves[i].second *= -1;
    }
    if(bobgoto(ax, ay)){
        cout << "Alice wins\n";
        return 0;
    }
    for(ll i = 0; i < n; i++){
        moves[i].first *= -1;
        moves[i].second *= -1;
    }

    if(n <= 10){
        ll bobspace = 0;
        ll hidex, hidey;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(bobgoto(i, j)){
                    bobspace++;
                } else {
                    hidex = i;
                    hidey = j;
                }
            }
        }

        if(bobspace == n * n){
            cout << "Bob wins\n";
        } else {
            cout << "tie " << hidex + 1 << ' ' << hidey + 1 << '\n';
        }
        return 0;
    }

    srand(time(0));

    // can alice not lose?
    for(ll randmove = 0; randmove < 150; randmove++){
        ll randx = rand() % n;
        ll randy = rand() % n;

        if(!bobgoto(randx, randy)){
            cout << "tie " << randx + 1 << ' ' << randy + 1 << '\n';
            return 0;
        }
    }
}
