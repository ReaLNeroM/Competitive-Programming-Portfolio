#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int p[maxn];
int q[maxn];

int findSample(int n,int confidence[],int host[],int protocol[]){
	for(int i = 0; i < n; i++){
		p[i] = confidence[i];
		q[i] = 0;
	}

	for(int i = n - 1; i > 0; i--){
		if(protocol[i] == 0){
			p[host[i]] += q[i];
			q[host[i]] += max(p[i], q[i]);
		} else if(protocol[i] == 1){
			p[host[i]] = max(max(p[host[i]] + q[i], p[i] + q[host[i]]), p[i] + p[host[i]]);
			q[host[i]] += q[i];
		} else if(protocol[i] == 2){
			p[host[i]] = max(p[host[i]] + q[i], p[i] + q[host[i]]);
			q[host[i]] += q[i];
		}
	}

	return max(p[0], q[0]);
}
