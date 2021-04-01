#include <bits/stdc++.h>

typedef long long ll;

const int ALPHA = 256;

struct AhoCorasick {
    std::vector<std::vector<int>> tree;
    std::vector<int> fail;
    std::vector<int> next_dict;
    std::vector<std::vector<int>> dict;

    AhoCorasick(std::vector<std::string> words){
        std::vector<int> empty_alpha(ALPHA, -1);

        int states = 1;
        tree.emplace_back(empty_alpha);
        dict.emplace_back(std::vector<int>{});

        for(int i = 0; i < words.size(); i++){
            std::string& s = words[i];
            int pos = 0;
            for(char c_c : s){
                int c = c_c;
                if(tree[pos][c] == -1){
                    tree[pos][c] = states++;
                    tree.emplace_back(empty_alpha);
                    dict.emplace_back(std::vector<int>{});
                }
                pos = tree[pos][c];
            }
            dict[pos].push_back(i);
        }

        fail.resize(states, -1);
        next_dict.resize(states, -1);

        std::queue<int> q;
        fail[0] = -1;
        for(int i = 0; i < ALPHA; i++){
            if(tree[0][i] != -1){
                fail[tree[0][i]] = 0;
                q.push(tree[0][i]);
            }
        }

        while(!q.empty()){
            int par = q.front();
            q.pop();

            for(int i = 0; i < ALPHA; i++){
                if(tree[par][i] == -1){
                    continue;
                }

                int pos = tree[par][i];
                q.push(pos);

                int &pos_fail = fail[pos];
                pos_fail = fail[par];
                while(pos_fail != -1){
                    if(tree[pos_fail][i] != -1){
                        pos_fail = tree[pos_fail][i];
                        break;
                    }
                    pos_fail = fail[pos_fail];
                }
                if(pos_fail == -1){
                    pos_fail = 0;
                }
                if(dict[pos_fail].empty()){
                    next_dict[pos] = next_dict[pos_fail];
                } else {
                    next_dict[pos] = pos_fail;
                }
            }
        }
    }

    std::vector<std::pair<int, int>> query(std::string q){
        int pos = 0;
        std::vector<std::pair<int, int>> matches;
        for(int i = 0; i < q.size(); i++){
            int c = q[i];
            while(pos != 0 and tree[pos][c] == -1){
                pos = fail[pos];
            }
            if(tree[pos][c] != -1){
                pos = tree[pos][c];
            }

            for(int j : dict[pos]){
                matches.push_back({j, i});
            }

            int match_pos = next_dict[pos];
            while(match_pos != -1){
                for(int j : dict[match_pos]){
                    matches.push_back({j, i});
                }
                match_pos = next_dict[match_pos];
            }
        }
        return matches;
    }
};

int main(){
    int n;
    std::cin >> n;

    std::vector<std::string> dict(n);
    for(int i = 0; i < n; i++){
        std::cin >> dict[i];
    }

    AhoCorasick aho_corasick(dict);

    std::string q;
    std::cin >> q;


    std::vector<std::pair<int, int>> matches = aho_corasick.query(q);
    std::cout << matches.size() << '\n';
    for(auto i : matches){
        int r = i.second + 1;
        int l = r - dict[i.first].size();
        std::cout << dict[i.first] << "\t ending at " << i.second << ": ";
        for(int j = 0; j < q.size(); j++){
            if(j == l){
                std::cout << "\033[1;31m";
            }
            if(j == r){
                std::cout << "\033[1;0m";
            }
            std::cout << q[j];
        }
        std::cout << "\033[1;0m";
        std::cout << '\n';

    }
}