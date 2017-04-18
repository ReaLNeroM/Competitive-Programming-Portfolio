#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 60000;
const ll maxk = 200;

static ll n, k;
static ll dp[maxn][maxk];
static ll val[maxn];
static ll par[maxn];
static ll sum[maxn];
std::vector<ll> adj[maxn];
static ll putin[maxn];
static bool used[maxn];

void fillout(ll pos){
	dp[pos][0] = sum[pos];

	priority_queue<pair<ll, ll>> pq;
	
	for(ll i = 0; i < adj[pos].size(); i++){
		ll next = adj[pos][i];
		putin[next] = 0;
		if(next != par[pos]){
			pq.push({dp[next][1] - dp[next][0], next});
		}
	}

	for(ll i = 0; i <= k and !pq.empty(); i++){
		ll next_cost = pq.top().first;
		ll next_ind = pq.top().second;
		pq.pop();

		dp[pos][i + 1] = max(dp[pos][i + 1], dp[pos][i] + next_cost);

		putin[next_ind]++;
		if(putin[next_ind] != k){
			pq.push({
				dp[next_ind][putin[next_ind] + 1] - dp[next_ind][putin[next_ind]]
				, next_ind
			});
		}
	}
	dp[pos][1] = max(0LL, dp[pos][1]);
	for(int i = 1; i <= k; i++){
		dp[pos][i] = max(dp[pos][i], dp[pos][i - 1]);
	}
}

void dfs(ll pos){
    used[pos] = true;

    sum[pos] = val[pos];

	for(ll i = 0; i < adj[pos].size(); i++){
		ll nnext = adj[pos][i];
		if(!used[nnext]){
			par[nnext] = pos;
			dfs(nnext);
			sum[pos] += sum[nnext];
		}
	}

    fillout(pos);
}

int main() {
    std::ios::sync_with_stdio(false);

//    freopen("A.IN", "r", stdin);
    std::cin >> n >> k;

    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
    	for(ll j = 0; j < maxk; j++){
            dp[i][j] = -1000000000000000000;
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

    cout << dp[0][k];
    return 0;
}
