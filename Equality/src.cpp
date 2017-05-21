#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
std::map<int, int> app;
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n, k;
    std::cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
        app[val[i]]++;
    }
    
    auto l = app.begin(), r = app.end();
    r--;
    
    while(r->first - l->first > k){
        if(app[l->first] == app[r->first]){
            res += app[l->first];
            
            app[l->first + 1] += app[l->first];
            app[r->first - 1] += app[r->first];
            
            app.erase(l), app.erase(r);
        } else if(app[l->first] > app[r->first]){
            res += app[r->first];
            
            app[l->first] -= app[r->first];
            app[l->first + 1] += app[r->first];
            app[r->first - 1] += app[r->first];
            
            app.erase(r);
        } else {
            res += app[l->first];
            
            app[r->first] -= app[l->first];
            app[r->first - 1] += app[l->first];
            app[l->first + 1] += app[l->first];
            
            app.erase(l);
        }  
        
        l = app.begin(), r = app.end();
        r--;
    }
    
    std::cout << res;
}