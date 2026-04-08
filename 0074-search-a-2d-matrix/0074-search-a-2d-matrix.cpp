class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0, high = m*n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid / n , col = mid % n;

            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }
        return false;
    }
};
// int m = matrix.size();
// int n = matrix[0].size();

// int rowlow = 0, rowhigh = m - 1;
// int collow = 0, colhigh = n - 1;

// while (rowlow <= rowhigh && collow <= colhigh) {
//     int rowmid = rowlow + (rowhigh - rowlow) / 2;
//     int colmid = collow + (colhigh - collow) / 2;

//     if (matrix[rowmid][colmid] == target)
//         return true;
//     if (matrix[rowmid][colmid] > target) {
//         rowhigh = rowmid - 1;
//         colhigh = colmid - 1;
//     } else if (matrix[rowmid][colmid] < target) {
//         rowlow = rowmid + 1;
//         collow = colmid + 1;
//     }
// }
// return false;