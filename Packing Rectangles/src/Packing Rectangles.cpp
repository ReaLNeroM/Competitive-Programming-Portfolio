/*
 ID: vlade.m1
 PROG: packrec
 LANG: C++
 */

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 4;
pair<int, int> p[maxn], orig[maxn];
pair<int, int> place[maxn];
int able[205][205];

bool overlap_point(pair<int, int> point, int rect) {
	for (int i = 0; i < rect; i++) {
		if (place[i].first <= point.first
				and point.first <= p[i].first + place[i].first) {
			if (place[i].second <= point.second
					and point.second <= p[i].second + place[i].second) {
				return true;
			}
		}
	}

	return false;
}
bool overlap(int rect) {
	int y1 = place[rect].first, y2 = place[rect].first + p[rect].first;
	int x1 = place[rect].second, x2 = place[rect].second + p[rect].second;

	for (int i = 0; i < rect; i++) {
		if (!(place[i].first + p[i].first <= y1 or y2 <= place[i].first)) {
			if (!(place[i].second + p[i].second <= x1 or x2 <= place[i].second)) {
				return true;
			}
		}
	}

	return false;
}
void check() {
	int sum_y = 0, sum_x = 0;
	for (int i = 0; i < 4; i++) {
		if (overlap(i)) {
			return;
		}
		sum_y = max(sum_y, p[i].first + place[i].first);
		sum_x = max(sum_x, p[i].second + place[i].second);
	}
	if(sum_y >= 205 or sum_x >= 205){
		return;
	}
	able[sum_y][sum_x] = true;
	able[sum_x][sum_y] = true;
}

void end_this() {
	int largest_x = 0;
	for(int i = 0; i < 3; i++){
		if(place[i].first == 0){
			largest_x = max(largest_x, place[i].second + p[i].second);
		}
	}
	place[3] = {0, largest_x};
	check();
	for (int i = 0; i < 3; i++) {
		for (int j = place[i].second; j < place[i].second + p[i].second; j++) {
			place[3] = {place[i].first + p[i].first, j};
			if (!overlap(i)) {
				check();
			}
		}
	}
}
void try_this() {
	place[0] = {0, 0};
	place[1] = {0, p[0].second};
	for(int i = 0; i < 205; i++) {
		for(int j = 0; j < 205; j++) {
			if(i == 0 or overlap_point( {i - 1, j}, 2)) {
				place[2] = {i, j};
				if(!overlap(2)) {
					end_this();
					break;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);

	for (int i = 0; i < 4; i++) {
		cin >> p[i].first >> p[i].second;
		orig[i].first = p[i].first;
		orig[i].second = p[i].second;
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < maxn; j++) {
			p[j] = orig[j];
		}
		for (int j = 0, bit = 1; j < 4; j++, bit *= 2) {
			if (bit & i) {
				swap(p[j].first, p[j].second);
			}
		}
		sort(p, p + 4);
		do {
			try_this();
		} while (next_permutation(p, p + maxn));
	}

	int min_area = 2000000;
	for (int i = 0; i < 205; i++) {
		for (int j = 0; j < 205; j++) {
			if (able[i][j]) {
				min_area = min(min_area, i * j);
			}
		}
	}
	cout << min_area << endl;
	for (int i = 0; i < 205; i++) {
		for (int j = i; j < 205; j++) {
			if (able[i][j] and i * j == min_area) {
				cout << i << ' ' << j << endl;
			}
		}
	}
}

