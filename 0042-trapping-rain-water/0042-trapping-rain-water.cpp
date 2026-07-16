class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax =0;
        int total = 0;
        int i = 0, j = n-1;

        while(i!=j){
            if(height[i] <= height[j]){
                if(height[i] < leftMax){
                    total += leftMax - height[i];
                }
                else{
                    leftMax = height[i];
                }
                i++;
            }
            else{ //(height[j] < height[i])
                if(height[j] < rightMax){
                    total += rightMax-height[j];
                }
                else{
                    rightMax = height[j];
                }
                j--;
            }
        }
        return total;

        
    }
};