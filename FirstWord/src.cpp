#include <string>
#include <vector>
using namespace std;

class FirstWord{
public:
	vector<int> used;
	int app[26][26];
	int res = 0;
	
	int dfs(string x){
		for(int i = 0; i < 26; i++){
			string y = x + ((char) (i + 'a'));
			y.erase(y.begin());

			if(app[x[1] - 'a'][i]){
				app[x[1] - 'a'][i]--;
				app[i][x[1] - 'a']--;
				dfs(y);
				res++;
				break;
			}
		}
	}

	int bdfs(string x){
		for(int i = 0; i < 26; i++){
			string y = ((char) (i + 'a')) + x;
			y.erase(--y.end());

			if(app[x[0] - 'a'][i]){
				app[x[0] - 'a'][i]--;
				app[i][x[0] - 'a']--;
				bdfs(y);
				res++;
				break;
			}
		}
	}

	int findFirstWord(vector<string> rules){
		used = std::vector<int>(rules.size(), false);

		for(int i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++){
				app[i][j] = 0;
			}
		}
		for(int i = 0; i < rules.size(); i++){
			app[rules[i][0] - 'a'][rules[i][1] - 'a']++;
			app[rules[i][1] - 'a'][rules[i][0] - 'a']++;
		}

		for(int i = 0; i < rules.size(); i++){
			if(app[rules[i][1] - 'a'][rules[i][0] - 'a']){
				app[rules[i][0] - 'a'][rules[i][1] - 'a']--;
				app[rules[i][1] - 'a'][rules[i][0] - 'a']--;
				res += 2;
				dfs(rules[i]);
				bdfs(rules[i]);
			}
		}

		return res;
	}
};
