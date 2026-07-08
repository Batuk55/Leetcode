class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int> arr, int idx) {
        if (idx == nums.size()) {
            ans.push_back({arr});
            return;
        }
        // include
        arr.push_back(nums[idx]);
        helper(ans, nums, arr, idx + 1);
        arr.pop_back();

        // exclude
        while(idx+1 < nums.size() && nums[idx] == nums[idx+1]) idx++; // to handle duplicates

        helper(ans, nums, arr, idx + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> arr;
        helper(ans, nums, arr, 0);
        return ans;
    }
};