class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // Your code goes here
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> nums = matrix;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    int k = 0;
                    while (k < n) { // i is fixed here, so entire row becoming 0.
                        nums[i][k] = 0;
                        k++;
                    }
                    int l =0;
                    while (l < m) { // j is fixed here, so entire column becoming 0.
                        nums[l][j] = 0;
                        l++;
                    }
                }
            }
        }
        matrix = nums;
    }
};