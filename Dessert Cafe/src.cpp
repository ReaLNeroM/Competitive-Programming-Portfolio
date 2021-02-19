// https://codeforces.com/gym/102920/problem/C

#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int n, k;
std::vector<int> adj[maxn];
bool apt[maxn];

int good_places = 0;
int dfs(int pos, int par){
    int childs_with_apt = 0;
    int apt_seen = 0;
    for(int next : adj[pos]){
        if(next != par){
            int response = dfs(next, pos);
            if(response != 0){
                childs_with_apt++;
                apt_seen += response;
            }
        }
    }

    if(apt[pos] or childs_with_apt >= 2 or childs_with_apt == 1 and apt_seen != k){
        good_places++;
    }

    if(apt[pos]){
        apt_seen++;
    }

    return apt_seen;
}

int main(){
    std::ios::sync_with_stdio(false);

    std::cin >> n >> k;

    for(int i = 0; i < n - 1; i++){
        int f, s, c;
        std::cin >> f >> s >> c;
        f--, s--;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }

    for(int i = 0; i < k; i++){
        int apt_site;
        std::cin >> apt_site;
        apt_site--;
        apt[apt_site] = true;
    }

    dfs(0, -1);

    std::cout << good_places << '\n';
}