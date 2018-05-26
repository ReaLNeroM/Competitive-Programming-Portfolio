#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<string> split_string(string);

ll inverse(ll a, ll m){
	if(a == 0){
		return -1;
	}
	
    ll exponent = m - 2;
    ll product = 1;

    while(exponent){
        if(exponent & 1){
            product = (product * a) % m;
        }

        a = (a * a) % m;

        exponent /= 2;
    }

    return product;
}

// Complete the howManyGoodSubarrays function below.
long howManyGoodSubarrays(vector<int> A, int m, int given_k) {
    ll n = A.size();
    ll mod = m;
    ll k = given_k;

    vector<ll> v(n);
    for(ll i = 0; i < n; i++){
        v[i] = A[i] % mod;
    }
    
    ll res = 0;

    if(k == 0){
        ll seen = -1;
        for(ll i = 0; i < n; i++){
            if(v[i] == 0){
                seen = i;
            }

            res += seen + 1;
        }

        return res;
    }

    std::queue<ll> ql, qr;
    ql.push(0), qr.push(n - 1);
    while(!ql.empty()){
        ll l = ql.front(), r = qr.front();
        ql.pop(), qr.pop();

        if(l == r){
            if(v[l] == k){
                res++;
            }

            continue;
        }

        ll mid = (l + r) / 2;

        std::map<ll, ll> m;

        ll producted = 1;
        for(ll i = mid; i >= l; i--){
            producted = (producted * v[i]) % mod;
            m[producted]++;
        }

        producted = 1;
        for(ll i = mid + 1; i <= r; i++){
            producted = (producted * v[i]) % mod;
            res += m[(inverse(producted, mod) * k) % mod];
        }

        ql.push(l), qr.push(mid);
        ql.push(mid + 1), qr.push(r);
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nmk_temp;
        getline(cin, nmk_temp);

        vector<string> nmk = split_string(nmk_temp);

        int n = stoi(nmk[0]);

        int m = stoi(nmk[1]);

        int k = stoi(nmk[2]);

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        long result = howManyGoodSubarrays(A, m, k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
