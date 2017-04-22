#include <bits/stdc++.h>
  
typedef long long ll;
  
const int maxn = 35;
std::vector<int> block[maxn];
int affect[maxn];
int v, e;
  
int dfs(int pos, int used){
    if(pos == v){
        return 1;
    }
    if(!affect[pos]){
        return 2 * dfs(pos + 1, used);
    }
  
    int res = 0;
    res += dfs(pos + 1, used);
  
    bool good = true;
    for(int i = 0; i < block[pos].size(); i++){
        if((used & block[pos][i]) == block[pos][i]){
            good = false;
        }
    }
  
    if(good){
        res += dfs(pos + 1, used | (1 << pos));
    }
  
    return res;
}
  
int main(){
    std::ios::sync_with_stdio(false);
  
    std::cin >> v >> e;
  
    std::vector<std::pair<int, int> > edg;
    for(int i = 0; i < e; i++){
        int f, s;
        std::cin >> f >> s;
        if(f > s){
            std::swap(f, s);
        }
  
        edg.push_back({f - 1, s - 1});
    }
  
    for(int i = 0; i < e; i++){
        for(int j = 0; j < e; j++){
            for(int k = 0; k < e; k++){
                if(edg[i].first == edg[j].first and edg[i].second == edg[k].second and edg[j].second == edg[k].first){
                    int biggest = std::max(edg[i].first, std::max(edg[i].second, edg[j].second));
                    block[biggest].push_back((1 << edg[i].first) + (1 << edg[i].second) + (1 << edg[j].second) - (1 << biggest));
                    affect[edg[i].first] = affect[edg[i].second] = affect[edg[j].second] = true;
                }
            }
        }
    }
  
    std::cout << dfs(0, 0);
}