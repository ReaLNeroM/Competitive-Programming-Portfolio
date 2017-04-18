#include <bits/stdc++.h>

typedef long long ll;

const ll max_sq = 500000; //a lot more than the maximum, just to be sure

ll time_taken_on_full(ll health, ll k_dmg, ll turns){
	if(turns <= 0){
		return 0;
	} else if(turns <= 1){
		return 1;
	}

	ll how_many_per_swipe = (health - 1) / k_dmg;

	if(how_many_per_swipe <= 0){
		return 1e9;
	} else {
		ll swipes_needed = (turns + how_many_per_swipe - 1 - 1) / how_many_per_swipe;
		return swipes_needed + turns;
	}
}

int main(){
	ll t;
	std::cin >> t;

	for(ll x = 0; x < t; x++){
		ll dragon_h, dragon_d, knight_h, knight_d, boost, debuff;
		std::cin >> dragon_h >> dragon_d >> knight_h >> knight_d >> boost >> debuff;

		ll free_needed = max_sq;
		for(ll boosts_taken = 0; boosts_taken < max_sq; boosts_taken++){
			free_needed = std::min(free_needed, boosts_taken
									 + (knight_h + (dragon_d + boost * boosts_taken) - 1) / (dragon_d + boost * boosts_taken));
		}

		ll best = 1e9;
		ll curr_health = dragon_h;
		for(ll debuffs_made = 0; knight_d >= 0 and debuffs_made <= 1100000000 and (debuffs_made == 0 or debuff != 0); debuffs_made++){
			if(debuffs_made % 1000000 == 0 and debuffs_made > 1){
				std::cerr << debuffs_made / 1000000 << std::endl;
			}

			if(knight_d == 0){
				best = std::min(best, free_needed + debuffs_made);
				break;
			} else {
				if(free_needed <= (curr_health - 1) / knight_d + 1){
					best = std::min(best, debuffs_made + free_needed);
				} else {
					best = std::min(best, debuffs_made + (curr_health - 1) / knight_d + time_taken_on_full(dragon_h - knight_d, knight_d, free_needed - (curr_health - 1) / knight_d));
				}
			}

			if(curr_health - (knight_d - debuff) <= 0){
				curr_health = dragon_h - (knight_d);
			} else {
				knight_d -= debuff;
				if(knight_d < 0){
					knight_d = 0;
				}
				curr_health -= knight_d;
			}
		}
		std::cerr << x + 1 << std::endl;
		std::cout << "Case #" << x + 1 << ": ";

		if(best == 1e9){
			std::cout << "IMPOSSIBLE";
		} else {
			std::cout << best;
		}

		std::cout << std::endl;
	}
}