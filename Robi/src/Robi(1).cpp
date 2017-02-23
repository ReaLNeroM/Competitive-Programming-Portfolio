#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

struct coord {
	int y, x;
	int dist;

	bool operator<(coord const &x) const {
		if(this->x == x.x){
			return y < x.y;
		}
		return this->x < x.x;
	}
	bool operator==(coord const &x) const {
		return (this->x == x.x and this->y == x.y);
	}
};

int abs(int x){
	if(x < 0){
		return -x;
	}

	return x;
}
int main() {
	int y, x;
	cin >> y >> x;

	int loc;
	cin >> loc;
	coord l[loc];
	for(int i = 0; i < loc; i++){
		cin >> l[i].y >> l[i].x;
	}

	vector<coord> res;
	for(int i = 0; i < loc; i++){
		coord a = l[i];
		for(int j = i + 1; j < loc; j++){
			coord b = l[j];

			if(a.x > b.x){
				swap(a, b);
			}

		}
	}

	sort(res.begin(), res.end());
	vector<coord>::iterator ite = unique(res.begin(), res.end());

	res.erase(ite, res.end());
	int points = 0;
	for(int i = 0; i < res.size(); i++){
		bool better = false;
		for(int j = 0; j < loc; j++){
			int dist1 = abs(res[i].x - l[j].x) + abs(res[i].y - l[j].y);
			if(dist1 < res[i].dist){
				better = true;
			}
		}
		if(!better){
			points++;
		}
	}

	cout << points;
	return 0;
}
