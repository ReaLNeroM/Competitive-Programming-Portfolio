#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int in[maxn]; //indegree
int out[maxn];
bool tag[maxn]; //visited
bool tag2[maxn];//part of an odd cycle AND not contributed to a free node
std::map<std::string, int> m;
std::vector<int> innodes[maxn];
int res = 0;

int id(std::string &x){
    int &return_value = m[x];

    if(return_value == 0){
        return_value = (int) m.size();
    }

    return return_value - 1;
}

int main(){
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::string s_a, s_b;
        std::cin >> s_a >> s_b;

        int a = id(s_a), b = id(s_b);

        out[a] = b;
        in[b]++;
        innodes[b].push_back(a);
    }

    if(n % 2 == 1){
        std::cout << -1 << '\n';
        return 0;
    }

    int free_nodes = 0;
    
    for(int i = 0; i < n; i++){
        if(!tag[i]){
            std::queue<int> q;
            q.push(i);
            tag[i] = true;

            int size = 0;

            while(!q.empty()){
                int fr = q.front();
                q.pop();

                size++;

                if(!tag[out[fr]]){
                    q.push(out[fr]);
                    tag[out[fr]] = true;
                }
            }

            if(size == 2){
                continue;
            }

            if(size % 2 == 0){
                res += size / 2;
            } else {
                res += size / 2;
                free_nodes += 1;
            }
        }
    }

    std::cout << res + free_nodes << '\n';
}
