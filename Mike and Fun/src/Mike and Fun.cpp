#include <iostream>
#include <map>

typedef long long ll;

int main() {
	ll y, x, queries;
	std::cin >> y >> x >> queries;

	std::map<ll, ll> in_a_row;

	bool mat[y][x];
	ll score[y];
	ll max, curr;
	for(ll i = 0; i < y; i++){
		max = 0, curr = 0;

		for(ll j = 0; j < x; j++){
			std::cin >> mat[i][j];

			if(!mat[i][j]){
				max = std::max(max, curr);
				curr = 0;
			} else {
				curr++;
			}
		}
		max = std::max(max, curr);

		score[i] = max;
		in_a_row[max]++;
	}

	ll res[queries];
	for(ll i = 0, qy, qx; i < queries; i++){
		std::cin >> qy >> qx;
		qy--, qx--;

		in_a_row[score[qy]]--;
		if(in_a_row[score[qy]] == 0){
			in_a_row.erase(in_a_row.find(score[qy]));
		}

		mat[qy][qx] = !mat[qy][qx];

		max = 0, curr = 0;
		for(ll j = 0; j < x; j++){
			if(!mat[qy][j]){
				max = std::max(max, curr);
				curr = 0;
			} else {
				curr++;
			}
		}

		max = std::max(max, curr);

		score[qy] = max;
		in_a_row[max]++;

		res[i] = in_a_row.rbegin()->first;
	}

	for(ll i = 0; i < queries; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
