/*
ID: vlade.m1
PROG: checker
LANG: C++
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 30;
int n;
vector<vector<int> > l;
int ord[maxn];
int y_used[maxn];
int diag_used[maxn];
int anti_used[maxn];
int found = 0;

void dfs(int pos){
	if(pos == n){
		if(found <= 2){
			l[found].resize(n);
			for(int j = 0; j < n; j++){
				l[found][j] = ord[j] + 1;
			}
		}
		found++;
		return;
	}
	for(int i = 0; i < n; i++){
		if(!y_used[i] and !diag_used[i + pos] and !anti_used[i - pos + n]){
			y_used[i]++, diag_used[i + pos]++, anti_used[i - pos + n]++;
			ord[pos] = i;
			dfs(pos + 1);
			y_used[i]--, diag_used[i + pos]--, anti_used[i - pos + n]--;
		}
	}
}

int main(){
//	freopen("checker.in", "r", stdin);
//	freopen("checker.out", "w", stdout);
	cin >> n;

	l.resize(3);
	dfs(0);

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < n; j++){
			cout << l[i][j];
			if(j != n - 1){
				cout << ' ';
			} else {
				cout << '\n';
			}
		}
	}

	cout << found << endl;
}
