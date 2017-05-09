#include <bits/stdc++.h>
 
typedef long long ll;
 
struct query {
    ll ind;
    ll block;
    ll l, r;
 
    bool operator<(query const &x) const {
        if(block == x.block){
            return r < x.r;
        }
        return block < x.block;
    }
};
 
const ll maxn = 1e6 + 1e2;
ll val[maxn];
ll sq = 174;
query que[maxn];
ll board[maxn];
ll res = 0;
ll ans[maxn];
 
void my_add(ll pos){
    if(board[val[pos]] == 0){
        res++;
    }
    board[val[pos]]++;
}
void my_remove(ll pos){
    board[val[pos]]--;
    if(board[val[pos]] == 0){
        res--;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
 
    for(ll i = 0; i < maxn; i++){
        board[i] = 0;
    }
 
    ll n;
    std::cin >> n;
 
    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
    }
 
    ll q;
    std::cin >> q;
    for(ll i = 0; i < q; i++){
        std::cin >> que[i].l >> que[i].r;
        que[i].l--, que[i].r--;
        que[i].l = std::max(que[i].l, 0LL);
        que[i].r = std::min(n - 1, que[i].r);
        que[i].block = que[i].l / sq;
        que[i].ind = i;
    }
 
    std::sort(que, que + q);
 
    ll l = 0, r = 0;
    my_add(0);
 
    for(ll i = 0; i < q; i++){
        while(r < que[i].r){
            r++;
            my_add(r);
        }
        while(que[i].l < l){
            l--;
            my_add(l);
        }
        while(que[i].r < r){
            my_remove(r);
            r--;
        }
        while(l < que[i].l){
            my_remove(l);
            l++;
        }
        ans[que[i].ind] = res;
    }
 
    std::stringstream str;
    for(ll i = 0; i < q; i++){
        str << ans[i] << '\n';
    }
    std::cout << str.str();
}