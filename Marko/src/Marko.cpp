#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

#define INF 9999999

using namespace std;

struct node
{
    int md, smd, mid, dp, sdp, sid, dnid;
};

int n, k;
int a[400000];
int p[400000];
vector<int> g[400000];
node x[400000];
vector<pair<int, int> > dv;

void dfs(int curr, int prev, int dpt)
{
//    cout << curr << " " << prev << " " << dpt << endl;
//    dv.push_back(make_pair(curr, dpt));

    p[curr] = prev;
    for (int i = 0; i < g[curr].size(); i++)
    {
        if (g[curr][i] == prev)
            continue;

        dfs(g[curr][i], curr, dpt + 1);
    }
}

int main()
{

    n = 300000;
    for (int i = 0; i < n; i++)
        a[i] = 1;

    int ca, cb;
    for (int i = 0; i < n - 1; i++)
    {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }

    dfs(n / 2, -1, 0);

    return 0;
}
