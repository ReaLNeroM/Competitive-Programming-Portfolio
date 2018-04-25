#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 20;
ll allowed[maxn];
ll ways[maxn];
ll free_digits = 0;
std::string n;

ll generate(ll pos, bool zero = false){
    if(pos == n.size()){
        return 0;
    }
    
    ll res = 0;
    if(zero){
    	if(allowed[0] and n[pos] == '0'){
    		res += generate(pos + 1, true);
    	} else if(allowed[0] and n[pos] > '0'){
    		res += ways[n.size() - pos - 1];
    	}
    }
    for(char i = '1'; i <= '9'; i++){
        if(allowed[i - '0'] and n[pos] > i){
            res += ways[n.size() - pos - 1];
        } else if(allowed[i - '0'] and n[pos] == i){
            res += generate(pos + 1, true);
        }
    }
    
    if(!zero){
    	for(ll i = n.size() - 1; i > pos; i--){
    		res += (free_digits - allowed[0]) * ways[n.size() - i - 1];
    		if(allowed[0] and n.size() - i - 1 == 0){
    			res++;
    		}
    	}
    }

    return res;
}

int main(){
    std::ios::sync_with_stdio(false);

    for(ll i = 0; i < 10; i++){
        std::cin >> allowed[i];
        allowed[i] = !allowed[i];
        free_digits += allowed[i];
    }

    std::cin >> n;

    ways[0] = 1;

    for(ll i = 1; i < 20; i++){
        ways[i] = ways[i - 1] * free_digits;
    }
    
    std::cout << generate(0) << '\n';
}
