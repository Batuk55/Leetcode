class Solution {
public:
    bool check(int start, int V, vector<vector<int>> &adj, vector<int> &visited){

        queue<int> q;
        // q.push(start);
        // visited[start]++;
        for(int i = 0; i< V; i++){
            if(visited[i] == 0){
                q.push(i);
            }
        }

        // vector<int> ans;
        int cnt = 0;

        while(!q.empty()){
            int curr = q.front();
            // int parent = q.front().second;
            q.pop();
            cnt++;

            // ans.push_back(curr);
            for(auto it : adj[curr]){

                visited[it]--;
               
                if(visited[it] == 0){
                    q.push(it);
                    // visited[it] = 1;
                }
                // else if(parent != it){
                //     return false;
                // }
            }
        }
        return cnt == V;      
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        
        vector<int> visited(V, 0);
        vector<vector<int>> adj(V);

        for(auto it: prerequisites){
            int course = it[0];
            int required = it[1];

            adj[required].push_back(course);
            visited[course]++;
        }

        //if cycle present --> not possible

        // for(int i = 0; i<V; i++){
        //     if(!visited[i]){
                // if(check(i, V, adj, visited)) return true;
                if(check(0, V, adj, visited)) return true;
        //     }
        // }
        return false;
        
    }
};