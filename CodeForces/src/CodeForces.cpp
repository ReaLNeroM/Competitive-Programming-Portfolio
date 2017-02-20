#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];
int on[maxn];
int used[maxn];
int res = 0;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int turned_on = 0;
	for(int i = 0; i < n; i++){
		cin >> val[i];
		val[i]--;
	}
	for(int i = 0; i < n; i++){
		cin >> on[i];
		turned_on += on[i];
	}

	if(turned_on % 2 == 0){
		res++;
	}

	int comps = 0;
	for(int i = 0; i < n; i++){
		if(!used[i]){
			comps++;
			int pos = i;

			while(true){
				if(used[val[pos]]){
					break;
				}
				pos = val[pos];
				used[pos] = true;
			}
		}
	}

	if(comps > 1){
		res += comps;
	}

	cout << res;
}
