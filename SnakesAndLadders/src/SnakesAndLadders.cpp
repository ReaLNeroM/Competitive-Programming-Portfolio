#include <string>
#include <vector>

class SnakesAndLadders
{
  public:
    std::string luckySequence(std::vector<int> path)
    {
    	std::string best[path.length()];

    	best[0] = 0;
    	for(int i = 0; i < path.length(); i++){
    		if(path[i] != 0){

    		}
    	}
    }
};

int main(){
	SnakesAndLadders x;
	std::cout << x.luckySequence()
}
