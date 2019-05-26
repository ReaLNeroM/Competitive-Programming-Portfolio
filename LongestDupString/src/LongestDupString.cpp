<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

=======
>>>>>>> 5ef42a7eb5a2377acf55c1835669f0f220cce5a8
typedef long long ll;

class Solution {
public:
    std::string bestAns = "";
    const ll mod = 101107157131LL;
    const ll base = 257;

    bool good(std::string& s, ll m){
        std::set<ll> ss;

        ll hash = 0LL;
        ll exp = 1LL;
        for(int i = 0; i < m; i++){
        	hash = (hash * base + s[i]) % mod;
        }
<<<<<<< HEAD
        for(int i = 0; i < m; i++){
=======
        for(int i = 0; i < m - 1; i++){
>>>>>>> 5ef42a7eb5a2377acf55c1835669f0f220cce5a8
        	exp = (exp * base) % mod;
        }
        ss.insert(hash);

        for(int i = m; i < s.size(); i++){
        	hash = (hash * base + s[i]) % mod;
<<<<<<< HEAD
        	hash -= exp * s[i - m];
=======
        	hash -= exp * s[0];
>>>>>>> 5ef42a7eb5a2377acf55c1835669f0f220cce5a8
        	hash %= mod;
        	if(hash < 0){
        		hash += (hash + 10LL * mod) % mod;
        	}

        	if(ss.find(hash) != ss.end()){
        		bestAns = s.substr(i - m + 1, m);
        		//get this bish
        		return true;
        	} else {
        		ss.insert(hash);
        	}
        }

        return false;
    }

    string longestDupSubstring(string S) {
        ll l = 1, r = S.size();

        while(l<=r){
            ll mid = (l+r)/2;

            if(good(S, mid)){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return bestAns;

    }
};
<<<<<<< HEAD

int main(){
	Solution x;
	std::cout << x.longestDupSubstring("moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyealllginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmakyjbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqkndujeranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbobxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuctshytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqzeleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrmrbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroqxsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcueyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenecqlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupvsorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfhtaniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvnhysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwtxtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvwnxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptkilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakmmehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxhmlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutqryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcwwpndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjreykqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbgatlsxfhpcidfgzrc");
}
=======
>>>>>>> 5ef42a7eb5a2377acf55c1835669f0f220cce5a8
