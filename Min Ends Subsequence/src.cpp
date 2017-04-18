#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 1e2;
int val[maxn];
int seg[16 * maxn];
int laz[16 * maxn];
int n;

int res = 0;

void propagate(int ind){
    seg[2 * ind + 1] += laz[ind];
    seg[2 * ind + 2] += laz[ind];
    laz[2 * ind + 1] += laz[ind];
    laz[2 * ind + 2] += laz[ind];
    
    laz[ind] = 0;
}

void update(int l, int r, int ind = 0, int cl = 0, int cr = n - 1){
    propagate(ind);
    
    if(l <= cl and cr <= r){
        seg[ind] += 1;
        laz[ind] += 1;
        return;
    } else if(r < cl or cr < l){
        return;
    }
    
    int mid = (cl + cr) / 2;
    
    update(l, r, 2 * ind + 1, cl     , mid);
    update(l, r, 2 * ind + 2, mid + 1, cr );
    
    seg[ind] = std::max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int l, int r, int ind = 0, int cl = 0, int cr = n - 1){
    propagate(ind);
    
    if(l <= cl and cr <= r){
        return seg[ind];
    } else if(r < cl or cr < l){
        return 0;
    }
    
    int mid = (cl + cr) / 2;
    
    return max(query(l, r, 2 * ind + 1, cl     , mid),
               query(l, r, 2 * ind + 2, mid + 1, cr ));
}

int main(){
    ios::sync_with_stdio(false);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }
    
    for(int x = 0; x < 2; x++){
        vector<int> v;
        v.push_back(val[0]);
            
        for(int i = 1; i < n; i++){
            int l = 0, r = v.size() - 1;
            int best = -1;
            
            while(l <= r){
                int mid = (l + r) / 2;
                
                if(v[mid] <= val[i]){
                    l = mid + 1;
                    best = mid;
                } else {
                    r = mid - 1;  
                }
            }
            
            if(1 <= best + 1){
                res = std::max(res, query(1, best + 1) + 2);
            }
        
            if(v[v.size() - 1] < val[i]){
                v.push_back(val[i]);
            } else {
                int l = 0, r = v.size() - 1;
                int best = v.size() - 1;
                while(l <= r){
                    int mid = (l + r) / 2;
                    
                    if(v[mid] <= val[i]){
                        l = mid + 1;
                    } else {
                        best = mid;
                        r = mid - 1;
                    }
                }
                update(best + 1, v.size());
            }
        }
        
        reverse(val, val + n);
        fill(seg, seg + 16 * maxn, 0);
        fill(laz, laz + 16 * maxn, 0);
    }
    
    res = std::max(res, std::min(2, n));
    std::cout << res;
}