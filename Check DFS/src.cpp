#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
std::set<std::vector<int>> s;
int order[maxn];
bool used[maxn];
std::vector<int> adj[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int v, e;
    std::cin >> v >> e;
    
    for(int i = 0; i < v; i++){
        std::cin >> order[i];
        order[i]--;
    }
    
    for(int i = 0; i < e; i++){
        int fir, sec;
        std::cin >> fir >> sec;
        fir--, sec--;
        adj[fir].push_back(sec);
        adj[sec].push_back(fir);
        s.insert({fir, sec});
        s.insert({sec, fir});
    }
    
    std::stack<int> st;
    
    st.push(0);
    used[0] = true;
    for(int i = 1; i < v; i++){
        used[order[i]] = true;
        while(!st.empty()){
            if(s.find({st.top(), order[i]}) != s.end()){
                st.push(order[i]);
                break;
            } else {
                int fr = st.top();
                for(int j : adj[fr]){
                    if(!used[j]){
                        std::cout << 0 << std::endl;
                        return 0;
                    }
                }
                st.pop();
            }
        }
        
        if(st.empty()){
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    
    std::cout << 1 << std::endl;
}