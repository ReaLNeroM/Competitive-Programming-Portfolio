#include <iostream>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);

    int broevi, razlika;
    std::cin >> broevi >> razlika;
    std::map<int, int> m;
    int natpr[broevi];
    for(int i = 0; i < broevi; i++){
        std::cin >> natpr[i];
        m[natpr[i]]++;
    }

    long long res = 0;
    for(int i = 0; i < broevi; i++){
        if(razlika == 0){
            m[natpr[i]]--;
        }
        long long one = (long long) m[natpr[i] + razlika];

        res += one;
    }

    std::cout << res;
    return 0;
}
