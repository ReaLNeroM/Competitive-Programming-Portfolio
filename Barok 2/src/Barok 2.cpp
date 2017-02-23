#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
struct rect {
	int y1, y2;
	int x1;
	int val;

	bool operator<(rect const &x) const {
		return x1 < x.x1;
	}
};
std::vector <int> t;
std::vector <int> lazy;
int n;

void modify(int cl, int cr, int val, int l = 0, int r = n - 1, int ind = 0) {
	if (cl > r or cr < l) {
		return;
	} else if (l >= cl and r <= cr) {
		lazy[ind] += val;
		if (lazy[ind]) {
			t[ind] = r - l + 1;
		} else {
			t[ind] = 0;
			if (l != r) {
				t[ind] = t[2 * ind + 1] + t[2 * ind + 2];
			}
		}
		return;
	}

	int mid = l + (r - l) / 2;
	modify(cl, cr, val, l, mid, 2 * ind + 1);
	modify(cl, cr, val, mid + 1, r, 2 * ind + 2);
	if (!lazy[ind]) {
		t[ind] = t[2 * ind + 1] + t[2 * ind + 2];
	}
}

int query(int cl = 0, int cr = n - 1, int l = 0, int r = n - 1, int ind = 0) {
	if (cl > r or cr < l) {
		return 0;
	} else if (l >= cl and r <= cr) {
		return t[ind];
	} else if (lazy[ind] != 0) {
		return std::min(cr, r) - std::max(cl, l);
	}

	int mid = l + (r - l) / 2;
	return query(cl, cr, l, mid, 2 * ind + 1) + query(cl, cr, mid + 1, r, 2 * ind + 2);
}

int main() {
	int y, x;
	std::cin >> y >> x;
	n = y;

	int months;
	std::cin >> months;

	int buildings;
	std::cin >> buildings;
	std::vector <rect> r;
	for (int i = 0, by, bx; i < buildings; i++) {
		std::cin >> by >> bx;
		by--, bx--;
		int y1 = std::max(by - months, 0);
		int y2 = std::min(by + months, y - 1);
		int x1 = std::max(bx - months, 0);
		int x2 = std::min(bx + months, x - 1);

		rect copy;
		copy.y1 = y1;
		copy.y2 = y2;
		copy.x1 = x1;
		copy.val = 1;
		r.push_back(copy);
		copy.x1 = x2 + 1;
		copy.val = -1;
		r.push_back(copy);
	}
	std::sort(r.begin(), r.end());

	t.resize(4 * n, 0);
	lazy.resize(4 * n, 0);
	long long sum = 0;
	for (int i = 0; i < 2 * buildings - 1; i++) {
		modify(r[i].y1, r[i].y2, r[i].val);
		sum += ((ll) query()) * (r[i + 1].x1 - r[i].x1);
	}

	std::cout << sum;
	return 0;

}
