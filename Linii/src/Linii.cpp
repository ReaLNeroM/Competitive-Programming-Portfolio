#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	int a[n][m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}

	int sumr = 0;
	for(int i = 0; i < n; i++){
		int good = 0;
		for(int j = 0; j < m; j++){
			if(a[i][j] == 1){
				good++;

				if(good >= 3){
					sumr++;
					break;
				}
			} else {
				good = 0;
			}
		}
	}

	for(int j = 0; j < m; j++){
		int good = 0;
		for(int i = 0; i < n; i++){
			if(a[i][j] == 1){
				good++;

				if(good >= 3){
					sumr++;
					break;
				}
			} else {
				good = 0;
			}
		}
	}

	printf("%d", sumr);
}
