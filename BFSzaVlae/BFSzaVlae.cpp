//============================================================================
// Name        : BFSzaVlae.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

bool vis[101][101];
int mat[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
vector<int> vx;
vector<int> vy;

int bfs(int a, int b, int fx, int fy)
{
	queue<int> q;
	vis[a][b] = true;
	q.push(a);
	q.push(b);

	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int cx = x + dx[i];
			int cy = y + dy[i];

			if(cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
			if(vis[cx][cy]) continue;

			mat[cx][cy] = mat[x][y] + 1;
			vis[cx][cy] = true;
			q.push(cx);
			q.push(cy);
		}
	}

	return mat[fx][fy];
}

void dfs(int sx, int sy, int ex, int ey, int maxx, int cmaxx)
{
	if(cmaxx > maxx)
		return;
	if(sx == ex && ey == sy)
	{
		for(int i = 0; i < vx.size(); i++)
			cout << vx[i] << " " << vy[i] << " -> ";

		cout << "end" << endl;
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		int cx = sx + dx[i];
		int cy = sy + dy[i];

		if(cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
		if(vis[cx][cy]) continue;

		vx.push_back(sx);
		vy.push_back(sy);
		vis[sx][sy] = true;

		dfs(cx, cy, ex, ey, maxx, cmaxx + 1);

		vx.pop_back();
		vy.pop_back();
	}
}

int main() {
	cin >> n >> m;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	int maxx = bfs(sx, sy, ex, ey);
	cout << maxx << endl;
	//vx.push_back(sx);
	//vy.push_back(sy);
	memset(vis, false, sizeof(vis));
	//vis[sx][sy] = true;
	dfs(sx, sy, ex, ey, maxx, 0);

	return 0;
}
