#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	int n = str.size();

	vector<int> v[26]; // vektor koja za dadena bukva,
					   // dava i kade sto str[i] == v[c] za dadeno c, sortirano opagacki
	for(int i = n - 1; i >= 0; i--){
		v[str[i] - 'A'].push_back(i);
	}

	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < v[str[i] - 'A'].size() and v[str[i] - 'A'][j] > i; j++){
			int e = v[str[i] - 'A'][j]; // krajna bukva

			//|verglanje| = |x| + |y| + |x| + |y|
			//|verglanje| = |x| + |x| + |x| + |x|
			//|verglanje| = 4 * |x|
			//golemina na verglanjeto e deliv so 4
			if((e - i + 1) % 4 == 0){ // da se proveri dali delot [i, e] e so golemina deliva so 4
				int sizep = (e - i + 1) / 4; // golemina na X

				//proveruvame dali dvete XY se isti
				bool passed = true;
				for(int k = 0; k < sizep + sizep and passed; k++){
					if(str[i + k] != str[i + sizep + sizep + k]){
						passed = false;
					}
				}

				//proveruvame dali prviot X i prviot Y se obratni
				for(int k = 0; k < sizep and passed; k++){
					if(str[i + k] != str[i + sizep + sizep - k - 1]){
						passed = false;
					}
				}

				if(passed){
					res = max(res, e - i + 1);

					//ovaa "optimizacija" ja ubrzuva programata dovolno za vremenskite limiti
					//no kontraprimerot pokazuva deka e greska
					break;
				}
			}
		}
	}

	cout << res;
}
