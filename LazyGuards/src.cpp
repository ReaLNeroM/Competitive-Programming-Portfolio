#include <string>
#include <vector>
#include <queue>
using namespace std;

class LazyGuards{
public:
	int dist[50][50][4];
	int used[50][50][4];
	int ay[4] = {0, -1, 0, 1};
	int ax[4] = {1, 0, -1, 0};
	vector<pair<int, int> > v;
	vector<int> step;

	bool coll(int sy, int sx, pair<int, int> guard, int time){
		if(time == 0){
			if(sy == guard.first and guard.second <= sx){
				return true;
			}
		} else if(time == 1){
			if(guard.first <= sy and guard.second == sx){
				return true;
			}
		} else if(time == 2){
			if(sy == guard.first and sx <= guard.second){
				return true;
			}
		} else if(time == 3){
			if(sy <= guard.first and guard.second == sx){
				return true;
			}
		}

		return false;
	}

	int check(int sy, int sx, int time){
		for(int i = 0; i < v.size(); i++){
			if(coll(sy, sx, v[i], (step[i] + time) % 4)){
				return true;
			}
		}

		return false;
	}

	int numberOfSteps(vector<string> maze){
		int sy, sx;
		int ey, ex;

		for(int i = 0; i < maze.size(); i++){
			for(int j = 0; j < maze[i].size(); j++){
				if(maze[i][j] == 'S'){
					sy = i, sx = j;
					maze[i][j] = '.';
				} else if(maze[i][j] == 'E'){
					ey = i, ex =  j;
					maze[i][j] = '.';
				} else if(maze[i][j] == '1'){
					v.push_back(make_pair(i, j));
					step.push_back(0);
				} else if(maze[i][j] == '2'){
					v.push_back(make_pair(i, j));
					step.push_back(1);
				} else if(maze[i][j] == '3'){
					v.push_back(make_pair(i, j));
					step.push_back(2);
				} else if(maze[i][j] == '4'){
					v.push_back(make_pair(i, j));
					step.push_back(3);
				}
			}
		}

		if(check(sy, sx, 0)){
			return -1;
		}

		for(int i = 0; i < 50; i++){
			for(int j = 0; j < 50; j++){
				for(int k = 0; k < 4; k++){
					dist[i][j][k] = 1000000;
					used[i][j][k] = false;
				}
			}
		}

		priority_queue<pair<pair<pair<int, int>, int>, int> > pq;

		dist[sy][sx][0] = 0;
		pq.push(make_pair(make_pair(make_pair(-dist[sy][sx][0], sy), sx), 0));

		while(!pq.empty()){
			int needed = -pq.top().first.first.first;
			int cy = pq.top().first.first.second;
			int cx = pq.top().first.second;
			int mod = pq.top().second;
			pq.pop();

			if(used[cy][cx][mod]){
				continue;
			}
			used[cy][cx][mod] = true;

			for(int i = 0; i < 4; i++){
				int ny = cy + ay[i];
				int nx = cx + ax[i];
				int nmod = (mod + 1) % 4;

				if(0 <= ny and ny < maze.size() and 0 <= nx and nx < maze[0].size() and dist[ny][nx][nmod] > needed + 1 and maze[ny][nx] == '.' and !check(ny, nx, nmod)){
					dist[ny][nx][nmod] = needed + 1;
					pq.push(make_pair(make_pair(make_pair(-dist[ny][nx][nmod], ny), nx), nmod));
				}
			}
		}

		int best = 10000000;
		for(int i = 0; i < 4; i++){
			if(best > dist[ey][ex][i]){
				best = dist[ey][ex][i];
			}
		}

		if(best > 100000){
			return -1;
		}

		return best;
	}
};
