#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 300000 + 1e2;
int val[maxn];
int res[maxn];
int height[maxn];
std::set<std::pair<int, int> > s[maxn];
std::set<std::pair<int, int> > *ptr[maxn];
std::vector<int> adj[maxn];
std::pair<int, int> push_update[maxn];

void dfs(int pos, int par){
    if(par == -1){
        height[pos] = 0;
    } else {
        height[pos] = height[par] + 1;
    }

    for(int i = 0; i < adj[pos].size(); i++){
        int next = adj[pos][i];

        dfs(next, pos);
    }
}

void insert(std::set<std::pair<int, int> > &a, std::pair<int, int> c, int here){
    a.insert(c);
    std::set<std::pair<int, int> >::iterator start = a.find(c);

    bool deleted = false;
    if (start != a.begin()){
        std::set<std::pair<int, int> >::iterator ite = start;
        --ite;

        if((*ite).second >= c.second){
			res[c.first] = std::max(0, height[c.first] - height[here] - 1);
            a.erase(start);
            deleted = true;
        }
    }

    if(!deleted){
        std::set<std::pair<int, int> >::iterator ite = start;
        ++ite;
        while (ite != a.end()){
            if((*ite).second <= c.second){
                res[(*ite).first] = height[(*ite).first] - height[here] - 1;
                std::set<std::pair<int, int> >::iterator sec = ite;
                ite++;
                a.erase(sec);
            } else {
                break;
            }
        }
    }
}

void dfs2(int pos){
    for(int i = 0; i < adj[pos].size(); i++){
        int next = adj[pos][i];

        dfs2(next);
        if((*ptr[pos]).size() < (*ptr[next]).size()){
            std::swap(ptr[pos], ptr[next]);
        }

        while(!(*ptr[next]).empty()){
            insert(*ptr[pos], *(*ptr[next]).begin(), pos);
            (*ptr[next]).erase((*ptr[next]).begin());
        }
    }

    insert(*ptr[pos], push_update[pos], pos);

    if(pos == 0){
        while(!(*ptr[pos]).empty()){
            res[(*(*ptr[pos]).begin()).first] = height[(*(*ptr[pos]).begin()).first];
            (*ptr[pos]).erase((*ptr[pos]).begin());
        }
    }
}

int main(){
    int n;
    std::cin >> n;
    n++;

    std::cin >> val[0];

    for(int i = 1; i < n; i++){
        int par;
        std::cin >> val[i] >> par;

        adj[par].push_back(i);
    }

    dfs(0, -1);
    for(int i = 0; i < n; i++){
        push_update[i] = {i, val[i]};
        ptr[i] = &s[i];
    }

    dfs2(0);

    for(int i = 1; i < n; i++){
    	std::cout << res[i] << '\n';
    }
}
