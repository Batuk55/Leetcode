class Solution {
public:
 int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        int nse = 0, pse = 0;

        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                int ele_idx = st.top();
                int ele = heights[ele_idx];  //nse for element at st.top() is at i;
                st.pop();

                nse = i;
                //pse is now at st.top()
                pse = st.empty() ? -1 : st.top();
                int currArea = ele * (nse - pse - 1);
                maxArea = max(maxArea, currArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele = heights[st.top()];
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, ele * (nse - pse - 1));
        }
        
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int TotalMaxArea = 0;
        vector<int> height (m, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j< m; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0; 
            }
            int currArea = largestRectangleArea(height);
            TotalMaxArea = max(TotalMaxArea, currArea);
        }
        return TotalMaxArea;
    }
};