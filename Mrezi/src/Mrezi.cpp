#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
 
using namespace std;
typedef long long ll;
 
struct e {
    int first, second, cost;
 
    bool operator()(e const &x, e const &y) const {
        return x.cost > y.cost;
    }
};
 
e make_e(int f, int s, int c){
    e copy;
    copy.first = f;
    copy.second = s;
    copy.cost = c;
 
    return copy;
}
 
int main() {
    int pamphlets;
    cin >> pamphlets;
 
    vector<int> res;
 
    for(int i = 0; i < pamphlets; i++){
        int n, left;
        cin >> n >> left;
 
        priority_queue<e, vector<e>, e> pq;
        for(int j = 0; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int c;
                cin >> c;
 
                pq.push(make_e(j, k, c));
            }
        }
 
        vector<pair<int, int> > adj[n];
 
        bool possible = true;
 
        while(!pq.empty()){
            e copy = pq.top();
            pq.pop();
 
            int dist[n];
            for(int j = 0; j < n; j++){
                dist[j] = 1000000;
            }
            dist[copy.first] = 0;
 
            priority_queue<e, vector<e>, e> pqq;
            pqq.push(make_e(copy.first, 0, 0));
 
            while(!pqq.empty() and pqq.top().first != copy.second){
                int next = pqq.top().first;
                pqq.pop();
 
                for(int j = 0; j < adj[next].size(); j++){
                    if(dist[next] + adj[next][j].second < dist[adj[next][j].first]){
                        dist[adj[next][j].first] = dist[next] + adj[next][j].second;
                        pqq.push(make_e(adj[next][j].first, 0, dist[adj[next][j].first]));
                    }
                }
            }
 
            if(dist[copy.second] > copy.cost){
                if(left > 0){
                    adj[copy.first].push_back(make_pair(copy.second, copy.cost));
                    adj[copy.second].push_back(make_pair(copy.first, copy.cost));
                    left--;
                } else {
                    possible = false;
                    break;
                }
            } else if(dist[copy.second] < copy.cost){
                possible = false;
                break;
            }
        }
 
        if(!possible){
            res.push_back(i + 1);
        }
    }
 
    cout << res.size() << endl;
 
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i] << endl;
    }
    return 0;
}