#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];
std::map<ll, ll> m;
std::pair<ll, ll> frog[maxn];
std::map<ll, ll> back_to_index;
ll final_length[maxn];
ll eaten[maxn];
std::multimap<ll, ll> mosquitoes_left;

bool push_update(ll pos){
	auto fir = mosquitoes_left.lower_bound(pos);
	auto ite = m.lower_bound(pos);

	if(ite == m.end() or fir == mosquitoes_left.end() or !(ite->second <= fir->first and fir->first <= ite->first)){
		return false;
	}

	ll start = ite->second;
	ll end = ite->first;

	while(ite != m.end() and start <= ite->second and ite->first <= end + fir->second){
		auto sec = ite;
		ite++;
		m.erase(sec);
	}

	eaten[back_to_index[start]]++;
	final_length[back_to_index[start]] = end + fir->second - start;

	m[end + fir->second] = start;
	mosquitoes_left.erase(fir);

	return true;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll frogs, mosquitoes;
	std::cin >> frogs >> mosquitoes;

	for(ll i = 0; i < frogs; i++){
		std::cin >> frog[i].first >> frog[i].second;
		back_to_index[frog[i].first] = i;
		final_length[i] = frog[i].second;
	}

	std::sort(frog, frog + frogs);

	int biggest = -1;
	for(ll i = 0; i < frogs; i++){
		if(frog[i].first + frog[i].second > biggest){
			m[frog[i].first + frog[i].second] = frog[i].first;
			biggest = frog[i].first + frog[i].second;
		}
	}

	for(ll i = 0; i < mosquitoes; i++){
		ll pos, size;
		std::cin >> pos >> size;

		mosquitoes_left.insert({pos, size});

		while(push_update(pos)){
		}
	}

	for(ll i = 0; i < frogs; i++){
		std::cout << eaten[i] << ' ' << final_length[i] << '\n';
	}
}
