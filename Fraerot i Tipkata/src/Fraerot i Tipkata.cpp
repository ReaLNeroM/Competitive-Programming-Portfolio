#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;

	int ef[e], es[e], ec[e];
	for(int i = 0; i < e; i++){
		cin >> ef[i] >> es[i] >> ec[i];
		ef[i]--, es[i]--;
	}

	int impcities;
	cin >> impcities;

	bool imp[v];
	for(int i = 0; i < v; i++){
		imp[i] = false;
	}
	int s = -1;

	for(int i = 0; i < 1000; i++){
		int inp;
		cin >> inp;
		inp--;

		if(i == impcities and v <= 1000){
			s = inp + 1;
			break;
		}
		if(inp >= 100){
			s = inp + 1;
			break;
		}

		imp[inp] = true;
	}

	if(s == -1){
		cin >> s;
	}

	int cost[v];
	for(int i = 0; i < v; i++){
		cost[i] = 1000000;
	}
	cost[s - 1] = 0;

	for(int i = 0; i < v; i++){
		for(int j = 0; j < e; j++){
			if(cost[es[j]] > cost[ef[j]] + ec[j]){
				cost[es[j]] = cost[ef[j]] + ec[j];
			}
			if(cost[ef[j]] > cost[es[j]] + ec[j]){
				cost[ef[j]] = cost[es[j]] + ec[j];
			}
		}
	}

	int mincost = 1000000 * 50;
	for(int i = 0; i < v; i++){
		if(imp[i] and cost[i] < mincost){
			mincost = cost[i];
		}
	}

	cout << mincost;
	return 0;
}
