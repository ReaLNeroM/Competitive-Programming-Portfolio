#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;

	for(int test = 0; test < cases; test++){
		int n;
		cin >> n;

		multimap<int, int> s[3];
		queue<int> q;
		int val[3][n], occur[3][n];
		bool used[n];
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < n; j++){
				occur[i][j] = 0;
				used[j] = false;
			}
			for(int j = 0; j < n; j++){
				cin >> val[i][j];
				val[i][j]--;
				occur[i][val[i][j]]++;
				s[i].insert(make_pair(val[i][j], j));
			}
			for(int j = 0; j < n; j++){
				if(occur[i][j] == 0){
					occur[i][j] = -1;
					q.push(j);
				}
			}
		}


		while(!q.empty()){
			int v = q.front();
			q.pop();

			for(int i = 0; i < 3; i++){
				for(int j = 0; j < occur[i][v]; j++){
					int column = s[i].find(v)->second;
					used[column] = true;
					for(int k = 0; k < 3; k++){
						if(s[k].find(val[k][column]) != s[k].end()){
							s[k].erase(s[k].find(val[k][column]));
							occur[k][val[k][column]]--;
							if(occur[k][val[k][column]] == 0){
								occur[k][val[k][column]] = -1;
								q.push(val[k][column]);
							}
						}
					}
				}
			}
		}

		int changes = 0;
		for(int i = 0; i < n; i++){
			if(used[i]){
				changes++;
			}
		}

		cout << changes << endl;
	}
	return 0;
}
