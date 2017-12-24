#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
std::vector<std::vector<int>> adj[maxn];
int f[maxn];
int c[maxn];
ll res = 0;

std::vector<int> dfs(int pos, int par, int curr_color, int final_color, int up = 0, int down = 0){
	for(auto i : adj[pos]){
		if(i[0] != par){
			auto v = dfs(i[0], pos, i[1], i[2], up + down, 0);
			up -= v[0], down += v[1];
		}
	}

	if(final_color != 2 and curr_color == !final_color){
		if(up == 0 and down == 0){
			down++;
			res++;
		} else if(up){
			up--;
		} else if(down){
			down--;
		}
	} else if(final_color != 2 and curr_color == final_color){
		if(up == 0 and down == 0){
			down++;
			res++;
		} else if(down){

		} else if(up){

		}
	}

	return sum;
}

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n - 1; i++){
    	int a, b, c, f;
        std::cin >> a >> b >> c >> f;
        a--, b--;

        adj[a].push_back({b, c, f});
        adj[b].push_back({a, c, f});
    }

    dfs(0, -1, -1, 2);

    std::cout << res << '\n';
}
