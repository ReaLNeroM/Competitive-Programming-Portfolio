#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int n;
int h[maxn];
int candles[maxn];

int res = 0;

bool good(int pos){
    if(pos == 0){
        return true;
    }
    std::map<int, int> m;
    for(int i = 0; i < pos; i++){
        m[candles[i]]++;
    }
    
    std::vector<int> v;
    v.resize(m.rbegin()->first, 0);
    int sum = 0;
    int prev = m.rbegin()->first - 1;
    int ind;
    for(auto i = m.rbegin(); true; i++){
        if(i == m.rend()){
            ind = 0;
            for(int j = ind; j <= prev; j++){
                v[j] = sum;
            }
            prev = ind;
            break;
        } else {
            ind = i->first - 1;
            for(int j = ind; j <= prev; j++){
                v[j] = sum;
            }
            prev = ind;
        }
        sum += i->second;
    }

    std::sort(v.begin(), v.end());
    
    int curr = 0;
    int left = 0;
    for(int i = 0; i < v.size(); i++){
        do {
            if(curr == n){
                return false;
            }
            left += h[curr];
            curr++;
        } while(left < v[i]);
        
        left -= v[i];
    }
    
    return true;
}

int main(){
    std::ios::sync_with_stdio(false);
    
    int evenings;
    std::cin >> n >> evenings;
    
    for(int i = 0; i < n; i++){
        std::cin >> h[i];
    }
    std::sort(h, h + n);
    
    for(int i = 0; i < evenings; i++){
        std::cin >> candles[i];
    }
    
    int l = 0, r = evenings;
    
    while(l <= r){
        int mid = (l + r) / 2;
        
        if(good(mid)){
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }
    
    std::cout << res;
}