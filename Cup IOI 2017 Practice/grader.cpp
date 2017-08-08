#include "cup.h"
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

static const int WORLD_SIZE = 1000 * 1000 * 1000;
static int t;
static vector<int> a, b, qc;

static void wrong_answer() {
    printf("%d\n", -1);
    exit(0);
}

int ask_shahrasb(int x, int y) {
    qc[t]++;
    if (abs(x) > WORLD_SIZE || abs(y) > WORLD_SIZE) {
        wrong_answer();
    }
    int dx = a[t] - x;
    int dy = b[t] - y;
    return abs(dx) ^ abs(dy);
}

int main() {
    int tests;
    assert(1 == scanf("%d", &tests));
    a.resize(tests);
    b.resize(tests);
    qc.resize(tests);
    std::srand(60);

    for (t = 0; t < tests; t++) {
        a[t] = rand() % 1000000001;
        b[t] = rand() % 1000000001;
        a[t] -= 500000000;
        b[t] -= 500000000;
        // assert(2 == scanf("%d %d", &a[t], &b[t]));
    }
    for (t = 0; t < tests; t++) {
        // std::cout << a[t] << ' ' << b[t] << std::endl;
        qc[t] = 0;
        vector<int> result = find_cup();
        if (int(result.size()) != 2) {
            wrong_answer();
        }
        int x = a[t];
        int y = b[t];
        if (result[0] != x || result[1] != y) {
            qc[t] = -1;
        }
        // std::cout << result[0] << ' ' << result[1] << ' ';
        std::cout << qc[t] << std::endl;
    }
    for (t = 0; t < tests; t++) {
    }
    return 0;
}
