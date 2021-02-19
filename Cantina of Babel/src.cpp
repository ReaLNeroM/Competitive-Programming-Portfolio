#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const int maxn = 1e2 + 1e2;
std::vector<std::string> st[maxn];
std::vector<int> adj[maxn];
int mat[maxn][maxn];
int n;
int res = 0;

void print(std::vector<int> comp){
    res = std::max(res, (int) comp.size());
}

vi val, comp, z, cont;
int Time, ncomps;
int dfs(int j) {
    int low = val[j] = ++Time, x; z.push_back(j);
    trav(e,adj[j]) if (comp[e] < 0)
        low = min(low, val[e] ?: dfs(e));

    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        print(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
void scc() {
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i);
}

int main(){
    std::ios::sync_with_stdio(false);

    std::cin >> n;

    std::string s;
    std::getline(std::cin, s);
    for(int i = 0; i < n; i++){
        std::string s;
        std::getline(std::cin, s);

        std::stringstream str;
        str << s;

        int j = 0;
        while(str >> s){
            if(j != 0){
                st[i].push_back(s);
            }
            j++;
        }
    }

    for(int i = 0; i < n; i++){
        std::string speak = st[i][0];

        for(int j = 0; j < n; j++){
            for(std::string listen : st[j]){
                if(speak == listen){
                    adj[j].push_back(i);
                    mat[j][i] = 1;
                    break;
                }
            }
        }
    }

    scc();

    std::cout << n - res << '\n';
}