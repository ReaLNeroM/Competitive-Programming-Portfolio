#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

class SCC {
  private:
    int v;
    std::vector<std::vector<int>> adj, rev;
    std::vector<bool> visited;
    std::vector<int> postOrdering;
    std::vector<int> sccNumbers;
    void explore(int u){
        if(visited[u]){
            return;
        }
        visited[u] = true;
        for(const auto &i : adj[u]){
            explore(i);
        }
        postOrdering.push_back(u);
    }
    void explore2(int u, int sccNumber){
        if(visited[u]){
            return;
        }
        visited[u] = true;
        sccNumbers[u] = sccNumber;
        for(const auto &i : rev[u]){
            explore2(i, sccNumber);
        }
    }
  public:
    SCC(int V, std::vector<std::pair<int, int>> edges) :
        v(V), visited(v), sccNumbers(v), adj(v), rev(v) {
        for(const auto& i : edges){
            adj[i.first].push_back(i.second);
            rev[i.second].push_back(i.first);
        }
    }
    std::vector<int> kosaraju(int& sccCount) {
        for(int i = 0; i < v; i++){
            explore(i);
        }
        for(int i = 0; i < v; i++){
            visited[i] = false;
        }
        int currSCC = 0;
        for(int i = v - 1; i >= 0; i--){
            int u = postOrdering[i];
            if(!visited[u]){
                explore2(u, currSCC);
                currSCC++;
            }
        }
        sccCount = currSCC;
        return sccNumbers;
    }
};

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int v, e;
    std::cin >> v >> e;

    std::vector<std::pair<int, int>> edges;
    for(int i = 0; i < e; i++){
        int f, s;
        std::cin >> f >> s;
        f--, s--;
        edges.push_back({f, s});
    }

    SCC scc(v, edges);
    int sccCount = 0;
    scc.kosaraju(sccCount);
    std::cout << sccCount << '\n';
}