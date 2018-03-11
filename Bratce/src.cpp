#include <bits/stdc++.h>
 
typedef long long ll;
 
const int maxn = 1e6 + 1e2;
static int val[maxn];
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    std::string str;
    std::cin >> str;
 
    std::string rev = str;
    std::reverse(rev.begin(), rev.end());
 
    std::cout << std::max(str, rev) << '\n';
}