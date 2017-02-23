#include <iostream>

int main() {
	int n, linesize;
	std::cin >> n >> linesize;

	std::string str[n];
	int l[n], dp[n + 1], bestindex[n];
	for(int i = 0; i < n; i++){
		std::cin >> str[i];
		l[i] = str[i].length();
		dp[i] = 10000000;
		bestindex[i] = n;
	}

	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		for(int j = i + 1; j <= n; j++){
			int sum = 0;
			for(int k = i; k < j; k++){
				sum += str[k].length();
			}
			sum += j - i - 1;
			if(sum > linesize){
				sum = 10000000;
			} else{
				sum = (linesize - sum) * (linesize - sum);
			}
			if(dp[i] > sum + dp[j]){
				dp[i] = sum + dp[j];
				bestindex[i] = j;
			}
		}
	}

	int curr = 0;
	while(curr < n){
		for(int i = curr; i < bestindex[curr]; i++){
			std::cout << str[i] << " ";
		}
		std::cout << std::endl;

		curr = bestindex[curr];
	}
	return 0;
}
