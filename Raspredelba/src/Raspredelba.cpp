#include <iostream>
#include <vector>
#include <algorithm>

int currgroups;
int goalgroups;
int min;

void dfs(std::vector <int> group, std::vector <int> goal, int change = 0) {
	bool finished = true;
	for (int i = 0; i < group.size(); i++) {
		if (group[i] != 0) {
			for (int j = 0; j < goal.size(); j++) {
				if (group[i] == goal[j]) {
					group[i] = 0;
					goal[j] = 0;
					break;
				}
			}
		}
	}

	if (change < min) {
		for (int i = 0; i < goal.size(); i++) {
			if (goal[i] != 0) {
				finished = false;
				break;
			}
		}
		if (finished) {
			min = change;
		} else {
			for (int i = 0; i < group.size(); i++) {
				if (group[i] != 0) {
					for (int j = i + 1; j < group.size(); j++) {
						if(group[j] != 0){
							group[i] += group[j];
							int temp = group[j];
							group[j] = 0;
							dfs(group, goal, change + 1);
							group[j] = temp;
							group[i] -= group[j];

						}
					}

					group.push_back(group);
					group.back()++;
					group[i]--;
					dfs(group, goal, change + 1);
					group.pop_back();
				}
			}
		}
	}
}
int main() {
	std::cin >> currgroups;

	std::vector <int> group(currgroups);
	int sum = 0;
	for (int i = 0; i < currgroups; i++) {
		std::cin >> group[i];
		sum += group[i];
	}

	std::cin >> goalgroups;

	std::vector <int> goal(goalgroups);
	for (int i = 0; i < goalgroups; i++) {
		std::cin >> goal[i];
		sum -= goal[i];
	}

	if (sum != 0) {
		std::cout << -1;
	} else {
		for(int i = 2; i <= goalgroups + currgroups; i++){
			min = i;
			dfs(group, goal);
			if(min != i){
				std::cout << min;
				break;
			}
		}
	}
	return 0;
}
