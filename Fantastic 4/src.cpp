#include <bits/stdc++.h>

typedef long long ll;

int main(){
    std::ios::sync_with_stdio(false);
    
	std::vector<ll> v(4);    

	std::cin >> v[0] >> v[1] >> v[2] >> v[3];	
	std::sort(v.begin(), v.end());

	// boost v[3];
	ll small = v[0];

	v[0] -= small;
	v[1] -= small;
	v[2] -= small;
	v[3] += 2 * small;

	// boost v[0] then v[3] then v[3]
	small = v[1] / 3;

	v[0] -= small * 2 - small * 2;
	v[1] -= small * 3;
	v[2] -= small * 3;
	v[3] += small * 3;

	ll most = v[3];

	int steps = 0;
	while(true){
		std::sort(v.begin(), v.end());

		if(v[0] == 0 and v[1] == 0){
			break;
		} else if(v[0] != 0){
			v[0]--;
			v[1]--;
			v[2]--;
			v[3] += 2;
		} else {
			v[0] += 2;
			v[1]--;
			v[2]--;
			v[3]--;
		}

		if(steps > 1000){
			break;
		}
		
		steps++;
		if(v[3] > most){
			steps = 0;
			most = v[3];
		}
	}

	std::cout << most << std::endl;
}