class Solution {
public:
    int row_of_max_ele_in_column(vector<vector<int>>& mat, int col, int m) {
        int maxele = INT_MIN;
        int row = 0;
        for (int i = 0; i < m; i++) {
            if (mat[i][col] > maxele) {
                maxele = mat[i][col];
                row = i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = row_of_max_ele_in_column(mat, mid, m);
            //row --> row in which there is maximum element of mid column.

            int leftele = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int rightele = mid + 1 < n ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > leftele && mat[row][mid] > rightele) {
                return {row, mid};
            } else if (mat[row][mid] < leftele)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};