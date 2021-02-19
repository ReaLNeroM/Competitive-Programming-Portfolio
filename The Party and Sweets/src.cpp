#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
std::pair<int, bool> v[maxn];

int main(){
    std::ios::sync_with_stdio(false);

    ll boys, girls;
    std::cin >> boys >> girls;

    for(ll i = 0; i < boys; i++){
        std::cin >> v[i].first;
        v[i].second = 0;
    }

    for(ll i = boys; i < boys + girls; i++){
        std::cin >> v[i].first;
        v[i].second = 1;
    }

    std::sort(v, v + (boys + girls), std::greater<std::pair<int, bool>>());

    ll needed_sum_for_max = 0;
    ll needed_count_for_max = 0;
    ll lowest_for_max = -1;

    ll res = 0;

    bool seen_boy = false;

    for(ll i = 0; i < boys + girls; i++){
        if(v[i].second == 0){ // boy
            if(needed_count_for_max != girls || lowest_for_max == v[i].first){
                res += needed_sum_for_max;
                res += (girls - needed_count_for_max) * v[i].first;

                needed_sum_for_max = 0;
                needed_count_for_max = 0;
                lowest_for_max = -1;
            } else {
                res += needed_sum_for_max - lowest_for_max;
                res += 1 * v[i].first;

                needed_sum_for_max = lowest_for_max;
                needed_count_for_max = 1;
            }

            seen_boy = true;
        } else { // girl
            if(seen_boy){
                std::cout << -1 << '\n';
                return 0;
            }

            needed_sum_for_max += v[i].first;
            needed_count_for_max += 1;
            lowest_for_max = v[i].first;
        }
    }

    if(needed_count_for_max != 0){
        std::cout << -1 << '\n';
        return 0;
    }

    std::cout << res << '\n';
}