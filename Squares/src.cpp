#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Squares{
	struct Point {
		int x, y;
	};
	int distSq(Point p, Point q){
    	return (p.x - q.x)*(p.x - q.x) +
        	   (p.y - q.y)*(p.y - q.y);
	}
	// This function returns true if (p1, p2, p3, p4) form a
	// square, otherwise false
	bool isSquare(Point p1, Point p2, Point p3, Point p4)
	{
		int dist[6];
		dist[0] = distSq(p1, p2);
		dist[1] = distSq(p1, p3);
		dist[2] = distSq(p1, p4);
		dist[3] = distSq(p2, p3);
		dist[4] = distSq(p2, p4);
		dist[5] = distSq(p3, p4);
		std::sort(dist, dist + 6);

		if(dist[0] == dist[3] and dist[4] == dist[5]){
			return true;
		}

		return false;
	}
public:
	int findMax(vector<int> x, vector<int> y){
		std::vector<Point> v(x.size());
		for(int i = 0; i < x.size(); i++){
			v[i].x = x[i];
			v[i].y = y[i];
		}
		int res = 0;	
		for(int i = 0; i < x.size(); i++){
			for(int j = i + 1; j < x.size(); j++){
				for(int k = j + 1; k < x.size(); k++){
					for(int l = k + 1; l < x.size(); l++){
						if(isSquare(v[i], v[j], v[k], v[l])){
							res++;
						}
					}
				}
			}
		}
		return res;
	}
};

