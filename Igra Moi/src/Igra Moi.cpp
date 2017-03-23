#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 55;
int blocked[maxn];
vector<vector<int>> v;
vector<int> used;
int allowed[maxn];
int n;
 
void dfs(int pos){
    for(int j = 1; j <= 6; j++){
        if(!used[(pos + j) % n] and allowed[j]){
            used[(pos + j) % n] = true;
            dfs((pos + j) % n);
            used[(pos + j) % n] = false;
        } else if(used[(pos + j) % n] == -1){
            v.push_back(used);
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     
    cin >> n;
     
    for(int i = 0; i < n; i++){
        cin >> blocked[i];
    }
 
    int moves;
    cin >> moves;
    for(int j = 0; j < moves; j++){
        int jump;
        cin >> jump;
        allowed[jump] = true;
    }

    used.resize(n);
    for(int i = 0; i < 6; i++){
        fill(used.begin(), used.end(), 0);
        for(int j = 0; j <= i; j++){
            used[j] = true;
        }
        for(int j = 0; j < n; j++){
            used[j] = blocked[j] | used[j];
        }
        used[i] = -1;
        dfs(i);
    }
 
    cout << v.size();    
}