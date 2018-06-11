#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
std::string s[maxn];
std::map<ll, ll> begin;
std::map<ll, ll> end;
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n;
    std::cin >> n;

    for(ll i = 0; i < n; i++){
        std::cin >> s[i];

        ll running_sum = 0;
        ll most_bottom = 0;
        ll most_top = 0;

        for(char x : s[i]){
            if(x == '('){
                running_sum++;
            } else {
                running_sum--;
            }
            if(running_sum < 0){
                most_top = -1;
                break;
            }

            most_top = std::max(most_top, running_sum);
        }

        if(most_top != -1)
            begin[running_sum]++;

        running_sum = 0;
        std::reverse(s[i].begin(), s[i].end());
        for(char x : s[i]){
            if(x == '('){
                running_sum++;
            } else {
                running_sum--;
            }
            if(running_sum > 0){
                most_bottom = 1;
                break;
            }
            most_bottom = std::min(most_bottom, running_sum);
        }

        
        if(most_bottom != 1)
            end[running_sum]++;
    }

    for(auto ite = begin.begin(); ite != begin.end(); ite++){
        if(ite->first >= 0){
            res += ite->second * end[-ite->first];
        }
    }

    std::cout << res << '\n';
}
