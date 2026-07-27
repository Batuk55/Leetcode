class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int MaxMul = 0;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                MaxMul = max(MaxMul, (nums[i]-1)*(nums[j]-1));
            }
        }
        return MaxMul;
    }
};