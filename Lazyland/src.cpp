#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
ll chosen[maxn];
ll persuasion[maxn];
ll ind[maxn];
ll used[maxn];

bool cmp(ll a, ll b){
	return persuasion[a] > persuasion[b];
}

int main(){
	std::ios::sync_with_stdio(false);

	ll idlers, jobs;
	std::cin >> idlers >> jobs;

	for(ll i = 0; i < idlers; i++){
		std::cin >> chosen[i];
	}
	for(ll i = 0; i < idlers; i++){
		std::cin >> persuasion[i];
	}
	for(ll i = 0; i < idlers; i++){
		ind[i] = i;	
	}

	std::sort(ind, ind + idlers, cmp);

	std::vector<ll> bb;
	ll taken = 0;
	for(ll i = 0; i < idlers; i++){
		ll curr = ind[i];

		if(!used[chosen[curr]]){
			used[chosen[curr]] = true;
			jobs--;
		} else {
			bb.push_back(persuasion[curr]);
		}
	}

	std::sort(bb.begin(), bb.end());
	ll res = 0;
	for(ll i = 0; i < jobs; i++){
		res += bb[i];
	}
	std::cout << res << '\n';

}www