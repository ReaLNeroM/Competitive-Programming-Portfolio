#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
ll n;
ll val[maxn];
ll size[maxn];
ll permutations[maxn];
ll par[maxn];
ll factorial[maxn];
ll inverse_factorial[maxn];
ll above[maxn];
std::vector<ll> adj[maxn];
ll res = 0;

ll modular_exponentiation(ll a, ll b, ll m){
	ll res = 1;

	while(b){
		if(b & 1){
			res *= a;
			res %= mod;
		}

		a *= a;
		a %= mod;

		b /= 2;
	}

	return res;
}

void calculate_factorials(){
	factorial[0] = 1;
	inverse_factorial[0] = 1;

	for(ll i = 1; i <= n; i++){
		factorial[i] = factorial[i - 1] * i % mod;
		inverse_factorial[i] = inverse_factorial[i - 1] * modular_exponentiation(i, mod - 2, mod) % mod;
	}
}

ll binomial(ll a, ll b){
	return (factorial[a] * inverse_factorial[b]) % mod * inverse_factorial[a - b] % mod;
}

ll combine(ll pa, ll pb, ll sa, ll sb){
	ll temp_res = pa * pb;
	temp_res %= mod;
	temp_res *= binomial(sa + sb, sb);
	temp_res %= mod;
	return temp_res;
}

void dfs(ll pos){
	size[pos] = 1;
	permutations[pos] = 1;

	for(ll next : adj[pos]){
		if(next != par[pos]){
			par[next] = pos;
			dfs(next);
			permutations[pos] = combine(permutations[pos], permutations[next], size[pos] - 1, size[next]);
			size[pos] += size[next];
		}
	}
}

void rev_dfs(ll pos){
	std::vector<int> prefix(adj[pos].size() + 1, 1), suffix(adj[pos].size() + 1, 1);
	std::vector<int> size_prefix(adj[pos].size() + 1, 1), size_suffix(adj[pos].size() + 1, 1);

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par[pos]){
			prefix[i + 1] = combine(prefix[i], permutations[adj[pos][i]], size_prefix[i] - 1, size[adj[pos][i]]);
			size_prefix[i + 1] = size_prefix[i] + size[adj[pos][i]];
		} else {
			prefix[i + 1] = combine(prefix[i], above[pos], size_prefix[i] - 1, n - size[pos]);
			size_prefix[i + 1] = size_prefix[i] + n - size[pos];
		}
	}

	for(int i = adj[pos].size() - 1; i >= 0; i--){
		if(adj[pos][i] != par[pos]){
			suffix[i] = combine(suffix[i + 1], permutations[adj[pos][i]], size_suffix[i + 1] - 1, size[adj[pos][i]]);
			size_suffix[i] = size_suffix[i + 1] + size[adj[pos][i]];
		} else {
			suffix[i] = combine(suffix[i + 1], above[pos], size_suffix[i + 1] - 1, n - size[pos]);
			size_suffix[i] = size_suffix[i + 1] + n - size[pos];
		}
	}

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par[pos]){
			above[adj[pos][i]] = combine(combine(1, prefix[i], 0, 1), suffix[i + 1], size_prefix[i] - 1, size_suffix[i + 1] - 1);
			rev_dfs(adj[pos][i]);
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);
    
    std::cin >> n;
    
    for(ll i = 0; i < n - 1; i++){
        ll f, s;
        std::cin >> f >> s;
        f--, s--;
        
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    
    calculate_factorials();

    std::fill(above, above + n, 1);
	par[0] = -1;
	dfs(0);
	rev_dfs(0);

	for(int i = 0; i < n; i++){
		res += combine(permutations[i], above[i], size[i] - 1, n - size[i]);
		res %= mod;
	}
    
    std::cout << res << '\n';
}
