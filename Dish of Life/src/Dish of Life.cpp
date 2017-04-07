#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 1e2;
int ingredients[maxn];
int places[maxn];
vector<int> ingredients_found[maxn];

int main(){
	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		int n, k;
		cin >> n >> k;

		fill(ingredients, ingredients + k, false);
		fill(places, places + k, false);
		for(int i = 0; i < n; i++){
			ingredients_found[i].clear();
		}

		for(int i = 0; i < n; i++){
			int ingredients;
			cin >> ingredients;
			
			ingredients_found[i].resize(ingredients);
			for(int j = 0; j < ingredients; j++){
				cin >> ingredients_found[i][j];
				ingredients_found[i][j]--;
				places[ingredients_found[i][j]]++;
			}
		}

		bool good = true;
		for(int i = 0; i < k and good; i++){
			if(places[i] == 0){
				cout << "sad\n";
				good = false;
			}
		}

		for(int i = 0; i < n and good; i++){
			bool special = false;
			for(int j = 0; j < ingredients_found[i].size(); j++){
				if(places[ingredients_found[i][j]] == 1){
					special = true;
					break;
				}
			}

			if(!special){
				cout << "some\n";
				good = false;
				break;
			}
		}

		if(good){
			cout << "all\n";
		}
	}
}