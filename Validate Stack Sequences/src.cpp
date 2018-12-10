class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int trackpos = 0;
        for(int i = 0; i < pushed.size(); i++){
            s.push(pushed[i]);
            while(!s.empty() and s.top() == popped[trackpos]){
                s.pop();
                trackpos++;
            }
        }
        
        return (trackpos == popped.size());
    }
};