#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class RadarGrid {
public:
	int minimalDistance(int length, int K, vector <int> radars) {
		sort(radars.begin(), radars.end());

		int l = 0, r = length;
		int best = r;
		while(l <= r){
			int mid = (l + r) / 2;

			int leeway = K, otherleeway = K;
			if(mid * radars.size() > length){
				leeway += mid * radars.size() - length;
				otherleeway += mid * radars.size() - length;
			}

			for(int i = 0; i < radars.size(); i++){
				if(mid * (i + 1) < length){
					leeway -= abs(radars[i] - mid * (i + 1));
				}
			}
			for(int i = 0; i < radars.size(); i++){
				if((length - mid * (i + 1)) >= 0){
					otherleeway -= abs(radars[radars.size() - i - 1] - (length - mid * (i + 1)));
				}
			}

			if(otherleeway >= 0 or leeway >= 0){
				best = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		return best;
	}
};

int main(){
	vector<int> r;
	r.push_back(2);
	r.push_back(6);
	r.push_back(8);
	RadarGrid x;
	x.minimalDistance(12, 1, r);
}
