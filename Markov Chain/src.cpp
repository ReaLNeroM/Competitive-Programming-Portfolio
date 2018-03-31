#include <bits/stdc++.h>

typedef long long ll;

std::map<int, std::string> mapping;
std::map<std::string, int> reference;
std::map<std::pair<int, int>, int> occurences;
std::map<int, int> appearances_total;

int main(){
	std::ios::sync_with_stdio(false);

	int curr_start = 1;
	for(int x = 1; x <= 15; x++){
		std::string build = "Dataset/";
		build += ('0' + x / 10);
		build += ('0' + x % 10);
		build += ".txt";
		
		std::ifstream fin(build.c_str());

		std::string prev = "";

		std::string curr = "";
		while(fin >> curr){
			if(prev != ""){
				int reference_prev = reference[prev];
				int reference_curr = reference[curr];

				if(reference_prev == 0){
					reference_prev = reference[prev] = curr_start;
					mapping[reference_prev] = prev;
					curr_start++;
				}
				if(reference_curr == 0){
					reference_curr = reference[curr] = curr_start;
					mapping[reference_curr] = curr;
					curr_start++;
				}

				occurences[{reference_prev, reference_curr}]++;
				appearances_total[reference_prev]++;
			}

			prev = curr;
			curr = "";
		}
	}

	int curr = 1100;
	for(int i = 1100; i <= 1200; i++){
		std::cout << mapping[i] << '\n';
		if(appearances_total[curr] < appearances_total[i]){
			curr = i;
		}
	}

	std::srand(1353203);
	for(int i = 0; i < 50; i++){
		std::cout << mapping[curr] << ' ';

		//go to the next state

		int forward_size = appearances_total[curr];

		if(forward_size == 0){
			std::cout << '\n' << "What the hell, there is no forward edge!" << '\n';
			break;
		}

		int searching_for = std::rand() % forward_size;

		auto ite = occurences.lower_bound({curr, 0});

		while(ite != occurences.end()){
			if(searching_for < ite->second){
				curr = ite->first.second;
				break;
			} else {
				searching_for -= ite->second;
			}
			ite++;
		}
	}
}
