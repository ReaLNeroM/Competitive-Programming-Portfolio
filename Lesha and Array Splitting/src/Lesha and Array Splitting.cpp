#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int val[n];

  for(int i = 0; i < n; i++){
    cin >> val[i];
  }

  vector<int> l, r;
  for(int i = 0; i < n; i++){
    if(val[i] != 0){
      val[i] = 1000000;
      int lpos = i, rpos = i;

      while(lpos > 0 and val[lpos - 1] == 0 and val[lpos - 1] != 1000000){
        lpos--;
        val[lpos] = 1000000;
      }
      while(rpos < n - 1 and val[rpos + 1] == 0 and val[rpos + 1] != 1000000){
        rpos++;
        val[rpos] = 1000000;
      }

      i = rpos;

      l.push_back(lpos);
      r.push_back(rpos);
    }
  }

  if(l.size() == 0){
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  cout << l.size() << endl;
  for(int i = 0; i < l.size(); i++){
    cout << l[i] + 1 << ' ' << r[i] + 1 << endl;
  }
}
