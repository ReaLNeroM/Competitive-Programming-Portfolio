class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        std::sort(tokens.begin(), tokens.end());
        
        int res = 0;
        
        int cP = P;
        
        for(int spli = 0; spli <= (int) tokens.size(); spli++){
            int l = 0, r = (int) tokens.size() - 1;
            
            int points = 0;
            
            P = cP;
            while(l <= r){
                if(P >= tokens[l] and l <= spli){
                    P -= tokens[l];
                    l++;
                    points++;
                } else if(points > 0 and r > spli){
                    P += tokens[r];
                    r--;
                    points--;
                } else {
                    break;
                }
                res = std::max(res, points);
            }
        }
        
        return res;
    }
};