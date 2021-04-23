// https://nadc21.kattis.com/problems/nadc21.youbethejudge

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

void ensurethat(bool b){
    if(!b){
        cout << 0 << endl;
        exit(0);
    }
}
int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    vector<string> tokens;

    string currtoken = "";
    char c;
    while(cin.get(c)){
        if(isspace(c)){
            if(currtoken != ""){
                tokens.push_back(currtoken);
                currtoken = "";
            }
            continue;
        }

        currtoken += c;
    }
    if(currtoken != ""){
        tokens.push_back(currtoken);
        currtoken = "";
    }

    ensurethat(tokens.size() == 3);
    vector<ll> nums;

    for(auto token : tokens){
        ll build = 0;
        for(char i : token){
            if('0' <= i and i <= '9'){
                build *= 10;
                build += i - '0';
                ensurethat(build <= 1000000000LL);
            } else {
                ensurethat(false);
            }
        }
        ensurethat(token[0] != '0');
        nums.push_back(build);
    }

    ensurethat(nums.size() == 3);
    ensurethat(nums[0] % 2 == 0);
    ensurethat(nums[0] > 3);
    ensurethat(nums[0] <= 1000000000);

    ensurethat(nums[1] + nums[2] == nums[0]);

    for(ll a = 2; a < 100000; a++){
        ensurethat(a >= nums[1] or nums[1] % a != 0);
        ensurethat(a >= nums[2] or nums[2] % a != 0);
    }

    cout << 1 << endl;
}
