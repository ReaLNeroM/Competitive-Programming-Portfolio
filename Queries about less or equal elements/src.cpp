#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
    int x, y;
    std::cin >> x >> y;

    int vala[x];
    for(int i = 0; i < x; i++){
        std::cin >> vala[i];
    }
    std::sort(vala, vala + x);

    int valb[y];
    for(int i = 0; i < y; i++){
        std::cin >> valb[i];

        int l = 0, r = x - 1;
        while(l <= r){
            int mid = (l + r) / 2;

            if(vala[mid] > valb[i]){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        valb[i] = r + 1;
    }

    for(int i = 0; i < y; i++){
        std::cout << valb[i] << ' ';

    }
    return 0;
}