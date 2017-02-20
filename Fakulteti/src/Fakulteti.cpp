#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 65;
const int max_dist = 1e9;
int n, built, add;
vector<int> adj[maxn];
int exists[maxn];
vector<vector<int>> cycles;
vector<int> trees;
vector<int> level[maxn];
int dist[maxn][maxn];
bool cycle[maxn];
int parent[maxn];
int sub[maxn][maxn];

int res = 1e9;

bool good(int allow){
    int real_added = 0;

    for(int i = 0; i < n; i++){
        exists[i] &= 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((exists[i] & 1) == 1 and dist[i][j] <= allow){
                exists[j] |= 2;
            }
        }
    }

    for(int i = maxn - 1; i > 0; i--){
        for(int j = 0; j < level[i].size(); j++){
            int par = parent[level[i][j]];
            bool good = true;
            for(int k = 0; k < n; k++){
                if(k != level[i][j] and sub[level[i][j]][k] and !exists[k] and dist[par][k] > allow){
                    good = false;
                }
            }
            if(!good or (!exists[level[i][j]] and dist[par][level[i][j]] > allow)){
                real_added++;
                for(int k = 0; k < n; k++){
                    if(dist[level[i][j]][k] <= allow){
                        exists[k] |= 2;
                    }
                }
            }
        }
    }

    for(int i = 0; i < trees.size(); i++){
        bool must = false;
        for(int j = 0; j < n; j++){
            if(dist[trees[i]][j] <= allow and !exists[j]){
                must = true;
            }
        }
        if(must){
            real_added++;
            for(int j = 0; j < n; j++){
                if(dist[trees[i]][j] <= allow){
                    exists[j] |= 2;
                }
            }
        }
    }

    for(int i = 0; i < cycles.size(); i++){
        bool empty = true;
        for(int j = 0; j < n; j++){
            if(dist[cycles[i][0]][j] < max_dist and !exists[j]){
                empty = false;
            }
        }
        if(empty){
            continue;
        }

        int best_added = n;

        for(int j = 0; j < cycles[i].size(); j++){
            //don't add anything between (0)...(j - 1)
            int curr_added = 1;

            for(int k = 0; k < n; k++){
                exists[k] &= 3;
            }

            for(int k = 0; k < n; k++){
                if(dist[cycles[i][j]][k] <= allow){
                    exists[k] |= 4;
                }
            }

            int last_add = j;
            for(int k = j + 1; k < cycles[i].size(); k++){
                bool good = true;

                for(int l = j + 1; l < k; l++){
                    for(int m = 0; m < n; m++){
                        if(sub[cycles[i][l]][m] and !exists[m] and dist[cycles[i][k]][m] > allow){
                            good = false;
                        }
                    }
                }

                if(!good){
                    curr_added++;
                    last_add = k - 1;
                    for(int l = 0; l < n; l++){
                        if(dist[cycles[i][k - 1]][l] <= allow){
                            exists[l] |= 4;
                        }
                    }
                }
            }
            bool must_add = false;
            for(int k = j + 1; k < cycles[i].size(); k++){
                for(int l = 0; l < n; l++){
                    if(sub[cycles[i][k]][l] and !exists[l]){
                        must_add = true;
                    }
                }
            }
            if(must_add){
                curr_added++;
                last_add = cycles[i].size() - 1;
                for(int k = 0; k < n; k++){
                    if(dist[cycles[i][cycles[i].size() - 1]][k] <= allow){
                        exists[k] |= 4;
                    }
                }
            }

            bool good = true;
            for(int k = 0; k < j; k++){
                for(int l = 0; l < n; l++){
                    if(sub[cycles[i][k]][l] and !exists[l] and dist[cycles[i][last_add]][l] > allow and dist[cycles[i][j]][l] > allow){
                        good = false;
                    }
                }
            }
            if(good){
                best_added = min(best_added, curr_added);
            }
        }

        real_added += best_added;
    }

    return real_added <= add;
}

void dfs(int pos, int par = -1, int currl = 0){
    sub[pos][pos] = true;
    parent[pos] = par;
    level[currl].push_back(pos);
    for(int i = 0; i < adj[pos].size(); i++){
        if(adj[pos][i] != par and !cycle[adj[pos][i]]){
            dfs(adj[pos][i], pos, currl + 1);
            for(int j = 0; j < n; j++){
                if(sub[adj[pos][i]][j]){
                    sub[pos][j] = true;
                }
            }
        }
    }
}

bool used[maxn];

bool dfs_cycle(int pos, int par, int goal){
    if(pos == goal and par != -1){
        return true;
    }

    used[pos] = true;
    for(int i = 0; i < adj[pos].size(); i++){
        int nnext = adj[pos][i];

        if(par != nnext and (!used[nnext] or nnext == goal)){
            if(dfs_cycle(nnext, pos, goal)){
                return true;
            }
        }
    }

    return false;
}

void calc_cycles(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            used[j] = false;
        }

        if(dfs_cycle(i, -1, i)){
            cycle[i] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> built >> add;

    for(int i = 0; i < built; i++){
        int ind;
        cin >> ind;
        exists[ind - 1] = true;
    }

    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            dist[i][j] = max_dist;
        }
        dist[i][i] = 0;
    }

    int e;
    cin >> e;

    for(int i = 0; i < e; i++){
        int f, s, c;
        cin >> f >> s >> c;
        f--, s--;

        adj[f].push_back(s);
        adj[s].push_back(f);

        dist[f][s] = min(dist[f][s], c);
        dist[s][f] = min(dist[s][f], c);
    }

    calc_cycles();

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool used[n];
    fill(used, used + n, false);

    for(int i = 0; i < n; i++){
        if(!used[i] and cycle[i]){
            vector<int> curr;

            int pos = i;
            used[pos] = true;
            for(int j = 0; j < n; j++){
                curr.push_back(pos);
                dfs(pos);
                for(int k = 0; k <= adj[pos].size(); k++){
                    if(k == adj[pos].size()){
                        j = n;
                        break;
                    }
                    if(cycle[adj[pos][k]] and !used[adj[pos][k]]){
                        used[adj[pos][k]] = true;
                        pos = adj[pos][k];
                        break;
                    }
                }
            }
            for(int j = 0; j < n; j++){
                if(!used[j] and dist[i][j] < max_dist){
                    used[j] = true;
                }
            }

            cycles.push_back(curr);
        }
    }

    for(int i = 0; i < n; i++){
        if(!used[i]){
            trees.push_back(i);

            dfs(i);
            for(int j = 0; j < n; j++){
                if(dist[i][j] < max_dist){
                    used[j] = true;
                }
            }
        }
    }


    int l = 0, r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2;

        if(good(mid)){
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << res;
}
