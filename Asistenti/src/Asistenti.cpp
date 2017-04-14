#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
const int maxn = 50005;
int n;
vector<pair<int, int>> adj[maxn];
vector<int> arrow[maxn];
vector<int> sec[maxn];
int dist[maxn];
int above[maxn];
int filled[maxn];
int res_for[maxn];
int apar[maxn];
int sub[maxn];
int res = -1;
int res_amount = 0;
    
void dfs1(int pos, int par){
    apar[pos] = par;
    dist[pos] = -1e9;
    if(filled[pos]){
        dist[pos] = 0;
    }
    sub[pos] = filled[pos];
    
    for(int i = 0; i < adj[pos].size(); i++){
        int nnext = adj[pos][i].first;
    
        if(nnext != par){
            dfs1(nnext, pos);
            dist[pos] = max(dist[pos], dist[nnext] + adj[pos][i].second);
            sub[pos] += sub[nnext];
        }
    }
}
    
void dfs2(int pos, int par, int best_above){
    int best = best_above;
    above[pos] = best_above;
    int bestind = -1;
    int best2 = -1e9;
    
    for(int i = 0; i < adj[pos].size(); i++){
        if(adj[pos][i].first != par){
            if(best < adj[pos][i].second + dist[adj[pos][i].first]){
                best2 = best;
                bestind = i;
                best = adj[pos][i].second + dist[adj[pos][i].first];
            } else if(best2 < adj[pos][i].second + dist[adj[pos][i].first]){
                best2 = adj[pos][i].second + dist[adj[pos][i].first];
            }
        }
    }
 
    if(pos == 19087){
        int xxxx = 5;
    }
    int sec_search = best2;
 
    for(int i = 0; i < adj[pos].size(); i++){
        if(adj[pos][i].first != par){
            if(dist[adj[pos][i].first] + adj[pos][i].second == best){
                arrow[pos].push_back(i);
            }
            if(dist[adj[pos][i].first] + adj[pos][i].second == sec_search){
                sec[pos].push_back(i);
            }
            if(bestind != i){
                int best_next_above = max(best + adj[pos][i].second, best_above + adj[pos][i].second);
                if(filled[pos]){
                    best_next_above = max(best_next_above, adj[pos][i].second);
                }
                dfs2(adj[pos][i].first, pos, best_next_above);
            } else {
                int best_next_above = max(best2 + adj[pos][i].second, best_above + adj[pos][i].second);
                if(filled[pos]){
                    best_next_above = max(best_next_above, adj[pos][i].second);
                }
                dfs2(adj[pos][i].first, pos, best_next_above);
            }
        } else {
            if(best_above == best){
                arrow[pos].push_back(i);
            }
        }
    }
}
 
void dfs5(int pos, int par, bool up_allowed = true){
    res_for[pos]++;
    if(!up_allowed and sub[pos] - filled[pos] == 0){
        return;
    }
 
    if(up_allowed){
        if(arrow[pos].size() >= 3){
            return;
        } else {
            int imp = arrow[pos].size();
            for(int i = 0; i < arrow[pos].size(); i++){
                if(adj[pos][arrow[pos][i]].first == par){
                    imp--;
                }
            }
 
            if(imp == 1){
                for(int i = 0; i < arrow[pos].size(); i++){
                    if(adj[pos][arrow[pos][i]].first != par){
                        dfs5(adj[pos][arrow[pos][i]].first, pos, up_allowed & (adj[pos][arrow[pos][i]].first == apar[pos]));
                    }
                }
            } else if(imp == 0){
                if(sec[pos].empty()){
                    if(apar[pos] != par){
                        dfs5(apar[pos], pos, true);
                    }
                } else {
                    if(apar[pos] != par and above[pos] >= dist[pos]){
                        dfs5(apar[pos], pos, true);
                    }
                    for(int i = 0; i < sec[pos].size(); i++){
                        if(adj[pos][sec[pos][i]].first != par){
                            dfs5(adj[pos][sec[pos][i]].first, pos, false);
                        }
                    }
                }
            }
        }
    } else {
        if(arrow[pos].size() == 1 and adj[pos][arrow[pos][0]].first == apar[pos]){
            if(sec[pos].size() >= 3){
                return;
            } else {
                int imp = sec[pos].size();
                for(int i = 0; i < sec[pos].size(); i++){
                    if(adj[pos][sec[pos][i]].first == par){
                        imp--;
                    }
                }
 
                if(imp == 1){
                    for(int i = 0; i < sec[pos].size(); i++){
                        if(adj[pos][sec[pos][i]].first != par){
                            dfs5(adj[pos][sec[pos][i]].first, pos, false);
                        }
                    }
                }
            }
        } else {
            if(arrow[pos].size() >= 4){
                return;
            } else {
                int imp = arrow[pos].size();
                for(int i = 0; i < arrow[pos].size(); i++){
                    if(adj[pos][arrow[pos][i]].first == par or adj[pos][arrow[pos][i]].first == apar[pos]){
                        imp--;
                    }
                }
 
                if(imp == 1){
                    for(int i = 0; i < arrow[pos].size(); i++){
                        if(adj[pos][arrow[pos][i]].first != par or adj[pos][arrow[pos][i]].first != apar[pos]){
                            dfs5(adj[pos][arrow[pos][i]].first, pos, false);
                        }
                    }
                }
            }
        }
    }
}
    
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int f, s, d;
        cin >> f >> s >> d;
    
        adj[f].push_back({s, d});
        adj[s].push_back({f, d});
    }
 
    int fill;
    cin >> fill;
    for(int i = 0; i < fill; i++){
        int ind;
        cin >> ind;
        filled[ind] = true;
    }
     
    dfs1(0, -1);
    dfs2(0, -1, -1e9);
    for(int i = 0; i < n; i++){
        if(filled[i]){
            dfs5(i, -1);
        }
    }
 
    for(int i = 0; i < n; i++){
        if(!filled[i]){
            if(res < res_for[i]){
                res = res_for[i];
                res_amount = 1;
            } else if(res == res_for[i]){
                res_amount++;
            }
        }
    }
    cout << res << ' ' << res_amount << endl;
}