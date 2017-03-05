#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;
int dist[maxn];
bool done[maxn];
bool usedportal[maxn];
int type[maxn];
vector<int> port[15];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

    int n, t;
    cin >> n >> t;

    for(int i = 0; i < n; i++){
        dist[i] = 1e9;
        done[i] = false;
    }
    for(int i = 0; i < n; i++){
        cin >> type[i];
        type[i]--;
        port[type[i]].push_back(i);
    }
    dist[0] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({-dist[0], 0});

    while(!pq.empty()){
        int frdist = -pq.top().first, frind = pq.top().second;
        pq.pop();

        if(done[frind]){
            continue;
        }
        dist[frind] = frdist;
        done[frind] = true;

        if(frind > 0){
            int nextdist = frdist + 1, nextind = frind - 1;
            pq.push({-nextdist, nextind});
        }
        if(frind < n - 1){
            int nextdist = frdist + 1, nextind = frind + 1;
            pq.push({-nextdist, nextind});
        }
        if(!usedportal[type[frind]]){
            usedportal[type[frind]] = true;
            for(int i = 0; i < port[type[frind]].size(); i++){
                int nextdist = frdist + t, nextind = port[type[frind]][i];
                pq.push({-nextdist, nextind});
            }
        }
    }

    cout << dist[n - 1];
}
