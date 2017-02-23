/*
 #include <iostream>
 #include <queue>

 int main() {
 int pos, size, cekori;
 std::cin >> pos >> size >> cekori;
 std::queue<int> q;
 q.push(pos);

 for (int i = 0; i < cekori; i++) {
 int c;
 std::cin >> c;

 bool used[size + 1];

 for (int i = 0; i < size + 1; i++) {
 used[i] = false;
 }

 for (int i = q.size(); i > 0; i--) {
 for (int j = -1; j != 3; j += 2) {
 int result = q.front() + (j * c);
 if (result >= 0 and result <= size and !used[result]) {
 q.push(result);
 used[result] = true;
 }
 }
 q.pop();
 }
 }

 int bestval = -1;
 while (!q.empty()) {
 bestval = std::max(bestval, q.front());
 q.pop();
 }

 std::cout << bestval;
 }
 */

#include <iostream>
#include <queue>
#define start n

int main() {
	int n, end;
	std::cin >> start;
	std::queue<int> q;
	q.push(start);

	std::cin >> end >> n;

	int step;
	bool tookpos[end + 1];
	for (int i = 0; i < n; i++) {
		std::cin >> step;
		for (int i = 0; i <= end; i++) {
			tookpos[i] = false;
		}

		for (int i = q.size(); i > 0; i--) {
			for (int i = -1; i < 2; i += 2) {
				int fr = q.front() + (i * step);

				if (fr <= end and fr >= 0 and !tookpos[fr]) {
					q.push(fr);
					tookpos[fr] = true;
				}
			}
			q.pop();
		}
	}

	int max = -1;
	while(!q.empty()){
		max = std::max(max, q.front());
		q.pop();
	}

	std::cout << max;
}
