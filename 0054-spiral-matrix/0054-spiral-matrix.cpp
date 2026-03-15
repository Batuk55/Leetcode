class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> arr;
        int top = 0;
        int right = n - 1;
        int left = 0;
        int bottom = m - 1;

        while (left <= right && top <= bottom) {

            int i = left;
            while (i <= right) { // left to right
                arr.push_back(matrix[top][i]);
                i++;
            }
            top++;

            int j = top;
            while (j <= bottom) { // top to bottom
                arr.push_back(matrix[j][right]);
                j++;
            }
            right--;
            if (top <= bottom) {
                int k = right;
                while (k >= left) { // right to left
                    arr.push_back(matrix[bottom][k]);
                    k--;
                }
                bottom--;
            }
            if (right >= left) {
                int l = bottom;
                while (l >= top) { // bottom to up
                    arr.push_back(matrix[l][left]);
                    l--;
                }
                left++;
            }
        }
        return arr;
    }
};