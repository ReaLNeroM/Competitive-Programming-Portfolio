#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 3e2 + 1e2;
int n;
int x[maxn], y[maxn];
std::vector<int> adj[maxn];
double dp[maxn][maxn][2];
double dist[maxn][maxn];

double dpfunc(int i, int j, bool side){
    if(dp[i][j][side] != -1.0){
        return dp[i][j][side];
    }

    double& ans = dp[i][j][side];
    if(i == j){
        return ans;
    }

    if(i < j and side == 0){
        for(int k : adj[j]){
            if(i < k and k < j){
                ans = std::max(ans, dist[j][k] + std::max(
                    dpfunc(j, k, 1),
                    dpfunc(i, k, 0)
                ));
            }
        }
    } else if(i > j and side == 1){
        for(int k : adj[j]){
            if(j < k and k < i){
                ans = std::max(ans, dist[j][k] + std::max(
                    dpfunc(j, k, 0),
                    dpfunc(i, k, 1)
                ));
            }
        }
    } else if(i < j and side == 1){
        for(int k : adj[j]){
            if(k < i){
                ans = std::max(ans, dist[j][k] + std::max(
                    dpfunc(j, k, 1),
                    dpfunc(i, k, 0)
                ));
            } else if(j < k){
                ans = std::max(ans, dist[j][k] + std::max(
                    dpfunc(j, k, 0),
                    dpfunc(i, k, 1)
                ));
            }
        }
        // everything not in between is accessible
    } else if(i > j and side == 0){
        for(int k : adj[j]){
            if(k < i){
                ans = std::max(ans, dist[j][k] + std::max(
                    dpfunc(j, k, 0),
                    dpfunc(i, k, 1)
                ));
            } else if(j < k){
                ans = std::max(ans, dist[j][k] + std::max(
                    dpfunc(j, k, 1),
                    dpfunc(i, k, 0)
                ));
            }
        }
    }

    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int test_cases;
    std::cin >> test_cases;

    for(int test_case = 1; test_case <= test_cases; test_case++){
        std::cin >> n;

        for(int i = 0; i < n; i++){
            std::cin >> x[i] >> y[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = -10e30;
            }
        }

        int lines;
        std::cin >> lines;

        for(int i = 0; i < lines; i++){
            int f, s;
            std::cin >> f >> s;
            f--, s--;

            adj[f].push_back(s);
            adj[s].push_back(f);

            dist[f][s] = dist[s][f] = std::sqrt(
                double(x[f] - x[s]) * (x[f] - x[s]) +
                double(y[f] - y[s]) * (y[f] - y[s])
            );
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j][0] = dp[i][j][1] = -1.0;
            }
        }

        double res = 0.0;
        for(int i = 0; i < n; i++){
            for(int j : adj[i]){
                if(i != j){
                    res = std::max(res, dist[i][j] + std::max(dpfunc(i, j, 0), dpfunc(i, j, 1)));
                }
            }
        }

        std::cout.precision(9);
        std::cout << std::fixed << res << '\n';
    }
}
