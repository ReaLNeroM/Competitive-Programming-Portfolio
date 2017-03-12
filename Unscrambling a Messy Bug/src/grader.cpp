#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace helper {

    set<string> set_;
    bool compiled = false;
    int n;
    vector<int> p;
    int w;
    int r;

    int read_int() {
        int x;
        cin >> x;
        return x;
    }

}

using namespace helper;


// A convenience function.
int get_p(int i) {
    int ret = p[i];
    return ret;
}


void wa() {
    printf("WA\n");
    exit(0);
}

bool check(const string& x) {
    if ((int)x.length() != n) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        if (x[i] != '0' && x[i] != '1') {
            return false;
        }
    }
    return true;
}

void add_element(string x) {
    if (--w < 0 || compiled || !check(x)) {
        wa();
    }
    set_.insert(x);
}

bool check_element(string x) {
    if (--r < 0 || !compiled || !check(x)) {
        wa();
    }
    return set_.count(x);
}

void compile_set() {
    if (compiled) {
        wa();
    }
    compiled = true;
    set<string> compiledSet;
    string compiledElement = string(n, ' ');
    for (set<string>::iterator it = set_.begin(); it != set_.end(); it++) {
        string s = *it;
        for (int i = 0; i < n; i++) {
            compiledElement[i] = s[get_p(i)];
        }
        compiledSet.insert(compiledElement);
    }
    set_ = compiledSet;
}

#include <bits/stdc++.h>

std::vector<int> perm;

void dfs(int l, int r, std::vector<int> cand, std::string ord){
	if(l + 1 == r){
		ord[cand[0]] = '1';
		if(check_element(ord)){
			perm[cand[0]] = l;
			perm[cand[1]] = r;
		} else {
			perm[cand[1]] = l;
			perm[cand[0]] = r;
		}
		ord[cand[0]] = '0';
	} else {
		std::vector<int> sub_cand;
		std::vector<int> other_cand;
		std::string sub_ord = ord, other_ord = ord;
		for(int i = 0; i < cand.size(); i++){
			ord[cand[i]] = '1';
			if(check_element(ord)){
				sub_cand.push_back(cand[i]);
				sub_ord[cand[i]] = '1';
			} else {
				other_cand.push_back(cand[i]);
				other_ord[cand[i]] = '1';
			}
			ord[cand[i]] = '0';
		}

		dfs(l, l + (r - l + 1) / 2 - 1, sub_cand, other_ord);
		dfs(l + (r - l + 1) / 2, r, other_cand, sub_ord);
	}
}

std::vector<int> restore_permutation(int n, int w, int r) {
	for(int i = n; i >= 2; i /= 2){
		for(int j = 0; j < n; j += i){
			std::string made = "";
			for(int k = 0; k < n; k++){
				if(j <= k and k < j + i){
					made += '0';
				} else {
					made += '1';
				}
			}
			for(int k = 0; k < n; k++){
				if(j <= k and k < j + (i / 2)){
					made[k] = '1';
					add_element(made);
					made[k] = '0';
				}
			}
		}
	}

	compile_set();

	std::vector<int> cand;
	for(int i = 0; i < n; i++){
		cand.push_back(i);
		perm.push_back(0);
	}

	std::string ord = std::string(n, '0');
	dfs(0, n - 1, cand, ord);

	return perm;
}


int main() {
    n = read_int();
    w = read_int();
    r = read_int();
    p = vector<int>(n);
    for (int i = 0; i < n; i++) {
        p[i] = read_int();
    }
    vector<int> answer = restore_permutation(n, w, r);

    if (answer.size() != n) {
        printf("WA\n");
        return 0;
    }


    printf("%d", answer[0]);

    for (int i = 1; i < n; i++) {
        printf(" %d", answer[i]);
    }
    printf("\n");
    return 0;
}
