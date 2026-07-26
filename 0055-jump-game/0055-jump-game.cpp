class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int MaxIdx = 0;
        int currMax = 0;

        for(int i = 0; i< n; i++){
            if(i>MaxIdx) return false;
            currMax = i+nums[i];
            MaxIdx = max(currMax, MaxIdx);

            if(MaxIdx >= n) return true;
        }
        return true;
    }
};
