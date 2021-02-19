#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int x[maxn];

int main(){
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::string s;
    std::getline(std::cin, s);

    for(int i = 0; i < n; i++){
        std::getline(std::cin, s);

        if(s.substr(0, 10) == "Simon says"){
            std::cout << s.substr(11, 100) << '\n';
        }
    }
}