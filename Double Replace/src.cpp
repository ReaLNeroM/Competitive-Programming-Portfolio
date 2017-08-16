#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    std::string s, a, b;
    std::cin >> s >> a >> b;
        
    for(int i = 0; i < s.size(); i++){
        bool change = false;
        
        if(i + a.size() <= s.size()){
            if(s.substr(i, a.size()) == a){
                s.erase(i, a.size());
                s.insert(i, b);
                change = true;
                i += b.size() - 1;
            }
        }
        if(!change and i + b.size() <= s.size()){
            if(s.substr(i, b.size()) == b){
                s.erase(i, b.size());
                s.insert(i, a);
                
                i += a.size() - 1;
            }
        }
        
    }
    
    std::cout << s << '\n';
}