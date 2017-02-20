#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>	ordered_set;

const int maxn = 1e5;
int val[maxn];
int res[maxn];
vector<int> adj[maxn];
ordered_set s[maxn];
ordered_set* real_pos[maxn];

void dfs(int pos){
	real_pos[pos] = &s[pos];

	int best_pos = -1;
	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i];

		dfs(next);

		if(real_pos[pos]->size() < real_pos[next]->size()){
			real_pos[pos] = real_pos[next];
			best_pos = i;
		}
	}
	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i];

		if(i != best_pos){
			ordered_set::iterator ite = real_pos[next]->begin();
			while(ite != real_pos[next]->end()){
				real_pos[pos]->insert(*ite);
				ite++;
			}
		}
	}

	int search_value = val[pos];

	res[pos] = real_pos[pos]->size() - real_pos[pos]->order_of_key({search_value + 1, -1});
	real_pos[pos]->insert({search_value, pos});
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> val[i];
	}

	for	(int i = 1; i < n; i++){
		int par;
		cin >> par;
		par--;
		adj[par].push_back(i);
	}

	dfs(0);

	for(int i = 0; i < n; i++){
		cout << res[i] << '\n';
	}
}

