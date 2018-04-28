#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 35;
int mat[maxn][maxn];
int id[maxn];
int tagged[maxn];

int main(){
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        mat[a][b] = true;
    }

	for(int k = 0; k < maxn; k++){
		for(int i = 0; i < maxn; i++){
			for(int j = 0; j < maxn; j++){
				mat[i][j] |= mat[i][k] & mat[k][j];
			}
		}
	}

    int printed = 0;

    for(int i = 0; i < maxn; i++){
    	if(!tagged[i]){
    		id[i] = i;
    	}

    	if(!tagged[i] and mat[i][i]){
            std::vector<int> scc;

            for(int j = 0; j < maxn; j++){
                if(!tagged[j] and mat[i][j] and mat[j][i]){
                    scc.push_back(j);
                    id[j] = i;
                    tagged[j] = true;
                }
            }

            printed += scc.size();
        }
    }

    for(int i = 0; i < maxn; i++){
        if(id[i] == i){
            for(int j = 0; j < maxn; j++){
                if(id[j] == j and j != i){
                    bool nema_drugo = true;

                    for(int k = 0; k < maxn; k++){
                        if(k != i and k != j and id[k] == k){
                            if(mat[i][k] and mat[k][j]){
                                nema_drugo = false;
                            }
                        }
                    }

                    if(mat[i][j] and nema_drugo){
                        printed++;
                    }
                }
            }
        }
    }

    std::cout << printed << '\n';

}
