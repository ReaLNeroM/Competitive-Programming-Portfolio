#include <bits/stdc++.h>

const int maxn = 1000;
int n, block;
int used[maxn];
bool blocked[maxn][maxn];
int match[maxn];

int dfs(int pos){
    if(!used[pos]){
        used[pos] = true;
        for(int i = 0; i < n; i++){
            if(!blocked[i][pos] and (match[i] == -1 or dfs(match[i]))){
                match[i] = pos;
                return 1;
            }
        }
 
    }
 
    return 0;
}

int main(){
    std::cin >> n >> block;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            blocked[i][j] = false;
        }
    }

    for(int i = 0; i < block; i++){
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        blocked[a][b] = true;
    }

    for(int i = 0; i < n; i++){
        match[i] = -1;
    }

    int res = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            used[j] = false;
        }

        dfs(i);
    }

    for(int i = 0; i < n; i++){
        if(match[i] != -1){
            res++;
        }
    }

    std::cout << res << std::endl;
}