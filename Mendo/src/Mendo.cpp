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

const int maxn = 100;
vector<pair<int, int>> adj[maxn];
bool vis[maxn];
int mat[maxn];
int n, m;
vector<int> vx;
vector<int> vy;

int bfs(int a, int b)
{
	queue<int> q;
	vis[a] = true;
	q.push(a);

	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		for(int i = 0; i < adj[x].size(); i++){
			int nnext = adj[x][i].first;
			if(vis[nnext]) continue;

			mat[nnext] = mat[x] + adj[x][i].second;
			vis[nnext] = true;
			q.push(nnext);
		}
	}

	return mat[b];
}

void dfs(int s, int e, int maxx, int cmaxx)
{
	if(cmaxx > maxx)
		return;
	if(s == e)
	{
		for(int i = 0; i < vx.size(); i++)
			cout << vx[i] << " -> ";

		cout << e << endl;
		return;
	}

	for(int i = 0; i < adj[s].size(); i++)
	{
		int nnext = adj[s][i].first;
		if(vis[nnext]) continue;

		vx.push_back(s);
		vis[s] = true;

		dfs(nnext, e, maxx, cmaxx + 1);

		vx.pop_back();
	}
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++){
		int f, s, d;
		cin >> f >> s >> d;

		adj[f].push_back({s, d});
		adj[s].push_back({f, d});
	}
	int s, e;
	cin >> s >> e;
	int maxx = bfs(s, e);
	cout << maxx << endl;
	memset(vis, false, sizeof(vis));
	dfs(s, e, maxx, 0);

	return 0;
}
