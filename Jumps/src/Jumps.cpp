//============================================================================
// Name        : Jumps.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int main() {
    long long goal;
    std::cin >> goal;

    long long res = 0;

    res += (goal / 6) * (goal / 6 + 1) / 2 * 3;
    res += (goal / 6 + 1) * ((goal / 2) % 3 + 1);

    res += ((goal - 3) / 6) * ((goal - 3) / 6 + 1) / 2 * 3;
    res += ((goal - 3) / 6 + 1) * (((goal - 3) / 2) % 3 + 1);

    std::cout << res % 1000000;
    return 0;
}
