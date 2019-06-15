#include <bits/stdc++.h>

typedef long long ll;

const ll step = (ll) 10000000000;
const ll INF = (ll) 1000000000000;
const int attempts = 100;

std::vector<std::pair<ll, ll>> gaps;

void doMove(std::vector<std::pair<ll, ll>>& v){
	int gapIndex = std::rand() % v.size();
	int gapPlace = std::rand() % (v[gapIndex].first - step);

	int a = gapPlace - 1;
	int b = v[gapIndex].first - (gapPlace + step);

	if(a >= step){
		v.push_back({a, v[gapIndex].second});
	}
	if(b >= step){
		v.push_back({b, gapPlace + step});
	}
	v.erase(v.begin() + gapIndex);
}

double getFitness(){
	double goodTries = 0;

	for(int attempt = 0; attempt < attempts; attempt++){
		int moveCount = 0;

		std::vector<std::pair<ll, ll>> gapCopy = gaps;
		while(gapCopy.size() > 1){
			doRandomMove(gapCopy);
			moveCount++;
		}

		if(moveCount % 2 == 0){
			goodTries += 1.0;
		}
	}

	return goodTries / attempts;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases, winNeed;
	std::cin >> testCases >> winNeed;

	std::srand(4325345);
	for(ll testcase = 1; testcase <= testCases; testcase++){
		ll lastResponse = 0;
		gap.clear();
		gap.insert({0, INF});
		while(std::cin >> lastResponse){
			if(lastResponse < 0){
				break;
			}

			fill.push_back(lastResponse);
			lastResponse--;

			ll bestPos = -1;
			double bestScore = -1;
			for(ll curr = 0LL; curr < INF; curr += step / 10LL){
				if(!overlap(curr)){
					fill.insert(curr);
					double getScore = 1.0 - getFitness();
					if(getScore > bestScore){
						bestScore = getScore;
						bestPos = curr;
					}
				}
			}

			std::cout << lastResponse + 1 << '\n';
		}
	}
}