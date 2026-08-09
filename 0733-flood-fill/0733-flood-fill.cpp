class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> visited = image;
        queue<pair<int,int>> q;

        q.push({sr, sc});
        visited[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            int r = curr.first;
            int c = curr.second;

            for(int i = 0; i<4; i++){
                int newr = r + drow[i];
                int newc = c + dcol[i];

                if(newr>=0 && newr <m && newc>=0 && newc < n && 
                visited[newr][newc] != color && image[sr][sc] == image[newr][newc]){
                    q.push({newr, newc});
                    visited[newr][newc] = color;
                }
            }
        }
        
        return visited;  
        
    }
};