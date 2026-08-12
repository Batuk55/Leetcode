class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0 ,-1};
    void bfs(int row, int col, vector<vector<char>>& grid){
        int m = grid.size(), n = grid[0].size();
        queue <pair<int ,int>> q;
        q.push({row, col});

        grid[row][col] = '0';

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i< 4; i++){
                int newr = r + drow[i];
                int newc = c + dcol[i];

                if(newr>=0 && newr<m && newc>=0 && newc<n && 
                grid[newr][newc]== '1'){

                    grid[newr][newc] = '0';
                    q.push({newr, newc});

                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid){
        int m = grid.size(), n = grid[0].size();

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    bfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};