#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int wa, wb, sa, sb, dissolvepercent, sum;
	std::cin >> wa >> wb >> sa >> sb >> dissolvepercent >> sum;

	int ra = 0, rb = 1;

	for(int i = 0; i <= sum; i += wa * 100){
		for(int j = 0; i + j <= sum; j += wb * 100){
			int water_sum = i + j;
			for(int k = 0; water_sum + k <= sum; k += sa){
				for(int l = 0; water_sum + k + l <= sum; l += sb){
					int sugar_sum = k + l;
					if(water_sum / 100 * dissolvepercent >= sugar_sum){
						if(sugar_sum * (ra + rb) >= ra * (water_sum + sugar_sum)){
							ra = sugar_sum;
							rb = water_sum;
						}
					}
				}
			}
		}
	}

	std::cout << ra + rb << ' ' << ra << std::endl;
}