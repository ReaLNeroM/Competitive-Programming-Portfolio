#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

std::vector<int> skill, gender, used;
struct group {
	int first, second;

	bool operator() (group const &x, group const &y) {
		int res = std::abs(skill[x.first] - skill[x.second]) - std::abs(skill[y.first] - skill[y.second]);
		if(res == 0){
			return x.first > y.first;
		}

		return res > 0;
	}
} insert;

int main() {
	int dancers;
	std::cin >> dancers;

	skill.resize(dancers), gender.resize(dancers), used.resize(dancers, false);
	for (int i = 0; i < dancers; i++) {
		std::cin >> skill[i];
	}
	for (int i = 0; i < dancers; i++) {
		std::cin >> gender[i];
	}

	std::priority_queue<group, std::vector<group>, group> pairs;
	for (int i = 0; i < dancers - 1; i++) {
		if (gender[i] != gender[i + 1]) {
			insert.first = i, insert.second = i + 1;
			pairs.push(insert);
		}
	}

	std::vector<group> res;
	while(!pairs.empty()){
		insert.first = pairs.top().first + 1, insert.second = pairs.top().second + 1;
		res.push_back(insert);

		used[pairs.top().first] = used[pairs.top().second] = true;
		int i, j;
		for(i = pairs.top().first - 1; i >= 0; i--){
			if(!used[i]){
				break;
			}
		}
		for(j = pairs.top().second + 1; j < dancers; j++){
			if(!used[j]){
				break;
			}
		}
		pairs.pop();
		if(i >= 0 and j < dancers and gender[i] != gender[j]){
			insert.first = i, insert.second = j;
			pairs.push(insert);
		}

		while(!pairs.empty() and (used[pairs.top().first] or used[pairs.top().second])){
			pairs.pop();
		}
	}

	std::cout << res.size() << std::endl;
	for(int i = 0; i < res.size(); i++){
		std::cout << res[i].first << " " << res[i].second << std::endl;
	}
	return 0;
}
