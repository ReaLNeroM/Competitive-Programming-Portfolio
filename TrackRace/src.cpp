#include<string>
#include <vector>
using namespace std;

class TrackRace
{
  public:
  	int cost(int lap){
  		return ((lap + 1) / 2) * 20;
  	}
    string fastest(vector<string> drivers, vector<string> penalties)
    {
    	std::vector<int> laps[drivers.size()];

    	for(int i = 0; i < drivers.size(); i++){
    		int sum = 0;
    		for(int j = 0; j < drivers[i].size(); j += 6){
    			sum += (drivers[i][j] - '0') * 600;
    			sum += (drivers[i][j + 1] - '0') * 60;
    			sum += (drivers[i][j + 3] - '0') * 10;
    			sum += (drivers[i][j + 4] - '0') * 1;
    			laps[i].push_back(sum);
    		}
    	}

    	for(int i = 0; i < penalties.size(); i++){
    		if(penalties[i] != "np"){
	    		for(int j = penalties[i].size() - 8; j >= 0; j -= 9){
	    			int location = 0;
	    			location += (penalties[i][j] - '0') * 36000;
	    			location += (penalties[i][j + 1] - '0') * 3600;
	    			location += (penalties[i][j + 3] - '0') * 600;
	    			location += (penalties[i][j + 4] - '0') * 60;
	    			location += (penalties[i][j + 6] - '0') * 10;
	    			location += (penalties[i][j + 7] - '0') * 1;

	    			int change = 0;
	    			for(int k = 0; k < laps[i].size(); k++){
	    				if(location <= laps[i][k] and !change){
	    					change = cost(k + 1);
	    				}
	    				if(change){
	    					laps[i][k] += change;
	    				}
	    			}
	    		}
    		}
    	}

    	int smallest = laps[0][laps[0].size() - 1];
    	for(int i = 0; i < drivers.size(); i++){
    		smallest = std::min(smallest, laps[i][laps[i].size() - 1]);
    	}

    	std::string s = "00:00:00";
    	s[0] = ('0' + smallest / 36000);
    	s[1] = ('0' + smallest % 36000 / 3600);
    	s[3] = ('0' + smallest % 3600 / 600);
    	s[4] = ('0' + smallest % 600 / 60);
    	s[6] = ('0' + smallest % 60 / 10);
    	s[7] = ('0' + smallest % 10 / 1);
    	return s;
  }
};

int main(){
	TrackRace x;
	x.fastest({"59:59;01:00;01:01;01:02;01:03;01:04;59:59","01:00;01:01;01:02;01:03;01:04;01:05;59:59"}, {"np","1:06:13"});
}
