class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        for(int i = 0; i < 8; i++){
            int n = arr1.size();
            vector<int> v(n);
            for(int j = 0; j < n; j++){
                v[j] = 0;
                if(i & 4){
                    v[j] -= arr1[j];
                } else {
                    v[j] += arr1[j];
                }
                if(i & 2){
                    v[j] -= arr2[j];
                } else {
                    v[j] += arr2[j];
                }
                if(i & 1){
                    v[j] -= j;
                } else {
                    v[j] += j;
                }
            }
            std::sort(v.begin(), v.end());
            res = std::max(res, v[n - 1] - v[0]);
        }
        return res;
    }
};