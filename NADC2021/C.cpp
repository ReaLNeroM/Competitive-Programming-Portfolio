// https://nadc21.kattis.com/problems/nadc21.borders

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct dsu {
    dsu* parent = this;
    int ind;
    int p;
    int rank = 0;

    dsu* head(){
        if(parent != parent->parent){
            parent = parent->head();
        }

        return parent;
    }
    void merge(dsu* second){
        dsu* first = head();
        second = second->head();

        if(first != second){
            if(first->rank > second->rank){
                second->parent = first;
            } else if(first->rank < second->rank){
                first->parent = second;
            } else {
                second->parent = first;
                first->rank++;
            }
        }
    }
};

const int maxn = 1e2 + 1e2;
char mat[maxn][maxn];
dsu d[maxn][maxn];
vector<std::vector<int>> adj;
int indegree[10100];
int y, x;
int comps;
set<int> added[10100];
vector<int> holes[10100];
int par[10100];
int res = 0;
int dp[10100];
int dpholes[10100];

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};


bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    trav(b, g[a]) if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B)){
            btoa[b] = a;
            return 1;
        }
    }
    return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
    int res = 0;
    vi A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(all(A), 0);
        fill(all(B), 0);
        /// Find the starting nodes for BFS (i.e. layer 0).
        cur.clear();
        trav(a, btoa) if(a != -1) A[a] = -1;
        rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
        /// Find all layers using bfs.
        for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            trav(a, cur) trav(b, g[a]) {
                if (btoa[b] == -1) {
                    B[b] = lay;
                    islast = 1;
                }
                else if (btoa[b] != a && !B[b]) {
                    B[b] = lay;
                    next.push_back(btoa[b]);
                }
            }
            if (islast) break;
            if (next.empty()) return res;
            trav(a, next) A[a] = lay;
            cur.swap(next);
        }
        /// Use DFS to scan for augmenting paths.
        rep(a,0,sz(g))
            res += dfs(a, 0, g, btoa, A, B);
    }
    return res;
}


int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    std::cin >> y >> x;

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            cin >> mat[i][j];
            d[i][j].parent = &d[i][j];
            d[i][j].ind = i * x + j;
        }
    }


    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            for(int k = 0; k < 4; k++){
                int ni = i + ay[k];
                int nj = j + ax[k];

                if(0 <= ni and ni < y and 0 <= nj and nj < x and mat[i][j] == mat[ni][nj]){
                    d[i][j].merge(&d[ni][nj]);
                }
            }
        }
    }

    map<int, int> s;
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            s[d[i][j].head()->ind] = 0;
        }
    }
    comps = 0;
    for(auto ite = s.begin(); ite != s.end(); ite++){
        ite->second = comps;
        comps++;
    }
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            d[i][j].head()->p = s[d[i][j].head()->ind];
        }
    }
    adj.resize(comps);

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(i == 0 or i == y - 1 or j == 0 or j == x - 1){
                indegree[d[i][j].head()->p] = 1000000;
            }
        }
    }

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            for(int k = 0; k < 4; k++){
                int ni = i + ay[k];
                int nj = j + ax[k];

                if(0 <= ni and ni < y and 0 <= nj and nj < x){
                    if(indegree[d[i][j].head()->p] != 1000000 and indegree[d[ni][nj].head()->p] != 1000000){
                        if(mat[i][j] == '0' and mat[ni][nj] == '1'){
                            if(!added[d[i][j].head()->p].count(d[ni][nj].head()->p)){
                                added[d[i][j].head()->p].insert(d[ni][nj].head()->p);
                                adj[d[i][j].head()->p].push_back(d[ni][nj].head()->p);
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < comps; i++){
        if(indegree[i] == 1000000){
            res++;
        }
    }

    vi btoa(comps, -1); res += hopcroftKarp(adj, btoa);

    std::cout << res << '\n';
}
