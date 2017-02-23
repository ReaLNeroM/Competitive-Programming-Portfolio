#include <iostream>
#include <vector>
#include <map>

struct teacher{
	int cost;

	std::vector<int> sub;
} c;

std::vector<teacher> t;
std::vector<std::vector<int> > dp;
int subjects, done = 0;

int gen(int pos, int bitset){
	if(bitset == done){
		return 0;
	} else if(pos >= t.size()){
		return 100000000;
	}

	if(dp[pos][bitset] == -1){
		int copybitset = bitset;
		for(int i = 0; i < t[pos].sub.size(); i++){
			if(((1 << (t[pos].sub[i] + subjects)) & bitset) == 0){
				if(((1 << (t[pos].sub[i])) & bitset) == 0){
					copybitset += (1 << (t[pos].sub[i]));
				} else {
					copybitset -= (1 << (t[pos].sub[i]));
					copybitset += (1 << (t[pos].sub[i] + subjects));
				}
			}
		}

		dp[pos][bitset] = std::min(gen(pos + 1, bitset), gen(pos + 1, copybitset) + t[pos].cost);
	}

	return dp[pos][bitset];
}

int main() {
	std::cin >> subjects;

	int start = 0;
	for(int i = 0; i < subjects; i++){
		done *= 2;
		done++;
	}
	for(int i = 0; i < subjects; i++){
		done *= 2;
	}

	int sum = 0;
	for(int i = 0, teachers; i < 2; i++){
		std::cin >> teachers;

		for(int j = 0, teachsubjects; j < teachers; j++){
			std::cin >> c.cost >> teachsubjects;
			if(i == 0){
				sum += c.cost;
				c.cost = 0;
				for(int k = 0, inp; k < teachsubjects; k++){
					std::cin >> inp;
					inp--;
					if(((1 << inp + subjects) & start) == 0){
						if(((1 << inp) & start) == 0){
							start += (1 << inp);
						} else {
							start -= (1 << inp);
							start += (1 << inp + subjects);
						}
					}
				}
			} else {
				for(int k = 0, inp; k < teachsubjects; k++){
					std::cin >> inp;
					c.sub.push_back(inp - 1);
				}
				t.push_back(c);
				c.sub.clear();
			}
		}

	}

	dp.resize(t.size() + 1);
	for(int i = 0; i < t.size(); i++){
		dp[i].resize(done + 1, -1);
	}

	std::cout << gen(0, start) + sum;
	return 0;
}
