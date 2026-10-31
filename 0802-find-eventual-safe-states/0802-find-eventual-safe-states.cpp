class Solution {
public:
     bool dfs(int start, vector<vector<int>> &graph, vector<int> &visited,  vector<int> &pathVisited, vector<int> &check){
        visited[start] = 1;
        pathVisited[start] = 1;
        check[start] = 0;

        for(auto it: graph[start]){
            if(!visited[it]){
                if(dfs(it, graph, visited, pathVisited, check)){
                    // check[node] = 0;
                    return true;
                }
            }
                //if node has been previously visited
            else if(visited[it] == 1 && pathVisited[it] == 1){
                // check[node] = 0;

                return true; 
            }
        }

        check[start] = 1;
        pathVisited[start] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> visited(N, 0);
        vector<int> pathVisited(N, 0);
        vector<int> check(N, 0);
        vector<int> safenodes;

        for(int i = 0; i < N; i++){
            if(!visited[i]){
                dfs(i, graph, visited, pathVisited, check);
            }
        }
        for(int i = 0; i<N; i++){
            if(check[i] == 1){
                safenodes.push_back(i);
            }
        }
        
        return safenodes;
    }
};