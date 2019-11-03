#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
static int val[maxn];
static int electionNumber[maxn];
static int aVotes[maxn];
static int bVotes[maxn];
static int sum[maxn];
static int sumA[maxn];
static int sumB[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int group, election;
	std::cin >> group >> election;

	long long votes = 0;
	for(int i = 0; i < group; i++){
		std::cin >> electionNumber[i] >> aVotes[i] >> bVotes[i];
		votes += aVotes[i] + bVotes[i];
		electionNumber[i]--;
		sumA[electionNumber[i]] += aVotes[i];
		sumB[electionNumber[i]] += bVotes[i];

		sum[electionNumber[i]] += aVotes[i];
		sum[electionNumber[i]] -= bVotes[i];
	}

	long long wastedA = 0;
	long long wastedB = 0;
	for(int i = 0; i < election; i++){
		if(sum[i] == 0){
			continue;
		} else if(sum[i] > 0){
			std::cout << 'A' << ' ' << (sum[i] - 1) / 2 << ' ' << sumB[i] << '\n';
			wastedA += (sum[i] - 1) / 2;
			wastedB += sumB[i];
		} else {
			std::cout << 'B' << ' ' << sumA[i] << ' ' << (- sum[i] - 1) / 2 << '\n';
			wastedA += sumA[i];
			wastedB += (- sum[i] - 1) / 2;
		}
	}
	std::cout.precision(12);

	std::cout << std::fixed << (long double) std::abs(wastedA - wastedB) / votes << '\n';

}