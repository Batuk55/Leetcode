class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefixMax(n, height[0]);
        vector<int> suffixMax(n, height[n-1]);

        for(int i = 1; i<n; i++){
            prefixMax[i] = max(height[i], prefixMax[i-1]);
            suffixMax[n-(i+1)] = max(height[n-(i+1)] , suffixMax[n-(i+1)+1]);
        }

        int total = 0;
        for(int i = 0; i< n; i++){
            if(height[i] < prefixMax[i] && height[i] < suffixMax[i]){
                total += min(prefixMax[i], suffixMax[i]) - height[i];
            }
        }
        return total;
    }
};