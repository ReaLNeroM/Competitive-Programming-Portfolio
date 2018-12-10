class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
    	std::vector<int> adj[stones.size()];
    	for(int i = 0; i < stones.size(); i++){
    		for(int j = i + 1; j < stones.size(); j++){
    			if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]){
    				adj[i].push_back(j);
    				adj[j].push_back(i);
    			}
    		}
    	}

    	std::vector<bool> visited(stones.size(), 0);
    	int res = stones.size();

    	for(int i = 0; i < stones.size(); i++){
    		if(!visited[i]){
    			visited[i] = true;
    			res--;
    			std::queue<int> q;
    			q.push(i);

    			while(!q.empty()){
    				int fr = q.front();
    				q.pop();

    				for(int next : adj[fr]){
    					if(!visited[next]){
    						visited[next] = true;
    						q.push(next);
    					}
    				}
    			}
    		}
    	}

    	return res;
    }
};