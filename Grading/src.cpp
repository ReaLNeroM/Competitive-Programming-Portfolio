/** Solution details
Let's consider the case where the number of files we can remove is 0.
The optimal solution will be one of the two following types:

1) We grade all 'A' documents we can i.e. that are on top of their corresponding stacks. Once we've
exhausted all 'A' type documents that we can grade, we have to context switch and start reviewing
'B' type documents. We similarly exhaust all 'B' type documents on top of stacks, and we are now
forced to switch to 'A' type documents. This process repeats until each pile is empty. So in
essence, the documents we context switch to forms a string 'ABABABAB....'
2) It's similar to 1), in that we repeat this process of exhausting all documents we can without
context-switching, except we start with 'B' type documents first, so our "context-switches string"
looks like 'BABABABA...' instead. 

Another important thing:

An important observation in this problem is that it's easier to work with the number of
context-switches, and 'reverse' the problem from there. This means the meat of our algorithm asks
for each K: I want to do a total of K context-switches (starting from 'A' and 'B' is different, so
we'll consider them independently), what's the least number of documents I have to remove? Wait,
what's the range on K? It's between 0 and some large number. What's the largest number of
context-switches we could do? Intuitively, the result is largest when we have grading piles that
look like 'ABABAB..', since we only remove one document for each context switch. If we have two test
piles that look like
'ABABAB...'
'BABABA...',
we'll have a result of 2 * H. It turns out this is the upper bound on the result (not proved, but
feel free to have at it).

Back to the problem. So solving the case where we forbid file removal is fairly straightforward. How
does file removal change our approach? 

We'll have to again use our human power of abstraction, and consider a special case: where S=1 i.e.
there is only one stack. Consider the grading pile 'AABBBBBAA'. We can achieve a result of 1
context-switch by just removing the first two 'A' documents and the last two 'A' documents, so we
need to remove at least 4 documents. So we have to choose where to 'invest' our file removals to
ensure we don't exceed our context-switches limit by completely eliminating consecutive clusters of
'A' (or 'B') documents, which will reduce our result by 1 context-switch for each cluster we
remove. Here, I implemented choosing which clusters to cull using DP, but I think greedily cutting
the shortest clusters would also work.

How do we extend this for arbitrary number of grading piles? Very simple: If we want only K
context-switches (and we start with 'A'/'B' documents), we compute the minimum number of files to be
removed for each stack independently, and just sum each stack's result!

So as a result, we've found a list indexed for X where X means "if you want to do at or below X
context-switches, you'll need at least Y removals". Since the more context-switches we're allowed to
do, the less (or equal) documents we need to remove, this is a monotonically decreasing list! We can
just binary search over this list, and answer all queries in O(Q*lgH) time, which is good enough.

What's the precomputation cost? The DP for each stack costs O(4 * H^3), and there are O(S) stacks,
so the result is O(4 * S * H^3) operations. Using some additional optimizations (and using -O4),
this finishes in below a minute on my laptop. If I instead used greedy, I could probably shave off a
factor of H off the complexity.
*/

#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 305 + 10;

int s, h;
int mat[maxn][maxn];
int dp[maxn][2 * maxn];
int tempmintotake[2 * maxn];
int mintotake[2 * maxn];
int currs = 0;

// for the given stack (currs), and for the given height and maximum number of
// context switches, this tells you how many books you need to remove from a
// given stack to ensure you don't exceed allowed number of context switches.
int dpfunc(int pos, int clusters){
	if(dp[pos][clusters] != -1){
		return dp[pos][clusters];
	}
	int& ans = dp[pos][clusters];
	if(pos == 0){
		ans = 0;
		return ans;
	}
	ans = pos;
	if(clusters == 0){
		return ans;
	}

	int currcost = 0;
	for(int i = pos; i > 0; i--){
		if(mat[currs][i - 1] != mat[currs][pos - 1]){
			currcost++;
		}
		if(currcost >= ans){
			break;
		}
		ans = std::min(ans, currcost + dpfunc(i - 1, clusters - 1));
	}

	return ans;
}

// essentially creates a reverse look-up table for the result i.e. we
// calculate FOR ALL N, if you want N context switches in total (with A as
// your first letter), you need to remove at least K books.
void solve(){
	tempmintotake[0] = s * h;
	for(int i = 1; i <= 2 * h; i++){
		tempmintotake[i] = 0;
	}

	for(int i = 0; i < s; i++){
		currs = i;
		for(int j = 0; j <= h + 1; j++){
			for(int k = 0; k <= 2 * h; k++){
				dp[j][k] = -1;
			}
		}

		for(int j = 1; j <= 2 * h; j++){
			int cost = 0;

			mat[i][h] = 0;
			cost = dpfunc(h + 1, j);
			
			tempmintotake[j] += cost;
		}
	}

	for(int i = 0; i <= 2 * h; i++){
		mintotake[i] = std::min(mintotake[i], tempmintotake[i]);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){
		std::cout << "Case #" << testcase << ": ";

		std::cerr << testcase << std::endl;

		int q;
		std::cin >> h >> s >> q;

		for(int i = 0; i < h; i++){
			for(int j = 0; j < s; j++){
				char c;
				std::cin >> c;

				mat[j][i] = (c == 'B');
			}
		}

		for(int i = 0; i < 2 * maxn; i++){
			mintotake[i] = s * h;
			tempmintotake[i] = s * h;
		}

		// assume we start with A first
		solve();
		for(int i = 0; i < s; i++){
			for(int j = 0; j < h; j++){
				mat[i][j] = !mat[i][j];
			}
		}

		//assume we start with B first
		solve();

		int most = 2 * h;
		for(int i = 0; i <= 2 * h; i++){
			if(mintotake[i] == 0){
				most = i;
				break;
			}
		}

		for(int i = 0; i < q; i++){
			int k;
			std::cin >> k;

			int best = most;
			int l = 0, r = most;
			while(l <= r){
				int mid = (l + r) / 2;

				if(mintotake[mid] <= k){
					best = mid;
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}

			std::cout << best << ' ';
		}
		std::cout << '\n';
	}
}
