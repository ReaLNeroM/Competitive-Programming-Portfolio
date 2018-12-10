class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        std::sort(A.begin(), A.end());
        int last = -1;
        
        int res = 0;
        for(int i = 0; i < A.size(); i++){
            if(last >= A[i]){
                res += (last + 1) - A[i];
                last++;
            } else {
                last = A[i];
            }
        }
        
        return res;
    }
};