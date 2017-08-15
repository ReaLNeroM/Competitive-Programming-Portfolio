#include <bits/stdc++.h>

typedef long long ll;

int left[26];
int right[26];
int need[26];

const int maxa = 3e7 + 1e2;
const int maxb = 3e6 + 1e2;
char a[maxa];
char b[maxb];
char res[maxb];

int main(){
	scanf("%s %s", a, b);

	for(char i : b){
		need[i - 'a']++;
	}
	for(char i : a){
		left[i - 'a']++;
	}

	int unsatisfied = 0;

	for(int i = 0; i < 26; i++){
		unsatisfied += (need[i] != 0);
	}

	int asize = strlen(a);
	int bsize = strlen(b);

	int l = -1;
	int r = asize;
	while(r > 0 and unsatisfied){
		if(r != asize){
			left[a[r] - 'a']--;
		}

		r--;

		right[a[r] - 'a']++;

		if(right[a[r] - 'a'] == need[a[r] - 'a']){
			unsatisfied--;
		}
	}

	if(r == 0 and unsatisfied){
		printf("impossible\n");
		return 0;
	}

	int respos = 0;

	for(int i = 0; i < bsize; i++){
		for(int j = 0; j < 26; j++){
			if(left[j] and need[j]){
				res[respos] = 'a' + j;
				respos++;

				if(respos == bsize){
					j = 26;
					break;
				}

				need[j]--;

				do {
					l++;
					left[a[l] - 'a']--;
				} while(a[l] != (char) ('a' + j));

				if(l == r){
					right[a[r] - 'a']--;
					r++;
					left[a[r] - 'a']++;
				}

				while(right[a[r] - 'a'] > need[a[r] - 'a']){
					right[a[r] - 'a']--;
					r++;
					left[a[r] - 'a']++;
				}

				break;
			}
		}
	}

	res[respos] = '\0';
	printf("%s\n", res);
}
