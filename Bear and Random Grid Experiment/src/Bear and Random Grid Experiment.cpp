#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];
int ay[] = {1, -1, 0, 0};
int ax[] = {0, 0, 1, -1};

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(time(NULL));

	ll sum = 0;
	for(int i = 0; i < 10000; i++){
		set<pair<ll, ll>> s;
		int n = 5000;

		while(!s.empty()){
			s.erase(s.begin());
		}

		int posy = 0, posx = 0;

		s.insert({posy, posx});
		for(int i = 0; i < n; i++){
			val[i] = rand() % 4;
			posy += ay[val[i]];
			posx += ax[val[i]];
			s.insert({posy, posx});
		}

		sum += s.size();
	}

	cout << sum / 10000 << endl;
}

