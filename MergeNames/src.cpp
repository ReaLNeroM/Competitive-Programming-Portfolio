#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

class MergeNames {
public:
	std::string merge(std::vector<std::string> names){
		std::vector<std::string> new_array;

		int n = names.size();
		while(n > 1){
			std::sort(names.begin(), names.end());
			new_array.clear();
			for(int i = 0; i < n - i - 1; i++){
				new_array.push_back(names[n - i - 1] + names[i]);
			}
			if(n % 2 == 1){
				new_array.push_back(names[names.size() / 2]);
			}
			names = new_array;
			n = names.size();
		}

		return names[0];
	}
};
