class Solution {
public:
    //8 directions
    int drow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dcol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return -1;

        queue<pair<int, pair<int, int>>> q; //{dist, r, c}
        q.push({1, {0,0}});
        grid[0][0] = 1;

        while(!q.empty()){
            auto IT = q.front();
            int dis = IT.first;
            int r = IT.second.first;
            int c = IT.second.second;
            q.pop();

            if(r == n-1 && c == n-1) return dis;

            for(int i = 0; i< 8; i++){
                int newr = r + drow[i];
                int newc = c + dcol[i];

                if(newr>=0 && newr <n && newc>=0 && newc < n && 
                grid[newr][newc] == 0){
                    q.push({dis+1, {newr, newc}});
                    grid[newr][newc] = 1;
                } 
            }
        }
        
        return -1;
        
    }
};