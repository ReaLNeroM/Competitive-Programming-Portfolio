#include <iostream>
#include <vector>
#include <utility>

//u tretio test primer e greskata

//-1 se pecate SAMO ako nema granica kolku daleko ode
using namespace std;
typedef long long ll;

const int maxfn = 100;
const int maxcomm = 20;

pair<int, int> rotate(pair<int, int> p, int rot){
	if(rot == 0){

	} else if(rot == 1){

	} else if(rot == 2){

	} else if(rot == 3){

	}

	return p;
}

int fn;
bool used[maxfn];
vector<int> f[maxfn];
pair<int, int> res[maxfn];
pair<int, int> sum[maxfn];

int sumf(int fn){

}

int resf(int fn){

}

int main() {
	ios::sync_with_stdio(false);

	cin >> fn;

	std::string str;
	for(int i = 0; i < fn; i++){
		cin >> str >> str >> str;

		for(int j = 0; j < maxcomm and str[0] != '}'; j++){
			if(str[0] == 'N'){
				f[i].push_back(0);
			} else if(str[0] == 'L'){
				f[i].push_back(-2);
			} else if(str[0] == 'D'){
				f[i].push_back(-1);
			} else if(str[0] == 'F'){
				int fr = 0;
				for(int k = 1; k < str.length() - 1; k++){
					fr *= 10;
					fr += str[k] - '0';
				}
			}
			cin >> str;
		}
	}

	return 0;
}
