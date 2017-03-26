#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 55;
int blocked[maxn];
vector<int> used;
int allowed[maxn];
int n;
int res = 7;
 
void dfs(int pos){
    for(int j = 1; j <= 6 and res == 7; j++){
        if(!used[(pos + j) % n] and allowed[j]){
            used[(pos + j) % n] = true;
            dfs((pos + j) % n);
            used[(pos + j) % n] = false;
        } else if(used[(pos + j) % n] == -1){
        	for(int i = 0; i < used.size(); i++){
        		if(used[i] == 0){
        			return;
        		}
        	}
        	res = 1;
        	return;
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
    	cin >> blocked[i];
    }
 
    int moves;
    cin >> moves;
    for(int j = 0; j < moves; j++){
        int jump;
        cin >> jump;
        allowed[jump] = true;
    }

    used.resize(n);
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < n; j++){
            used[j] = blocked[j];
        }
        if(!used[i]){
			used[i] = -1;
			dfs(i);
			break;
        }
    }
 
    if(res == 7){
    	cout << "GRESHKA" << endl;
    } else {
		cout << res;
    }
}
