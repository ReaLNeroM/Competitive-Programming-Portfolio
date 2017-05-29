#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 100;
const int log_maxn = 30;
int level[maxn];
int skip[maxn][log_maxn];
std::vector<int> adj[maxn];
ll res[maxn];

void dfs(int pos, int par, int curr_level = 0){
	skip[pos][0] = par;
	level[pos] = curr_level;

	for(int i = 0; i < adj[pos].size(); i++){
		int nnext = adj[pos][i];

		if(nnext != par){
			dfs(nnext, pos, curr_level + 1);
		}
	}
}

int query(int pos, int steps){
	for(int i = log_maxn, jump = (1 << log_maxn); i >= 0; i--, jump /= 2){
		if(jump <= steps){
			pos = skip[pos][i];
			steps -= jump;
		}
	}

	return pos;
}

int main(){
    std::ios::sync_with_stdio(false);
    
    int n, q;
    std::cin >> n >> q;
    
    for(int i = 0; i < n - 1; i++){
    	int f, s;
        std::cin >> f >> s;

        f--, s--;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }

    dfs(0, -1);

    for(int i = 1; i < log_maxn; i++){
    	for(int j = 0; j < n; j++){
    		//check for -1
    		if(skip[j][i - 1] == -1){
    			skip[j][i] = -1;
    		} else {
	    		skip[j][i] = skip[skip[j][i - 1]][i - 1];
    		}
    	}
    }

    for(int i = 0; i < q; i++){
    	int v_orig[3];
    	int v[3];
    	std::cin >> v_orig[0] >> v_orig[1] >> v_orig[2];
    	v_orig[0]--, v_orig[1]--, v_orig[2]--;
    	v[0] = v_orig[0], v[1] = v_orig[1], v[2] = v_orig[2];

    	bool path = false;x
    	for(int j = 0; j < 3; j++){
    		for(int k = 0; k < 3; k++){
    			if(j != k and level[v[j]] > level[v[k]] and query(v[j], level[v[j]] - level[v[k]]) == v[k]){
    				std::cout << v[j] + 1 << ' ' << v[k] + 1 << std::endl;
    				return 0;
    				path = true;
    				for(int l = 0; l < 3; l++){
    					if(j != k and j != l and k != l){
    						std::cout << v[k] + 1 << ' ' << std::abs(level[v[j]] - level[v[k]]) + std::abs(level[v[k]] - level[v[l]]) << std::endl;
		    				j = 3, k = 3, l = 3;
    					}
    				}
    			}
    		}
    	}

    	if(!path){
    		int least = 0;
    		for(int j = 0; j < 3; j++){
    			if(level[v[j]] < level[v[least]]){
    				least = j;
    			}
    		}

    		bool vertical_star = true;
    		for(int j = 0; j < 3; j++){
    			if(j != least and query(v[j], level[v[j]] - level[v[least]]) != v[least]){
    				vertical_star = false;
    			}
    		} 

    		if(vertical_star){
	    		std::swap(v[2], v[least]);
    		}

			//solve for LCA of v[0] and v[1]
    		if(level[v[0]] > level[v[1]]){
    			v[0] = query(v[0], level[v[0]] - level[v[1]]);
    		} else if(level[v[1]] > level[v[0]]){
    			v[1] = query(v[1], level[v[1]] - level[v[0]]);
    		}

    		int lca = -1;
    		if(v[0] == v[1]){
    			lca = v[0];
    		} else {
	    		for(int j = 29; j >= 0 and v[0] != v[1]; j--){
	    			if(skip[v[0]][j] == skip[v[1]][j]){
	    				lca = skip[v[0]][j];
	    			} else {
	    				v[0] = skip[v[0]][j];
	    				v[1] = skip[v[1]][j];
	    			}
	    		}
    		}

    		int res = 0;
    		for(int j = 0; j < 3; j++){
    			res += std::abs(level[v_orig[j]] - level[lca]);
    		}

    		std::cout << lca + 1 << ' ' << res << '\n';
    	}
    }
}