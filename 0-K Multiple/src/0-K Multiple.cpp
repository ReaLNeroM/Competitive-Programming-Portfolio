#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
bool used[maxn];
ll par[maxn];
ll step[maxn];
ll res = 0;

int main(){
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    fill(used, used + n, false);
    queue<int> q;
    
    q.push(k);
    used[k] = true;
    par[k] = -1;
    
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        
        if(fr == 0){
            break;
        }
        
        int nnext = fr * 10 + k;
        if(!used[nnext % n]){
            used[nnext % n] = true;
            par[nnext % n] = fr;
            step[nnext % n] = k;
            q.push(nnext % n);
        }
        
        nnext = fr * 10;
        if(!used[nnext % n]){
            used[nnext % n] = true;
            par[nnext % n] = fr;
            step[nnext % n] = 0;
            q.push(nnext % n);
        }
    }
    
    string s;
    int pos = 0;
    
    while(pos != k){
        s += '0' + step[pos];
        pos = par[pos];
    }
    s += '0' + k;
    
    reverse(s.begin(), s.end());
    
    cout << s;
}