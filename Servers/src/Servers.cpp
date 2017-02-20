#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5;
int entry[maxn], hard[maxn], time_needed[maxn];
int used[100];
int able[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int servers, tasks;
	cin >> servers >> tasks;
	for(int i = 0; i < servers; i++){
		used[i] = -1;
	}

	vector<pair<int, pair<int, int> > > v;

	for(int i = 0; i < tasks; i++){
		cin >> entry[i] >> hard[i] >> time_needed[i];
		v.push_back({entry[i], {1, i}});
		v.push_back({entry[i] + time_needed[i], {-1, i}});
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++){
		int ind = v[i].second.second;

		if(v[i].second.first == -1 and able[ind] != -1){
			for(int j = 0; j < servers; j++){
				if(used[j] == ind){
					used[j] = -1;
				}
			}
		} else if(v[i].second.first == 1){
			int found = 0;
			for(int j = 0; j < servers; j++){
				if(used[j] == -1){
					found++;
				}
			}

			if(found >= hard[ind]){
				able[ind] = 0;
				int left = hard[ind];
				for(int j = 0; j < servers; j++){
					if(used[j] == -1 and left > 0){
						used[j] = ind;
						able[ind] += j + 1;
						left--;
					}
				}
			} else {
				able[ind] = -1;
			}
		}
	}

	for(int i = 0; i < tasks; i++){
		cout << able[i] << '\n';
	}
}

