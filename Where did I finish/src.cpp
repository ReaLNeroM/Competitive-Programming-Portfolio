#include <bits/stdc++.h>

typedef long long ll;

double calculateModalRank(std::vector<int> scores, std::vector<int> yours){
	std::sort(scores.begin(), scores.end(), std::greater<int>());
	scores.erase(std::unique(scores.begin(), scores.end()), scores.end());

	std::map<int, int> playerRankFrequency;
	for(int playerScore : yours){
		if(playerScore > scores[0]){
			playerRankFrequency[0]++;
			continue;
		}

		int l = 1, r = scores.size();
		int best = r;
		while(l <= r){
			int mid = (l + r) / 2;

			if(scores[mid - 1] <= playerScore){
				r = mid - 1;
			} else if(scores[mid - 1] > playerScore){
				l = mid + 1;
				best = mid;
			}
		}

		playerRankFrequency[best]++;
	}

	int bestScore = playerRankFrequency.begin()->first;
	int occurences = 0;
	for(auto ite : playerRankFrequency){
		if (ite.second >= occurences){
			bestScore = ite.first;
			occurences = ite.second;
		}
	}

	return bestScore + 1;
}

int main(){
	int scoresCount;
	std::cin >> scoresCount;

	std::vector<int> scores(scoresCount);
	for(int i = 0; i < scoresCount; i++){
		std::cin >> scores[i];
	}

	int playerScoresCount;
	std::cin >> playerScoresCount;

	std::vector<int> playerScores(playerScoresCount);
	for(int i = 0; i < playerScoresCount; i++){
		std::cin >> playerScores[i];
	}

	std::cout << calculateModalRank(scores, playerScores) << '\n';
}