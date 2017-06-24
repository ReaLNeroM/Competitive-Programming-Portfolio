#include <iostream>
#include <vector>
#include <algorithm>
 
typedef long long ll;
 
#define bit1 (1 << (sticks / 2))
#define bit2 (1 << sticks)
 
int main() {
    ll sticks, sides;
    std::cin >> sticks >> sides;
 
    ll length[sticks];
    for (ll i = 0; i < sticks; i++) {
        std::cin >> length[i];
    }
    std::sort(length, length + sticks);
 
    ll res = 0;
    std::vector<ll> sec[sticks + 1];
    for (ll i = 0; i < bit1; i++) {
        ll sum = 0, max = 0, used = 0;
        for (ll j = 0; j < sticks; j++) {
            if (i & (1 << j)) {
                sum += length[j];
                max = std::max(max, length[j]);
                used++;
            }
        }
 
        if (max < sum - max and used == sides) {
            res++;
        }
 
        sec[used].push_back(sum);
    }
    for (ll i = 0; i < sticks; i++) {
        std::sort(sec[i].begin(), sec[i].end());
    }
 
    for (ll i = bit1; i < bit2; i += bit1) {
        ll sum = 0, max = 0, used = 0;
 
        for (ll j = 0; j < sticks; j++) {
            if (i & (1 << j)) {
                sum += length[j];
                max = std::max(max, length[j]);
                used++;
            }
        }
        sum -= max;
 
        ll goal = max - sum;
        ll lefttouse = sides - used;
 
        if(!sec[lefttouse].empty() and lefttouse >= 0){
            res += sec[lefttouse].end() - std::upper_bound(sec[lefttouse].begin(), sec[lefttouse].end(), goal);
        }
    }
 
    std::cout << res;
    return 0;
}
