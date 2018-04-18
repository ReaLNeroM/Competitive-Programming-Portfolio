#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
std::string val[maxn];
int n;
double res = 0;

bool cmp(std::string& a, std::string& b){
    for(int i = 0; i < std::min(a.size(), b.size()); i++){
        if(a[i] < b[i]){
            return true;
        } else if(a[i] > b[i]){
            return false;
        }
    }

    return (a.size() <= b.size());
}

void gen(ll pos, ll l, ll r){
	int found[27];
    std::fill(found, found + 27, 0);

    ll epten_start_l = l;

    if(val[l].size() == pos){
        found[26]++;
        l++;
    }

    if(r < l){
        return;
    }
    
    ll start_l = l;

    for(int i = 0; i < 26; i++){
        char need = 'a' + i;

        int bound_l = l;
        int bound_r = r;
        int latest = l - 1;
        
        while(bound_l <= bound_r){
            int mid = (bound_l + bound_r) / 2;

            if(val[mid][pos] <= need){
                latest = mid;
                bound_l = mid + 1;
            } else {
                bound_r = mid - 1;
            }
        }

        found[i] = latest - l + 1;
        l = latest + 1;
    }

    double sum = (double) r - epten_start_l + 1.0;
    
    for(int i = 0; i < 27; i++){
        sum -= found[i];
        res += (double) pos * (double) sum * (double) found[i];
    }

    l = start_l;
    for(int i = 0; i < 26; i++){
    	if(found[i] != 0){
			gen(pos + 1, l, l + found[i] - 1);
			l += found[i];
    	}
    }
}

int main(){
    std::ios::sync_with_stdio(false);

    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }
    
    std::sort(val, val + n, cmp);

    gen(0, 0, n - 1);

    std::cout.precision(9);
    std::cout << std::fixed << 2.0 * res / ((double) n) / ((double) (n - 1)) << '\n';
}
