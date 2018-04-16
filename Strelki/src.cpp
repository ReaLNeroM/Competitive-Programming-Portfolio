#include <bits/stdc++.h>
 
typedef long long ll;
 
struct dsu {
    dsu* parent = this;
    int rank = 0;
    int ind = 0;
 
    dsu* head(){
        if(parent != parent->parent){
            parent = parent->head();
        }
 
        return parent;
    }
 
    bool merge(dsu* sec){ //returns whether equal
        dsu* fir = head();
        sec = sec->head();
 
        if(fir == sec){
            return true;
        }
 
        if(fir->rank > sec->rank){
            sec->parent = fir;
        } else if(fir->rank < sec->rank){
            fir->parent = sec;
        } else {
            sec->parent = fir;
            fir->rank++;
        }
 
        return false;
    }
};
 
const int maxn = 300005;
static int out[maxn];
static int deleted_at[maxn];
static dsu uni[maxn];
static std::string res[maxn];
static int event[maxn][2];
 
int main(){
    std::ios::sync_with_stdio(false);
 
    int n;
    std::cin>>n;
    std::fill(deleted_at, deleted_at + maxn, -1);
    std::fill(res, res + maxn, "");
 
    for(int i = 0; i < n; i++){
        std::cin >> out[i];
        out[i]--;
    }
 
    int q;
    std::cin >> q;
 
    for(int i = 0; i < q; i++){
        std::cin >> event[i][0] >> event[i][1];
        event[i][1]--;
 
        if(event[i][0] == 2){
            deleted_at[event[i][1]] = i;
        }
    }
 
    for(int i = 0; i < q - i - 1; i++){
        std::swap(event[i][0], event[q - i - 1][0]);
        std::swap(event[i][1], event[q - i - 1][1]);
    }
 
    for(int i = 0; i < n; i++){
        uni[i].ind = i;
    }
 
    for(int i = 0; i < n; i++){
        if(deleted_at[i] == -1 and out[i] != -1){
            int next = uni[out[i]].head()->ind;
            bool get = uni[i].merge(&uni[out[i]]);
            uni[i].head()->ind = next;
 
            if(get){
                uni[i].head()->ind = -1;
            }
        }
    }
 
    for(int i = 0; i < q; i++){
        if(event[i][0] == 1){
            int get = uni[event[i][1]].head()->ind;
 
            if(get == -1){
                res[q - i - 1] = "CIKLUS\n";
            } else {
                std::stringstream ostr;
                ostr << get + 1 << "\n";
                res[q - i - 1] = ostr.str();
            }
        } else {
            int next = uni[out[event[i][1]]].head()->ind;
            bool get = uni[event[i][1]].merge(&uni[out[event[i][1]]]);
            uni[event[i][1]].head()->ind = next;
 
            if(get){
                uni[event[i][1]].head()->ind = -1;
            }
        }
    }
 
    for(int i = 0; i < q; i++){
        if(res[i] != ""){
            std::cout << res[i];
        }
    }
}