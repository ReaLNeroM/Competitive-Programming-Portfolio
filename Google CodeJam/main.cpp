#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e2 + 10;
const ll maxbit = (1 << 17);
const ll INF = 1000000000000000010;

std::string res[] = {
    "Case #1: IMPOSSIBLE",
"Case #2: IMPOSSIBLE",
"Case #3: IMPOSSIBLE",
"Case #4: POSSIBLE
1 1
2 3
1 5
2 2
1 4
2 1
1 3
2 5
1 2
2 4",
"Case #5: IMPOSSIBLE",
"Case #6: IMPOSSIBLE",
"Case #7: IMPOSSIBLE",
"Case #8: IMPOSSIBLE",
"Case #9: IMPOSSIBLE",
"Case #10: POSSIBLE
1 1
2 3
3 1
1 2
4 3
2 2
4 1
3 3
2 1
4 2
1 3
3 2",
"Case #11: IMPOSSIBLE",
"Case #12: IMPOSSIBLE",
"Case #13: POSSIBLE
4 2
1 1
3 2
5 1
2 2
4 1
1 2
3 1
5 2
2 1",
"Case #14: IMPOSSIBLE",
"Case #15: IMPOSSIBLE",
"Case #16: POSSIBLE
1 1
2 3
1 5
2 1
1 3
2 5
1 2
2 4
3 1
1 4
2 2
3 4
4 1
3 3
4 5
5 1
4 3
5 5
4 2
5 4
3 5
5 2
4 4
3 2
5 3"
};

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cin >> y >> x;
        std::cout << res[(y - 2) * 4 + (x - 2)] << std::endl;
	}
}
