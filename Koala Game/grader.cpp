#include "koala.h"

#include <stdio.h>
#include <stdlib.h>

static int N, W;
static int P[105];

static int maxQueries = 3200;
static int numQueries;

static void runGame(int F);
static void grader();

int main() {
    grader();
    return 0;
}

void playRound(int *B, int *R) {
    int i, j;

    int S = 0;
    for (i=0;i<N;++i) {
        if ( !(B[i] >= 0 && B[i] <= W) ) {
            printf("Invalid query.\n");
            exit(0);
        }
        S += B[i];
    }
    if (S > W) {
        printf("Invalid query.\n");
        exit(0);
    }

    numQueries++;
    if (numQueries > maxQueries) {
        printf("Too many queries.\n");
        exit(0);
    }

    int cache[2][205];
    int num[2][205];
    char taken[105][205];

    for (i=0;i<205;++i) {
        cache[1][i] = 0;
        num[1][i] = 0;
    }

    for (i=0;i<N;++i) {
        int v = B[i]+1;
        int ii = i&1;
        int o = ii^1;
        for (j=0;j<=W;++j) {
            cache[ii][j] = cache[o][j];
            num[ii][j] = num[o][j];
            taken[i][j] = 0;
        }
        for (j=W;j>=v;--j) {
            int h = cache[o][j-v] + P[i];
            int hn = num[o][j-v] + 1;
            if (h > cache[ii][j] || (h == cache[ii][j] && hn > num[ii][j])) {
                cache[ii][j] = h;
                num[ii][j] = hn;
                taken[i][j] = 1;
            } else {
                taken[i][j] = 0;
            }
        }
    }

    int cur = W;
    for (i=N-1;i>=0;--i) {
        R[i] = taken[i][cur] ? (B[i] + 1) : 0;
        cur -= R[i];
    }
}

static void runGame(int F) {
    int i;

    scanf("%d %d",&N,&W);
    int smallest = 0, biggest = 0;

    for (i=0;i<N;++i) {
        P[i] = i;
        // scanf("%d",&P[i]);
    }
    int first_two = 0;
    if(P[1] > P[0]){
        first_two = 1;
    }

    for(int i = 0; i < N; i++){
        if(P[smallest] > P[i]){
            smallest = i;
        }
        if(P[biggest] < P[i]){
            biggest = i;
        }
    }

    numQueries = 0;
    if (F == 1 and minValue(N, W) != smallest) {
        printf("%d %d\n", minValue(N, W), smallest);
    } else if (F == 2 and maxValue(N, W) != biggest) {
        printf("%d %d\n", maxValue(N, W), biggest);
    } else if (F == 3 and greaterValue(N, W) != first_two) {
        printf("%d\n", greaterValue(N, W));
    } else if (F == 4 and W == N) {
        
        int userP[105];
        allValues(N, W, userP);
        for (i=0;i<N;i++) {
            printf("%d ",userP[i]);
        }
        printf("\n");
    }
    int allowed[] = {0, 1, 4, 4, 10000};
    if(allowed[F] < numQueries){
        printf("Made %d calls to playRound.\n", numQueries);
    }
}

static void grader() {
    int i;

    int F, G;
    scanf("%d %d %d",&F,&G,&i);

    for (i=0;i<G;i++) {
        runGame(F);
    }
}
