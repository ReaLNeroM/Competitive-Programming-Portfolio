#include <bits/stdc++.h>
 
typedef long long ll;
 
const int maxn = 2e5 + 1e2;
 
struct dsu {
    dsu* par = this;
    int rank = 0;
    int highest_ind;
     
    dsu* head(){
        if(par != par->par){
            par = par->head();
        }
         
        return par;
    }       
     
    void merge(dsu* second){
        dsu* fir = head();
        dsu* sec = second->head();

        if(fir->rank > sec->rank){
            sec->par = fir;
        } else if(sec->rank > fir->rank){
            fir->par = sec;
        } else {
            fir->par = sec;
            sec->rank++;
        }
    }
};
 
int v, e, p;
int dfs_num[maxn];
int dfs_low[maxn];
std::vector<std::vector<int>> adj[maxn];
std::vector<int> to_inspect[maxn];
int color[maxn];
int bridge[maxn];
int in[maxn];
int out[maxn];
int res[maxn];
int order_given[maxn];
int curr = 0;
int path_f[maxn];
int path_s[maxn];
dsu d[maxn];
 
void dfs(int pos, int par, int par_edge){
    color[pos] = 1;
    dfs_num[pos] = curr;
    dfs_low[pos] = curr;
    curr++;
 
    for(int i = 0; i < adj[pos].size(); i++){
        if(color[adj[pos][i][0]] == 0){
            dfs(adj[pos][i][0], pos, adj[pos][i][1]);
 
            if(dfs_low[adj[pos][i][0]] > dfs_num[pos]){
                bridge[adj[pos][i][1]] = true;
            }
 
            dfs_low[pos] = std::min(dfs_low[pos], dfs_low[adj[pos][i][0]]);
        } else if(adj[pos][i][1] != par_edge){
            dfs_low[pos] = std::min(dfs_low[pos], dfs_low[adj[pos][i][0]]);
        }
    }
 
    color[pos] = 2;
}
 
void dfs2(int pos, int par, int par_edge){
    color[pos] = 3;
     
    for(int i = 0; i < adj[pos].size(); i++){
        if(color[adj[pos][i][0]] == 2){
            dfs2(adj[pos][i][0], pos, adj[pos][i][1]);
            d[adj[pos][i][0]].merge(&d[pos]);
            d[adj[pos][i][0]].head()->highest_ind = pos;
        }
    }
     
    color[pos] = 4;
    
    for(int i = 0; i < to_inspect[pos].size(); i++){
        int other = to_inspect[pos][i];
         
        if(color[other] == 4){
            int lca = d[other].head()->highest_ind;
            in[lca]--;
            out[lca]--;
        }
    }
}
 
std::vector<int> dfs3(int pos, int par, int par_edge){
    color[pos] = 5;
 
    int here_in = in[pos];
    int here_out = out[pos];
 
    for(int i = 0; i < adj[pos].size(); i++){
        if(color[adj[pos][i][0]] == 4){
            std::vector<int> get = dfs3(adj[pos][i][0], pos, adj[pos][i][1]);
            here_in += get[0];
            here_out += get[1];
        }
    }
 
    if(par_edge != -1 and bridge[par_edge]){
        if(here_in){
            if((par < pos) == order_given[par_edge]){
                res[par_edge] = 1;
            } else {
                res[par_edge] = 2;
            }
        } else if(here_out){
            if((par < pos) == order_given[par_edge]){
                res[par_edge] = 2;
            } else {
                res[par_edge] = 1;
            }
        }
    }
 
    color[pos] = 6;
 
    return {here_in, here_out};
}
 
int main(){
    std::ios::sync_with_stdio(false);
 
    std::cin >> v >> e;
 
    for(int i = 0; i < e; i++){
        int f, s;
        std::cin >> f >> s;
        f--, s--;
 
        if(f != s){
            if(f < s){
                order_given[i] = true;
            } else {
                order_given[i] = false;
            }
 
            adj[f].push_back({s, i});
            adj[s].push_back({f, i});
        }
    }
 
    for(int i = 0; i < v; i++){
        if(color[i] == 0){
            dfs(i, -1, -1);
        }
    }
 
    std::cin >> p;
     
    for(int i = 0; i < p; i++){
        std::cin >> path_f[i] >> path_s[i];
        path_f[i]--, path_s[i]--;
 
        if(path_f[i] == path_s[i]){
            continue;
        }
        
        to_inspect[path_f[i]].push_back(path_s[i]);
        to_inspect[path_s[i]].push_back(path_f[i]);
        
        in[path_s[i]]++;
        out[path_f[i]]++;
    }
     
    for(int i = 0; i < v; i++){
        d[i].highest_ind = i;
    }
     
    for(int i = 0; i < v; i++){
        if(color[i] == 2){
            dfs2(i, -1, -1);
        }
    }
     
    for(int i = 0; i < v; i++){
        if(color[i] == 4){
            dfs3(i, -1, -1);
        }
    }
     
    for(int i = 0; i < e; i++){
        if(res[i] == 0){
            std::cout << 'B';
        } else if(res[i] == 1){
            std::cout << 'R';
        } else {
            std::cout << 'L';
        }
    }
 
    std::cout << std::endl;
}