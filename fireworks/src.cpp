#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5;
std::vector<std::vector<ll>> adj[maxn];
int par[maxn];
int l[maxn];
  
std::vector<ll> dfs(int pos, int par){
  std::vector<std::vector<ll>> v;

  ll sum = 0;
  
  for(int i = 0; i < adj[pos].size(); i++){
    v.push_back(dfs(adj[pos][i][0], pos));
    sum += v[v.size() - 1][2];
    v[v.size() - 1][0] += l[adj[pos][i][0]];
  }
  
  if(v.empty()){
    return 0;
  }
  
  std::sort(v.begin(), v.end());

  ll pivot = v[v.size() / 2];

  for(int i = 0; i < v.size(); i++){
    sum += std::abs(pivot - v[i]);
  } 

  return sum; 
}

int main(){
  int leaves, junctions;
  std::cin >> leaves >> junctions;

  int n = leaves + junctions;

  for(int i = 0; i < n - 1; i++){
    std::cin >> par[i] >> l[i];
    adj[par[i]].push_back({i, l[i]});
    par[i]--;
  }

  std::cout << dfs(0, -1) << std::endl;
}
