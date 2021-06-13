#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;

typedef ll Flow;
struct Edge {
    int dest, back;
    Flow f, c;
};

struct PushRelabel {
    vector<vector<Edge>> g;
    vector<Flow> ec;
    vector<Edge*> cur;
    vector<vi> hs; vi H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

    void add_edge(int s, int t, Flow cap, Flow rcap=0) {
        if (s == t) return;
        g[s].push_back({t, sz(g[t]), 0, cap});
        g[t].push_back({s, sz(g[s])-1, 0, rcap});
    }

    void add_flow(Edge& e, Flow f) {
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f; e.c -= f; ec[e.dest] += f;
        back.f -= f; back.c += f; ec[back.dest] -= f;
    }
    Flow maxflow(int s, int t) {
        int v = sz(g); H[s] = v; ec[t] = 1;
        vi co(2*v); co[0] = v-1;
        rep(i,0,v) cur[i] = g[i].data();
        trav(e, g[s]) add_flow(e, e.c);

        for (int hi = 0;;) {
            while (hs[hi].empty()) if (!hi--) return -ec[s];
            int u = hs[hi].back(); hs[hi].pop_back();
            while (ec[u] > 0)  // discharge u
                if (cur[u] == g[u].data() + sz(g[u])) {
                    H[u] = 1e9;
                    trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
                        H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        rep(i,0,v) if (hi < H[i] && H[i] < v)
                            --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
                    add_flow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
        }
    }
    bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

const int maxn = 45;
vector<vector<int>> yard;

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};

class DefendTheHouse {
public:
    int minimumCost(int houseRow, int houseCol, vector<string> yardString){
        yard.resize(yardString.size());
        for(int i = 0; i < yardString.size(); i++){
            int curr = 0;
            for(int j = 0; j <= yardString[i].size(); j++){
                if(j == yardString[i].size() or yardString[i][j] == ';'){
                    yard[i].push_back(curr);
                    curr = 0;
                } else {
                    curr *= 10;
                    curr += yardString[i][j] - '0';
                }
            }
        }

        int vs = yard.size() * yard[0].size() * 2 + 2;
        PushRelabel graph(vs);
        int source = vs - 2;
        int sink = vs - 1;
        yard[houseRow][houseCol] = 1000000000;
        for(int i = 0; i < yard.size(); i++){
            for(int j = 0; j < yard[i].size(); j++){
                int in = (i * yard[0].size() + j) * 2;
                int out = in + 1;
                if(i == 0 or i == yard.size() - 1 or j == 0 or j == yard[0].size() - 1){
                    // connect to sink
                    graph.add_edge(out, sink, 1000000000);
                }
                if(i == houseRow and j == houseCol){
                    graph.add_edge(source, in, 1000000000);
                }
                graph.add_edge(in, out, yard[i][j]);

                for(int k = 0; k < 4; k++){
                    int ai = i + ay[k];
                    int aj = j + ax[k];
                    int ain = (ai * yard[0].size() + aj) * 2;
                    int aout = ain + 1;
                    if(0 <= ai and ai < yard.size() and 0 <= aj and aj < yard[0].size()){
                        graph.add_edge(out, ain, 1000000000);
                        graph.add_edge(aout, in, 1000000000);
                    }
                }
            }
        }

        return (int) graph.maxflow(source, sink);
    }
};
