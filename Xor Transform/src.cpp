#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct SplitMix64 {
    unsigned long long nextInt() {
        unsigned long long z = (x += 0x9E3779B97F4A7C15ULL);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
        return z ^ (z >> 31);
    }
    
    int random() {
        return 1 + (nextInt() >> 33);
    }
    
    unsigned long long x;
};

int res[4];
void init(const vector< vector<int> >& A) {
    int y = A.size();
    int x = A[0].size();
    
    vector<vector<int>> B = A;

    for(int iteration = 0; iteration < 4; iteration++){
        res[iteration] = B[0][0];

        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                if(i != y - 1){
                    B[i][j] ^= B[i + 1][j];
                }
                if(j != x - 1){
                    B[i][j] ^= B[i][j + 1];
                }
                if(i != y - 1 and j != x - 1){
                    B[i][j] ^= B[i + 1][j + 1];
                }
                
                std::cout << B[i][j] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}

int query(int K) {
    return res[K % 4];
}

int main() {
    int N, M, Q; 
    SplitMix64 rng;
    
    cin >> N >> M >> Q >> rng.x;
    
    vector< vector<int> > A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = rng.random();
        }
    }
    
    init(A);
    
    unsigned long long hashSol = 0;
    
    for (int i = 1; i <= Q; i++) {
        hashSol ^= (unsigned long long)i * query(rng.random());
    }
    
    cout << hashSol << endl;
}

