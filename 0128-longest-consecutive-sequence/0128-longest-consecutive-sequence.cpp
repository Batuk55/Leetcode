class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        
        int max_count = 1;
        int count = 1;
        int i = 0;
        while(i<nums.size()-1){
            if(nums[i] == nums[i+1]){
                i++;
                continue;
            }
            if(nums[i]+1 == nums[i+1]) count++;
            else count = 1;
            max_count = max(max_count, count);
            i++;
        }
        return max_count;
        
    }
};