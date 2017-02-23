#include <iostream>
#include <deque>

using namespace std;

int main() {
	int kids, balls;
	std::cin >> kids >> balls;

	int highend = balls % kids;
	int kidx[kids], needed[kids];
	for(int i = 0; i < kids; i++){
		std::cin >> kidx[i];
		needed[i] = balls / kids;
		if(i < highend){
			needed[i]++;
		}
	}

	std::deque<std::pair<int, int> > d;
	std::pair<int, int> copy;

	int max = 0;
	for(int i = 0; i < kids; i++){
		copy.first = i;
		int num = kidx[i];
		while(!d.empty() and d.front().first < i and num > 0){
			max = std::max(max, i - d.front().first);
			if(d.front().second > num){
				d.front().second -= num;
				copy.second = num;
				num = 0;
			} else {
				num -= d[0].second;
				copy.second = d[0].second;
				d.pop_front();
			}

			d.push_back(copy);
		}

		if(kidx[i] > needed[i]){
			copy.second = kidx[i] - needed[i];
			d.push_back(copy);
			kidx[i] = needed[i];
		} else {
			num = needed[i] - kidx[i];
			while(!d.empty() and d.front().first < i and num > 0){
				max = std::max(max, i - d.front().first);
				if(d[0].second > num){
					d[0].second -= num;
					copy.second = num;
					num = 0;
				} else {
					num -= d[0].second;
					copy.second = d[0].second;
					d.pop_front();
				}
			}
			kidx[i] = needed[i];
		}
	}

	std::cout << max;
	return 0;
}
