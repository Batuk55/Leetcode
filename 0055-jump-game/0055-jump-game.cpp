class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MaxInd = 0;
        int CurrMax = 0;
        for(int i = 0; i<nums.size(); i++){
            CurrMax = i + nums[i];
            if(i > MaxInd) return false;

            MaxInd = max(MaxInd, CurrMax);
            if(MaxInd >=nums.size()) return true;
        }
        return true;
    }
};