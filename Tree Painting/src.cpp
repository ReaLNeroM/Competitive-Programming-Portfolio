#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2e5 + 1e2;
std::vector<int> adj[maxn];
ll n;
ll size[maxn];
ll dp[maxn];
ll parent[maxn];

void dfs(ll pos, ll par){
    size[pos] = 1;
    parent[pos] = par;

    dp[pos] = 0;

    for(ll next : adj[pos]){
        if(next == par){
            continue;
        }

        dfs(next, pos);
        size[pos] += size[next];
        dp[pos] += dp[next];
    }

    dp[pos] += size[pos];
}

ll solve_dfs(ll pos, ll points_from_above = 0){
    if(adj[pos].size() == 1 and pos != 0){
        return points_from_above + n;
    }

    ll points_from_removing_this_node = n; // minus the child node (we'll try all possible choices)
    ll points_from_all_children = points_from_above;

    for(ll next : adj[pos]){
        if(next == parent[pos]){
            continue;
        }

        points_from_all_children += dp[next];
    }

    ll res = 0;
    for(ll next : adj[pos]){
        if(next == parent[pos]){
            continue;
        }

        res = std::max(res, solve_dfs(next, (points_from_removing_this_node - size[next]) +
                                            (points_from_all_children - dp[next])));
    }

    return res;
}

int main(){
    std::ios::sync_with_stdio(false);

    std::cin >> n;

    for(ll i = 0; i < n - 1; i++){
        ll f, s;
        std::cin >> f >> s;
        f--, s--;

        adj[f].push_back(s);
        adj[s].push_back(f);
    }

    dfs(0, -1);

    ll res = 0;
    if(adj[0].size() == 1){
        // if the root is a leaf, handle this separately
        res = dp[0];
    }

    res = std::max(res, solve_dfs(0));

    std::cout << res << '\n';
}