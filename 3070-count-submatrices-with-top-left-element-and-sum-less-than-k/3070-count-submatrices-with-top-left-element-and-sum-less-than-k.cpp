/*class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // vector<int> mpp;
        int count = 0;
        int sum = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i++) { // row
            if (sum < k) {
                // continue;
                // int a = 0;
                // while (a < i) {
                //     mpp.push_back(grid[a++][0]);
                // }
                count++;
            }
            sum += grid[i][0];
        }
        for (int j = 0; j < m; j++) {
            if (sum2 < k) {
                // continue;
                // int b = 0;
                // while (b < j) {
                //     mpp.push_back(grid[0][b++]);
                // }
                count++;
            }
            sum2 += grid[0][j];
        }
        // return mpp.size();
        return count;
    }
};
*/
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i > 0) grid[i][j] += grid[i-1][j];
                if (j > 0) grid[i][j] += grid[i][j-1];
                if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];

                if (grid[i][j] <= k) count++;
            }
        }

        return count;
    }
};