#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e2;
int val[maxn][maxn];
int won[maxn];
ll res = 0;

int main(){
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> val[i][j];
            if(val[i][j] == 2){
                won[j]++;
            } else if(val[i][j] == 1){
                won[i]++;
            }
        }
    }
    
    int index = 0;
    for(int i = 0; i < n; i++){
        if(won[i] > won[index]){
            index = i;
        }
    }
    
    cout << index + 1;
}