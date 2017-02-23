#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;

    ll found = 0;
    for(ll i = 2; i <= b * 2; i *= 2){
        ll res = i - 1;
        for(ll j = i / 4; j >= 1; j /= 2){
            if((res ^ j) >= a and (res ^ j) <= b){
                found++;
            }
        }
    }

    cout << found;
    return 0;
}
