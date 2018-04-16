#include <string>
#include <vector>
using namespace std;

class GunScratch{
public:
	int matches(vector<string> bullets, string bullet){
		for(int i = 0; i < bullets.size(); i++){
			for(int j = 0; j < bullet.size(); j++){
				std::string gen = bullet.substr(j, (int) bullet.size() - j);
				if(j != 0){
					gen += bullet.substr(0, j);
				}

				if(gen == bullets[i]){
					return i;
				}
			}
		}

		return -1;
	}
};
