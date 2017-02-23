#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	int cases;
	std::cin >> cases;

	std::string res[cases];
	for(int test = 0; test < cases; test++){
		int points;
		std::cin >> points;

		int pos[points];
		for(int i = 0; i < points; i++){
			std::cin >> pos[i];
		}
		std::sort(pos, pos + points);

		res[test] = "NISTO";
		if(points == 3){
			int i = 1, level = 0;
			while(i + level < pos[0]){
				level++;
				i += level;
			}

			int dist;
			for(dist = 0; i < pos[1]; dist++, level++, i += level){

			}

			if(i <= pos[1] and i <= pos[2] and i + level >= pos[1] and i + level >= pos[2] and pos[2] - pos[1] == dist){
				res[test] = "TRIAGOLNIK";
			} else {
				int i = 1, level = 0;
				while(i + level < pos[0]){
					level++;
					i += level;
				}

				int dist;
				if(i <= pos[0] and i <= pos[1] and i + level >= pos[0] and i + level >= pos[1]){
					dist = pos[1] - pos[0];

					int
				}

			}
		} else if(points == 4){

		} else if(points == 6){

		}
	}

	for(int test = 0; test < cases; test++){
		std::cout << res[test] << std::endl;
	}
	return 0;
}
