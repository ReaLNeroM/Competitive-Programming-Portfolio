#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int val[maxn];
std::vector<std::string> results;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int test_cases;
    std::cin >> test_cases;

    for(int test_case = 1; test_case <= test_cases; test_case++){
        std::string s;
        std::cin >> s;

        int n = s.size();

        std::reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++){
            val[i] = (s[i] - '0');
        }

        for(int j = 0; j < 25; j++){
            std::string s;
            results.push_back(s);
            results[results.size() - 1].resize(n);

            for(int j = 0; j < n / 2; j++){
                results[results.size() - 1][j] = (char) (val[n - 1 - j] + '0');
            }
            for(int j = n / 2; j < n; j++){
                results[results.size() - 1][j] = (char) (val[j] + '0');
            }

            bool first_part_is_bigger = false;
            for(int k = n-1; k >= 0; k--){
                if(results[results.size() - 1][k] - '0' > val[k]){
                    first_part_is_bigger = true;
                    break;
                } else if(results[results.size() - 1][k] - '0' < val[k]){
                    break;
                }
            }

            if(first_part_is_bigger){
                int carry = 1;
                for(int k = n / 2; k < n; k++){
                    results[results.size() - 1][k] -= carry;
                    if(results[results.size() - 1][k] - '0' < 0){
                        results[results.size() - 1][k] += 10;
                        carry = 1;
                    } else {
                        carry = 0;
                        break;
                    }
                }

                for(int k = n / 2 - 1; k >= 0; k--){
                    results[results.size() - 1][k] = results[results.size() - 1][n - 1 - k];
                }
            }

            int carry = 0;
            int new_n = 0;

            for(int j = 0; j < n; j++){
                val[j] = val[j] - (results[results.size() - 1][j] - '0' + carry);
                if(val[j] < 0){
                    val[j] += 10;
                    carry = 1;
                } else {
                    carry = 0;
                }

                if(val[j] != 0){
                    new_n = j + 1;
                }
            }

            n = new_n;

            if(n == 0){
                break;
            }
        }

        std::cout << results.size() << '\n';
        for(int i = 0; i < results.size(); i++){
            std::reverse(results[i].begin(), results[i].end());

            std::cout << results[i] << '\n';
        }

        results.clear();
    }
}
