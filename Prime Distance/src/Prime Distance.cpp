#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    ios::sync_with_stdio(false);
    
    int a, b;
    cin >> a >> b;
    
    int res = 0;
    
    for(int i = 2; i * i <= a or i * i <= b; i++){
        while(a % i == 0 and b % i == 0){
            a /= i;
            b /= i;
        }
        while(a % i == 0 or b % i == 0){
            if(a % i == 0){
                a /= i;
            }
            if(b % i == 0){
                b /= i;
            }
            res++;
        }
    }
    
    if(a % b == 0){
        a /= b;
        b = 1;
    } else if(b % a == 0){
        b /= a;
        a = 1;
    }
    if(a != 1){
        res++;
    }
    if(b != 1){
        res++;
    }
    
    cout << res;
}