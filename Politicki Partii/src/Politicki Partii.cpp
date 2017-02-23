#include <iostream>
#include <vector>

typedef long long ll;

ll dpc[50000][151];
ll val[50000];
ll sum[50000];
ll next[50000], child[50000];
std::vector<ll> adj[50000];

bool used[50000];
void dfs(ll pos){
    used[pos] = true;

    sum[pos] = val[pos];

    if(!adj[pos].empty()){
        ll prev = -1;
        for(ll i = 0; i < adj[pos].size(); i++){
            if(!used[adj[pos][i]]){
                if(prev != -1){
                    next[prev] = adj[pos][i];
                } else {
                    child[pos] = adj[pos][i];
                }
                prev = adj[pos][i];
                dfs(adj[pos][i]);
                sum[pos] += sum[adj[pos][i]];
            }
        }
    }
}

ll findc(ll pos, ll left){
    if(dpc[pos][left] == -50000000000001){
        ll res = -50000000000001;

        if(next[pos] == -1){
        	if(child[pos] != -1){
				res = findc(child[pos], left);
        	}
        } else if(child[pos] == -1){
        	res = findc(next[pos], left);
        } else {
			for(ll i = 0; i <= left; i++){
				ll first = sum[pos];

				if(i > 0){
					first = std::max(0LL, findc(child[pos], i) + val[pos]);
				}
				ll second = findc(next[pos], left - i);

				if(first + second > res){
					res = first + second;
				}
			}
        }

        dpc[pos][left] = res;
    }

    return dpc[pos][left];
}

int main() {
    std::ios::sync_with_stdio(false);

    ll n, k;
    std::cin >> n >> k;

    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
        next[i] = child[i] = -1;
        used[i] = false;
        for(ll j = 0; j <= k; j++){
            dpc[i][j] = -50000000000001;
        }
    }

    for(ll i = 0; i < n - 1; i++){
        ll f, s;
        std::cin >> f >> s;
        f--, s--;

        adj[f].push_back(s);
        adj[s].push_back(f);
    }

    dfs(0);

    std::cout << findc(0, k);
    return 0;
}
