#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll mod = 1000000007;
const ll maxn = 1e6 + 1e2;
int cycle[maxn];
int parent[maxn];
int tag[maxn];
int dp[maxn][2];
std::vector<int> adj[maxn];
std::vector<ll> cycles;
ll n, k;
ll res = 1;
 
void tag_cycle(int pos, int end){
    ll cycle_size = 0;
 
    while(pos != end){
        cycle[pos] = true;
        cycle_size++;
 
        pos = parent[pos];
    }
 
    cycle_size++;
    cycle[pos] = true;
    cycles.push_back(cycle_size);
}
 
void dfs(int pos){
    tag[pos] = 1;
 
 
 
    tag[pos] = 2;
}
 
void calc_dp(){
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        ll a = (k - 2);
        a *= (ll) dp[i - 1][0];
        a += dp[i - 1][1];
        ll b = (k - 1);
        b *= (ll) dp[i - 1][0];
        a %= mod;
        b %= mod;
        dp[i][0] = a;
        dp[i][1] = b;
    }
}
 
int main(){
    std::ios::sync_with_stdio(false);
 
    std::cin >> n >> k;
 
    calc_dp();
 
    for(int i = 0; i < n; i++){
        int ind;
        std::cin >> ind;
        ind--;
 
        adj[i].push_back(ind);
        adj[ind].push_back(i);
    }
 
    memset(parent, -1, sizeof(parent));
 
    for(int i = 0; i < n; i++){
        if(parent[i] == -1){
            parent[i] = -2;
            std::stack<int> s, ssign;
            s.push(i), ssign.push(-1);
            s.push(i), ssign.push(1);
 
            while(!s.empty()){
                int pos = s.top();
                int sign = ssign.top();
                s.pop();
                ssign.pop();
 
                if(sign == 1){
                    tag[pos] = 1;
 
                    for(int i = 0; i < adj[pos].size(); i++){
                        int next = adj[pos][i];
                        if(next != parent[pos] and tag[next] == 1 and !cycle[pos]){
                            parent[next] = pos;
                            tag_cycle(pos, next);
                        } else if(next != parent[pos] and tag[next] == 0){
                            parent[next] = pos;
                            s.push(next); ssign.push(-1);
                            s.push(next); ssign.push(1);
                        }
                    }
                } else if(sign == -1){
                    tag[pos] = 2;
                }
 
            }
        }
    }
 
 
    for(int i = 0; i < cycles.size(); i++){
        res *= (ll) k;
        res %= mod;
        if(cycles[i] != 1){
            res *= (ll) dp[cycles[i]][1];
        }
        res %= mod;
    }
 
    memset(tag, 0, sizeof(tag));
 
    for(int i = 0; i < n; i++){
        if(!cycle[i] and !tag[i]){
            int size = 1;
            bool in_cycle = false;
 
            std::queue<ll> q;
            q.push(i);
            tag[i] = true;
 
            while(!q.empty()){
                ll fr = q.front();
                q.pop();
 
                for(ll i = 0; i < adj[fr].size(); i++){
                    ll next = adj[fr][i];
 
                    if(cycle[next]){
                        in_cycle = true;
                    } else if(!tag[next]){
                        tag[next] = true;
                        q.push(next);
                        size++;
                    }
                }
            }
 
            for(int j = 0; j < size; j++){
                if(j == 0 and !in_cycle){
                    res = (res * (ll) k) % mod;
                } else {
                    res = (res * (ll) (k - 1LL)) % mod;
                }
            }
        }
    }
 
    std::cout << res << '\n';
}