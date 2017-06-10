#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxpeople = 55;
const ll maxquestions = 20005;
const ll maxgroups = 55;
const ll INF = 1e15;
 
ll people, questions, groups;
ll prize[maxquestions];
ll correct[maxpeople][maxquestions];
ll nextfall[maxpeople][maxquestions];
ll dp[maxquestions][maxgroups];
ll sum[maxquestions];
 
ll f(int a, int b){
    ll res = 0;
 
    for(int i = 0; i < people; i++){
        if(nextfall[i][a] > b){
            res += sum[b] - sum[a] + prize[a];
        }
    }
 
    return res;
}
 
ll dfs(ll pos, ll left){
    if(dp[pos][left] == -1){
        if(pos >= questions){
            if(left != 0){
                dp[pos][left] = INF;
            } else {
                dp[pos][left] = 0;
            }
        } else {
            if(left == 1){
                dp[pos][left] = f(pos, questions - 1);
            } else {
                dp[pos][left] = INF;
 
                std::vector<int> v;
                v.push_back(pos);
                for(int i = 0; i < people; i++){
                    v.push_back(nextfall[i][pos]);
                }
 
                for(ll i = 0; i < v.size(); i++){
                    dp[pos][left] = std::min(dp[pos][left], f(pos, v[i]) + dfs(v[i] + 1, left - 1));
                }
            }
        }
    }
 
    return dp[pos][left];
}
 
int main(){
    std::ios::sync_with_stdio(false);
 
    std::cin >> people >> questions >> groups;
 
    for(ll i = 0; i < questions; i++){
        std::cin >> prize[i];
        if(i == 0){
            sum[i] = prize[i];
        } else {
            sum[i] = sum[i - 1] + prize[i];
        }
    }
 
    for(ll i = 0; i < people; i++){
        std::string s;
        std::cin >> s;
 
        for(ll j = 0; j < questions; j++){
            if(s[j] == '1'){
                correct[i][j] = true;
            } else {
                correct[i][j] = false;
            }
        }
    }
 
    for(int i = 0; i < people; i++){
        nextfall[i][questions] = questions;
        for(int j = questions - 1; j >= 0; j--){
            nextfall[i][j] = nextfall[i][j + 1];
            if(!correct[i][j]){
                nextfall[i][j] = j;
            }
        }
    }
 
    for(int i = 0; i < maxquestions; i++){
        for(int j = 0; j < maxgroups; j++){
            dp[i][j] = -1;
        }
    }
 
    for(ll i = 1; i <= groups; i++){
        std::cout << dfs(0, i) << '\n';
    }
}