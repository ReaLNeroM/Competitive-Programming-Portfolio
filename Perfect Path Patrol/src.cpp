#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 5e5 + 1e2;
int val[maxn];
std::vector<std::pair<int, int>> adj[maxn];
int par[maxn];
int parcost[maxn];
int level[maxn];
int paiddown[maxn];
std::vector<int> bylevel[maxn];

void dfs(int pos){
    for(auto &next : adj[pos]){
        if(par[next.first] == -1){
            par[next.first] = pos;
            parcost[next.first] = next.second;
            level[next.first] = level[pos] + 1;
            bylevel[level[next.first]].push_back(next.first);
            dfs(next.first);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for(int i = 0; i < n - 1; i++){
        int f, s, c;
        cin >> f >> s >> c;
        adj[f].push_back({s, c});
        adj[s].push_back({f, c});
    }

    for(int i = 0; i < n; i++){
        par[i] = -1;
        level[i] = 0;
    }

    par[0] = -2;
    bylevel[0].push_back(0);
    dfs(0);

    int res = 0;

    for(int kk = n - 1; kk >= 0; kk--){
        for(int k : bylevel[kk]){
            // below are done, above isn't.
            std::vector<int> flows;
            int available = 0;
            for(auto n : adj[k]){
                if(level[n.first] == level[k] + 1){
                    flows.push_back(n.second - paiddown[n.first]);
                }
            }
            // std::sort(flows.begin(), flows.end());
            // std::reverse(flows.begin(), flows.end());
            for(int i = 0; i < flows.size(); i++){
                if(available < flows[i]){
                    res += flows[i] - available;
                    available += 2*(flows[i] - available);
                }
                available -= flows[i];
            }
            if(available > 0){
                paiddown[k] = std::min(parcost[k], available);
            }
        }
    }

    std::cout << res << '\n';
}
