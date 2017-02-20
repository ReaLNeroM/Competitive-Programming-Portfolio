#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e6;

vector<ll> adj[maxn];
ll strength[maxn];
ll weight[maxn];
ll subtree_sum[maxn];
ll subtree_broken[maxn];
ll leftout[maxn];
ll edg[maxn][4];

bool possible = true;

void dfs(ll pos){
	for(ll i = 0; i < adj[pos].size(); i++){
		ll next = adj[pos][i];

   		dfs(next);
		subtree_sum[pos] += subtree_sum[next] + weight[next];
		subtree_broken[pos] += subtree_broken[next];
	}

	if(strength[pos] < subtree_sum[pos]){
		subtree_broken[pos]++;
	}
}

ll dfs2(ll pos, ll carry){
	ll start_carry = carry;

	for(ll i = 0; i < adj[pos].size(); i++){
		ll next = adj[pos][i];

		if(subtree_broken[next]){
			ll lowered = dfs2(next, max(0LL, subtree_sum[next] - strength[next]));
			subtree_sum[pos] -= lowered;
			carry -= lowered;
			//dfs2 helped out by reducing some of its weight
		}
	}
	for(ll i = 0; i < adj[pos].size(); i++){
		ll next = adj[pos][i];

		ll lowered = dfs2(next, max(0LL, carry));
		subtree_sum[pos] -= lowered;
		carry -= lowered;
		//dfs2 helped out by reducing some of its weight
	}

	if(carry > 0){
		ll reduce = min(weight[pos] - 1, min(strength[pos], min(strength[pos] - subtree_sum[pos], carry)));
		if(reduce > 0){
			carry -= reduce;
			weight[pos] -= reduce;
			strength[pos] -= reduce;
		}
	}

	if(strength[pos] < subtree_sum[pos]){
		possible = false;
	}

	return start_carry - max(0LL, carry);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	for(ll i = 0; i < n - 1; i++){
		ll f, s, vweight, vstrength;
		cin >> f >> s >> vweight >> vstrength;
		f--, s--;

		edg[i][0] = f;
		edg[i][1] = s;
		edg[i][2] = vweight;
		edg[i][3] = vstrength;

		adj[f].push_back(s);
		strength[s] = vstrength;
		weight[s] = vweight;
	}
	strength[0] = 1e18;

	dfs(0);
	dfs2(0, 0);

	if(possible){
		cout << n << '\n';
		for(ll i = 0; i < n - 1; i++){
			cout << edg[i][0] + 1 << ' ' << edg[i][1] + 1 << ' ' <<
					weight[edg[i][1]] << ' ' << strength[edg[i][1]] << '\n';
		}
	} else {
		cout << -1 << endl;
	}
}

