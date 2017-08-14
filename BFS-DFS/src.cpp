#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 4096;
int bfs[maxn];
int dfs[maxn];
std::vector<std::vector<int> > v;
std::vector<int> adj[maxn];
int n;
bool usedbfs[maxn];
bool useddfs[maxn];
bool used[maxn];

bool bfs_attempt(){
    int curr = 0;
    
    std::queue<int> q;
    q.push(0);
    usedbfs[0] = true;

    while(!q.empty()){
        int fr = q.front();
        q.pop();
        if(bfs[curr] != fr){
            return false;
        }
        curr++;
        
        for(int i = 0; i < adj[fr].size(); i++){
            int next = adj[fr][i];
            
            if(!usedbfs[next]){
                usedbfs[next] = true;
                q.push(next);
            }
        }
    }
    
    return true;
}

int curr = 0;

bool do_dfs(int pos){
	useddfs[0] = true;
    if(dfs[curr] != pos){
        return false;
    }
    curr++;
    
    for(int i = 0; i < adj[pos].size(); i++){
        int next = adj[pos][i];
        
        if(!useddfs[next]){
            useddfs[next] = true;
            if(!do_dfs(next)){
            	return false;
            }
        }
    }
    
    return true;
}

int main(){
    std::ios::sync_with_stdio(false);
    
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> bfs[i];
        bfs[i]--;
        if(i != 0){
     		v.push_back({0, bfs[i]});
     		adj[0].push_back(bfs[i]);
     		adj[bfs[i]].push_back(0);
        }
    }
    for(int i = 0; i < n; i++){
        std::cin >> dfs[i];
        dfs[i]--;
        if(i >= 2){
        	v.push_back({dfs[i - 1], dfs[i]});
        	adj[dfs[i - 1]].push_back(dfs[i]);
        	adj[dfs[i]].push_back(dfs[i - 1]);
        }
    }
    
    if(bfs_attempt() and do_dfs(0)){
        std::cout << v.size() << std::endl;
        
        for(int i = 0; i < v.size(); i++){
            std::cout << v[i][0] + 1 << ' ' << v[i][1] + 1 << '\n';
        }
    } else {
        std::cout << -1 << std::endl;
    }
}