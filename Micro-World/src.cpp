#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n, k;
    std::cin >> n >> k;

    std::multiset<int> s;
    for(int i = 0; i < n; i++){
    	std::cin >> val[i];
    	s.insert(val[i]);
    }

    for(auto ite = s.begin(); ite != s.end(); ite++){
    	int get_val = *ite;

    	while(ite != s.begin()){
    		auto sec = ite;
    		sec--;

    		if(get_val > *sec and get_val <= *sec + k){
    			s.erase(sec);
    		} else {
    			break;
    		}
    	}
    }

    std::cout << s.size() << '\n';
}