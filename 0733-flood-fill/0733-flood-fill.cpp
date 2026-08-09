class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    void  dfs(vector<vector<int>>& image, int row, int col, int &color, int &startColor){
        image[row][col] = color;
        
        for(int i = 0; i<4; i++){
            int newr = row + drow[i];
            int newc = col + dcol[i];

            if(newr>=0 && newr < image.size() && newc>=0 && newc < image[0].size() && 
            image[newr][newc] != color &&  image[newr][newc] == startColor){ //image[sr][sc] == image[newr][newc]
                // q.push({newr, newc});
                dfs(image, newr, newc, color, startColor);                
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // vector<vector<int>> ans = image;
        int startColor = image[sr][sc];

        dfs(image, sr, sc, color, startColor);
        // return ans;
        return image;
        
    }
};