class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        int n = mat.size();

        vector<vector<int>> mat2(n, vector<int>(n));
        int a = 0;
        while (a < 4) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    mat2[i][j] = mat[n - (j + 1)][i];
                }
            }
            if (mat2 == target)
                return true;

            a++;
            mat = mat2; // after every rotation mat changes...
        }

        return false;
    }
};