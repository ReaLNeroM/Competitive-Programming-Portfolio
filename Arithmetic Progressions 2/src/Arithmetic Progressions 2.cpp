// C++ program to Find the repeating
// and missing elements

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;

const ll maxn = 5005;
ll val[maxn];
std::set<ll> m;

int main(){
  ll n;
  cin >> n;

  for(ll i = 0; i < n; i++){
    std::cin >> val[i];
  }

  std::sort(val, val + n);
  for(ll i = 0; i < n; i++){
    // std::cerr << val[i] << ' ';
    m.insert(val[i]);
  }

  ll best = 2;
  for(ll i = 0; i < n; i++){
    for(ll j = i+1; j < n; j++){
      if(i == j){
          continue;
      }
      ll diff = val[j] - val[i];

//      std::cerr << val[i] << ' ' << val[j] << ' ' << diff << '\n';
      if(m.find(val[i] - diff) != m.end()){
        // std::cout << val[i] - diff << '\n';
        continue;
      }
      ll elems = 0;
      for(ll l = val[i]; true; l += diff){
        if(m.find(l) == m.end()){
          break;
        }

        if(elems >= 20){
          std::cerr << val[i] << ' ' << diff << ' ' << l << '\n';
        }
        elems++;
      }
      best = max(best, elems);
    }
  }

  std::cout << best;
}
