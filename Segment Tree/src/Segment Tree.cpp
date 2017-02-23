#include <iostream>
#include <vector>

int n;  // array size
std::vector<int> t;

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void push() {
  for (int i = 1; i < n; ++i) {
    t[2 * i    ] += t[i];
    t[2 * i + 1] += t[i];
    t[i] = 0;
  }
}

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

int query(int p) {
  int res = 0;
  for (p += n; p > 1; p >>= 1){
	  res += t[p];
  }
  return res;
}
int main() {
	std::cin >> n;
	t.resize(2 * n);
	for (int i = 0; i < n; i++) {
		std::cin >> t[n + i];
	}
	build();
	modify(0, 5, 1);

	push();

	std::cout << t[n + 1];
	return 0;
}
