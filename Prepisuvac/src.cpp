#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 10000;
std::string str;
ll powcand[maxn];
std::string cand[maxn];
ll n, unknown, cands, ind;
 
bool dfs(ll pos, ll unknown_pos, ll ind_left, std::string gen = ""){
    if(ind_left == 0 and pos == n){
        std::cout << gen << '\n';
        return true;
    }
    if(powcand[(unknown - unknown_pos)] <= ind_left){
        return false;
    }
    if(str[pos] != '#'){
        return dfs(pos + 1, unknown_pos, ind_left, gen + str[pos]);
    }
 
    for(ll i = 0; i < cands; i++){
        if(dfs(pos + 1, unknown_pos + 1, ind_left, gen + cand[unknown_pos][i])){
            return true;
        }
        ind_left -= powcand[(unknown - unknown_pos - 1)];
    }
 
    return false;
}
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    std::cin >> n >> unknown >> cands >> ind;
    std::cin >> str;
 
    for(ll i = 0; i < unknown; i++){
        std::cin >> cand[i];
        std::sort(cand[i].begin(), cand[i].end());
    }
 
    powcand[0] = 1;
    for(ll i = 1; i < maxn; i++){
        powcand[i] = powcand[i - 1] * cands;
        if(powcand[i] > ind){
            powcand[i] = 2 * ind;
        }
    }
 
    dfs(0, 0, ind - 1);
}