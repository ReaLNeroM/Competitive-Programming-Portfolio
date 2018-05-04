#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 35;
ll n, t;
ll val[maxn];
ll inter[maxn];
std::vector<int> s[2][maxn];

void dfs(ll pos, ll ups, ll sum, ll side, ll threshold, ll inc){
    if(side == 0){
    	sum += ups * inter[pos];
    }
    if(sum > t){
    	return;
    }

    if(pos == threshold){
    	s[side][ups].push_back(sum);
    	return;
    }
    if(side != 0){
		sum += ups * inter[pos];
    }
    if(pos + inc + ups + 1 < n){
        dfs(pos + inc, ups + 1, sum, side, threshold, inc);
    }
    if(pos + inc + ups     < n){
        dfs(pos + inc, ups    , sum, side, threshold, inc);
    }
    if(ups != 0){
        dfs(pos + inc, ups - 1, sum, side, threshold, inc);
    }
} 

int main(){
    std::ios::sync_with_stdio(false);

    std::cin >> n >> t;

    ll start = 0;
    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
    }

    std::sort(val, val + n);

    for(int i = 0; i < n - 1; i++){
    	inter[i] = 2 * (val[i + 1] - val[i]);
		start += inter[i];
    }

    t -= start;

    ll breakpoint = n / 2;

    dfs(0, 0, 0, 0, breakpoint, 1);
    dfs(n - 2, 0, 0, 1, breakpoint, -1);

  	int res = 0;

  	for(int i = 0; i < n; i++){
  		std::sort(s[0][i].begin(), s[0][i].end(), std::greater<int>());
  		std::sort(s[1][i].begin(), s[1][i].end());
  		auto sec = s[1][i].begin();

  		if(s[0][i].empty() or s[1][i].empty()){
  			continue;
  		}

  		for(auto ite = s[0][i].begin(); ite != s[0][i].end(); ite++){

  			while(sec != s[1][i].end() and (sec + 1) != s[1][i].end()){
  				auto thi = sec + 1;

  				if(thi == s[1][i].end() or *ite + *thi > t){
  					break;
  				}

  				sec = thi;

  			}

  			if(*ite + *sec <= t){
				res = std::max(res, *ite + *sec);
  			}
  		}
  	}

    std::cout << start + res << '\n';
}
