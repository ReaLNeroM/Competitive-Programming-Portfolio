#include <iostream>
#include <vector>

struct soap{
	int start, end, length;
} copy;

std::vector<soap> s;
std::vector<int> val;

int dp(int end){
	if(val[end] == -1){
		val[end] = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i].start > s[end].end and s[i].end <= copy.start){
				val[end] = std::max(val[end], dp(i) + s[i].length);
			}
		}
	}

	return val[end];
}

int main(){
	int size;
	std::cin >> size;

	for(int i = 0, hour, minute; i < size; i++){
		std::cin >> hour >> minute;

		copy.start = hour * 60 + minute;
		std::cin >> hour >> minute;
		copy.end = hour * 60 + minute;

		if(copy.start >= copy.end){
			copy.end += 1440;
		}

		copy.length = copy.end - copy.start;
		s.push_back(copy);
	}

	val.resize(size, -1);

	int best = 0;
	for(int i = 0; i < size; i++){
		copy.start = s[i].start + 1440;
		best = std::max(best, dp(i) + s[i].length);
	}

	std::cout << best;
}
