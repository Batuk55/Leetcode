class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        int cnt = 0;

        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        
        for(int i = 0; i<V; i++){// reversing arrow direction
            for(auto it: graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){// terminal node
                // ans.push_back(i);
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){
                //node is in ans so remove it from indegree.
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
                
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};