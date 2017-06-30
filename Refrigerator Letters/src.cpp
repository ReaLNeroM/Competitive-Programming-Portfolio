#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
std::vector<char> v;
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
        
    v.resize(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    
    std::string s;
    std::cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(s[i] == v[j]){
                s.erase(s.begin() + i);
                v.erase(v.begin() + j);
                i--, j--;
            }
        }
    }
    
    std::cout << s.size();
}