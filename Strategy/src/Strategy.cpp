#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
ll f(ll a, ll b, ll k){
    ll accul = 1;
 
    while(accul <= k){
        ll made = 0;
 
        if(accul == k){
            return a;
        } else if(accul + 1 == k){
            return b;
        }
 
        if(a == 0 or b == 0 or b > a){
            ll temp = abs(b - a);
            a = b;
            b = temp;
            accul++;
        } else if(a > b){
            made = a / b;
 
            ll size;
 
            //accul, accul + 2, accul + 3, accul + 5... are a - b * diff
            //accul + 1, accul + 4, accul + 7 are b
            if(made % 2 == 1){
                size = 2 + (made - 1) / 2 * 3;
                if(accul <= k and k < accul + size){
                    if((k - accul) % 3 == 0){
                        return a - (k - accul) / 3 * 2 * b;
                    } else if((k - accul) % 3 == 1){
                        return b;
                    } else if((k - accul) % 3 == 2){
                        return a - ((k - accul) / 3 * 2 + 1) * b;
                    }
                }
                accul += size - 1;
                a %= b;
                swap(a, b);
            } else {
                size = made / 2 * 3;
 
                if(accul <= k and k < accul + size){
                    if((k - accul) % 3 == 0){
                        return a - (k - accul) / 3 * 2 * b;
                    } else if((k - accul) % 3 == 1){
                        return b;
                    } else if((k - accul) % 3 == 2){
                        return a - ((k - accul) / 3 * 2 + 1) * b;
                    }
                }
 
                accul += size - 1;
                a %= b;
                b = a + b;
                swap(a, b);
            }
        } else if(a == b){
            if((accul + 2) % 3 == k % 3){
                return 0;
            } else {
                return a;
            }
        }
    }
}
 
int main(){
    ll a, b, k;
    cin >> a >> b >> k;
 
    cout << f(a, b, k);
}