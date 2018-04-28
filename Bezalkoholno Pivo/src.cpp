#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxpiva = 1e3 + 1e2;
const ll maxn = 6000001;
ll budget, order;
ll n;
std::vector<std::vector<ll> > piva;
ll dp[maxn];
ll partial_sum[maxpiva];
ll ke_ides_do[maxpiva];
 
ll brute(){
    ll best = 0;
 
    dp[0] = order;
 
    ll one_side = 1;
    for(ll j = 1; j <= budget; j++){
        dp[j] = budget + 1;
 
        for(ll i = 0; i < piva.size(); i++){
            if(piva[i][0] >= j){
                dp[j] = std::min(dp[j], dp[j - 1] + piva[i][1]);
            } else {
                dp[j] = std::min(dp[j], dp[j - piva[i][0]] + dp[piva[i][0]]);
            }
        }
 
        if(dp[j] <= budget){
            best = std::max(best, j);
        } else {
            break;
        }
    }
 
    return best;
}
 
ll smart(){
    ll best = 0;
 
    partial_sum[0] = order;
    ke_ides_do[0] = 0;
 
    for(ll i = 1; i <= n; i++){
        ke_ides_do[i] = piva[i - 1][0];
        partial_sum[i] = partial_sum[i - 1] + (ke_ides_do[i] - ke_ides_do[i - 1]) * piva[i - 1][1];
    }
 
    for(ll i = 0; i <= n; i++){
        ll times_full_taken, attempt, budget_left;
 
        if(i == 0){
            times_full_taken = 0;
            attempt = 0;
            budget_left = budget;
        } else {
            times_full_taken = budget / partial_sum[i];
            attempt = times_full_taken * ke_ides_do[i];
            budget_left = budget % partial_sum[i];
        }
 
        ll attempt2 = 0;
        if(i != n and i != 0){
            attempt2 += std::min(times_full_taken * (ke_ides_do[i] - ke_ides_do[i - 1]), budget_left / piva[i][1]);
        }
 
        budget_left -= order;
 
        ll attempt3 = 0;
        ll last = 0;
        for(ll j = 0; j < n and budget_left >= 0; j++){
            ll you_can_take = std::min(piva[j][0] - last, budget_left / piva[j][1]);
            attempt3 += you_can_take;
            last += you_can_take;
 
            if(piva[j][0] != last){
                break;
            }
 
 
            budget_left -= you_can_take * piva[j][1];
        }
 
        best = std::max(best, attempt + std::max(attempt2, attempt3));
    }
 
    return best;
}
 
int main(){
    std::ios::sync_with_stdio(false);
 
    std::cin >> budget >> order;
 
    std::cin >> n;
 
    piva.resize(n);
    for(ll i = 0; i < n; i++){
        piva[i].resize(2);
        std::cin >> piva[i][1] >> piva[i][0];
        piva[i][0]++;
    }
 
    std::sort(piva.begin(), piva.end());
 
    for(ll i = 0; i < piva.size(); i++){
        for(ll j = 0; j < piva.size(); j++){
            if(i != j and piva[j][0] >= piva[i][0] and piva[j][1] <= piva[i][1]){
                piva.erase(piva.begin() + i);
                i--;
                break;
            }
        }
    }
 
    n = piva.size();
 
    if(budget > 5000000){
        std::cout << smart() << '\n';
    } else {
        std::cout << brute() << '\n';
    }
}